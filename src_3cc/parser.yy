/*  3cc - Ternary C Compiler for Tunguska
 *  Copyright (C) 2008  Viktor Lofgren
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

%{
#define YYERROR_VERBOSE
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <FlexLexer.h>
#include "type.h"
#include "compiler.h"
#include "variable.h"
#include "expression.h"
#include "bivalent.h"
#include "memory.h"
#include "conditional.h"
#include <stdint.h> // added by ahmed on 4-feb-2024
class type;
class expression;
class sllist;

extern yyFlexLexer* lexer;

int yyerror(const char* err) { throw new std::runtime_error(err); }
void newline() { compiler::instance()->advance_line(); }

int yywrap() { return 1; }
extern int yylex();

int force_lazy = 0;

/* Automagically figure out whether to use assignment or ptr_assignment 
 *
 * FIXME: This is terribly deprecated, and useless.
 */
expression* auto_assign(expression* target, expression* source) {
	lvalue* l = dynamic_cast<lvalue*>(target);
	if(!l) throw new runtime_error("Assigning non-lvalue");
	return new assigner(l, source);
}	

type* matrix_type(type* t, sllist* dimensions) {
	while(dimensions) {
		// modified by ahmed on 4-feb-2024
		//t = new t_array(t, (int)dimensions->data);
		t = new t_array(t, (intptr_t)dimensions->data);
		dimensions=dimensions->next;
	}
	return t;
}

type* matrix_type_lazy(type* t, sllist* dimensions, sllist* initializer) {
	if(dimensions) t = matrix_type(t, dimensions);

	int lazy_dim = 0;
	while(initializer) {
		lazy_dim++;
		initializer = initializer->next;
	}
	return new t_array(t, lazy_dim);
}

%}


%union {
	type* tval;
	expression* exprval;
	lvalue* lval;
	variable* varval;
	char* strval;
	sllist* listval;
	intptr_t ival; //int ival;  // modified by ahmed on 4-feb-2024
}

%expect 1 // Expect one error (loose if)

%token TYPE DECIMAL IDENTIFIER CONTINUE BREAK '{' '}' VOLATILE EXTERN ISR TYPEDEBUG REENTRANT
%nonassoc RETURN
%left	SPTEST
%right '=' '?' ADDASSIGN SUBASSIGN MULASSIGN ANDASSIGN XORASSIGN ORASSIGN
%left   LOG_OR LOG_AND
%left   '<' '>' GE LE NE EQ
%left	'+' '-'
%left   '%' '*' '/'
%left   '~' '&' '|' '^' PRM TSH COMM_OP
%left	INVERT

%nonassoc DEREF_IDENT
%left INDEX

%nonassoc ';' ':' '(' ')' INC DEC ',' '[' ']' '\n' '.'
%nonassoc IF ELSE STATIC WHILE STRING FOR
%nonassoc ASM PRAGMA SIZEOF '#' STRUCT PTRFIELD


%%

codelines: codeline | codelines codeline;
codeline:
	vardecl_glob
	| fundecl_glob ';'
	| struct_declaration ';'
	| fundef 
	| '#' metacommand ; 
	| asm;
	
	
metacommand: 
	PRAGMA IDENTIFIER DECIMAL '\n' { compiler::instance()->pragma($<strval>2, $<ival>3); }
	| PRAGMA IDENTIFIER '\n' { compiler::instance()->pragma($<strval>2); }
	| DECIMAL '\n' { compiler::instance()->set_effective_location(NULL, $<ival>1); }
	| DECIMAL STRING '\n' { compiler::instance()->set_effective_location($<strval>2, $<ival>1); }
	| DECIMAL STRING DECIMAL '\n' { compiler::instance()->set_effective_location($<strval>2, $<ival>1); }
	;

statement: ';' | expression ';' 
			{
				if($<exprval>1 != NULL) {  
					expression* p = new cleaner($<exprval>1);
					p->autoeval();
					delete p;
					compiler::instance()->printf("\n");
				} else { printf("Null expression"); }
			};
		| jump_statement
		| conditional_statement
		| scope
		| asm;

jump_statement: CONTINUE ';' { cond_mgr::cont_cond(); }
		| BREAK ';' { cond_mgr::brk_cond(); }
		| RETURN ';' { function::get_current()->do_return(); }
		| RETURN expression ';' { function::get_current()->do_return($<exprval>2); };
		| TYPEDEBUG expression ';' { $<exprval>2->typ()->id(); puts(""); }
		;
		
conditional_statement: if_cnd | while_cnd; | for_cnd;

asm: ASM '(' asm_instruction ')' ';'
asm_instruction: string  { compiler::instance()->printf("\t\t%s\n", $<strval>1); } 
		| asm_instruction ',' string { compiler::instance()->printf("\t\t%s\n", $<strval>3); }

statement_block: | 
	statements;

statements: statement | statements statement;

/* ******************************************************************* *
 * Miscellaneous                                                       *
 * ******************************************************************* */

string: string STRING 
	{ char* s = (char*) malloc(strlen($<strval>1) + strlen($<strval>2)+1); 
  	  sprintf(s, "%s%s", $<strval>1, $<strval>2);
	  $<strval>$ = s; }
	| STRING { $<strval>$ = $<strval>1; };

/* ******************************************************************* *
 * Conditionals                                                        *
 * ******************************************************************* */

scope:
	'{' vardecl_locals { cond_mgr::add_scope();
			     function::get_current()->add_scope($<listval>2); } 
	statement_block '}' { cond_mgr::end_scope();
			     function::get_current()->end_scope(); };

if_cnd_begin:	
	IF '(' expression ')' {
			conditional_* c = new if_cnd($<exprval>3);
			cond_mgr::init_cond(c);
			} statement;
if_cnd:
	if_cnd_begin ELSE { cond_mgr::intermediate_cond(); } statement { cond_mgr::dispose_cond(); }
	| if_cnd_begin { cond_mgr::intermediate_cond(); cond_mgr::dispose_cond(); };

while_cnd: WHILE '(' expression ')' {
				conditional_* c = new while_cnd($<exprval>3);
				cond_mgr::init_cond(c); } 
			statement 
			{ 	cond_mgr::dispose_cond(); 	}

expr_or_null: expression { $<exprval>$ = $<exprval>1; }
		   | { $<exprval>$ = NULL; } ;
for_cnd: FOR '(' expr_or_null ';' expr_or_null ';' expr_or_null ')' {
				 conditional_* c = new for_cnd($<exprval>3, 
						$<exprval>5, $<exprval>7);
				cond_mgr::init_cond(c); } 
			statement
			{ 	cond_mgr::dispose_cond(); 	}
		
			


/* ******************************************************************* *
 * Function definitions and declarations                               *
 * ******************************************************************* */

fundef: 
	Type IDENTIFIER '(' ')' '{' vardecl_locals 
		   { 
			function_prototype fp($<tval>1, NULL);
		     	compiler::instance()->decl_fun($<strval>2, fp); 
	  	      	function::init_definition(fp, $<strval>2, $<tval>1, NULL, $<listval>6); 
		    }
			 statement_block 
		'}' { function::finish_definition(); }
	| Type IDENTIFIER '(' fundef_args ')' '{' vardecl_locals
		 { 
			function_prototype fp($<tval>1, $<listval>4);
			compiler::instance()->decl_fun($<strval>2, fp); 
		      	function::init_definition(fp, $<strval>2, $<tval>1, $<listval>4, $<listval>7); 
		    }
			 statement_block 
		'}' { function::finish_definition(); };

fundef_args:
	Type IDENTIFIER { $<listval>$ = new sllist((void*)$<tval>1, (void*)$<strval>2); }
	| Type IDENTIFIER '[' ']' { $<listval>$ = new sllist(new t_ptr($<tval>1), (void*)$<strval>2); }
	| Type IDENTIFIER '[' ']' array_dimensions { $<listval>$ = new sllist(new t_ptr(matrix_type($<tval>1, $<listval>5)), (void*)$<strval>2); }
	| fundef_args ',' Type IDENTIFIER { $<listval>$ = new sllist($<listval>1, $<tval>3, $<strval>4); }
	| fundef_args ',' Type IDENTIFIER '[' ']' { $<listval>$ = new sllist(new t_ptr($<tval>3), (void*)$<strval>4); }
	| fundef_args ',' Type IDENTIFIER '[' ']' array_dimensions { $<listval>$ = new sllist(new t_ptr(matrix_type($<tval>3, $<listval>7)), (void*)$<strval>4); }

fundecl_glob_: /* Function declaration */
	Type IDENTIFIER '(' ')' { 
		function_prototype fp($<tval>1, NULL);
		compiler::instance()->decl_fun($<strval>2, fp); 
		$<strval>$ = $<strval>2;
	}
	| Type IDENTIFIER '(' fundef_args ')' { 
		function_prototype fp($<tval>1, $<listval>4);
		compiler::instance()->decl_fun($<strval>2, fp); 
		$<strval>$ = $<strval>2;
	}
	;

fundecl_glob:
	fundecl_glob_
	| fundecl_glob '=' decimal { compiler::instance()->printf("%s\t@EQU\t%d\n", $<strval>1, $<ival>3); }
	| fundecl_glob '=' IDENTIFIER { 
		compiler::instance()->printf("%s\t@EQU\t%d\n", $<strval>1, $<strval>3); 
	}
	;

/* Local variable declarations */
struct_or_array_initializer: 
			expression { $<listval>$ = new sllist($<varval>1); } 
			| '{' struct_or_array_initializer '}' 
			   { $<listval>$ = new sllist(NULL, NULL, $<listval>2); } 
			| struct_or_array_initializer ',' expression 
			   {  $<listval>$ = new sllist($<listval>1, $<varval>3);  } 
			| struct_or_array_initializer ',' '{' struct_or_array_initializer '}' 
			   { $<listval>$ = new sllist($<listval>1, NULL, $<varval>4); }

array_dimensions:
	'[' decimal ']' { $<listval>$ = new sllist((void*)($<ival>2)); }
	| array_dimensions '[' decimal ']'
			{ $<listval>$ = new sllist($<listval>1, (void*)($<ival>3)); }

/* Local variable declarations */
vardecl_local: 
	/* Dynamic local variables */
	Type IDENTIFIER ';' { $<varval>$ = new dynamic_variable($<strval>2, $<tval>1); }
	| Type IDENTIFIER '=' expression ';' { $<varval>$ = new dynamic_variable($<strval>2, $<tval>1, $<exprval>4); }
	| Type IDENTIFIER '['']' '=' '{' struct_or_array_initializer '}' ';' 
			{
				type* t = matrix_type_lazy($<tval>1, NULL, $<listval>7);
				$<varval>$ = new dynamic_variable($<strval>2, t, new composite_initializer(t, $<listval>7));; 
			}
	| Type IDENTIFIER array_dimensions ';' { $<varval>$ = new dynamic_variable($<strval>2, matrix_type($<tval>1, $<listval>3)); }
	| Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';' {
		type* t = matrix_type($<tval>1, $<listval>3);
		$<varval>$ = new dynamic_variable($<strval>2, t, new composite_initializer(t , $<listval>6)); 
	}

	| Type IDENTIFIER '[' ']' array_dimensions '=' '{' struct_or_array_initializer '}' ';' {
		type* t = matrix_type_lazy($<tval>1, $<listval>5, $<listval>8);
		$<varval>$ = new dynamic_variable($<strval>2, t, new composite_initializer(t, $<listval>8)); 
	}
	| Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';' { $<varval>$ = new dynamic_variable($<strval>2, $<tval>1, new composite_initializer($<tval>1, $<listval>5)); }

	/* Static local varaibles */
	| STATIC Type IDENTIFIER ';' { $<varval>$ = new static_variable($<strval>3, $<tval>2); }
	| STATIC Type IDENTIFIER '=' expression ';' { $<varval>$ = new static_variable($<strval>3, $<tval>2, $<exprval>5); }
	| STATIC Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';' 
		{ $<varval>$ = new static_variable($<strval>3, $<tval>2, new composite_initializer($<tval>2, $<listval>6)); }
	| STATIC Type IDENTIFIER array_dimensions ';' { $<varval>$ = new static_variable($<strval>3, matrix_type($<tval>2, $<listval>4)); } 
	| STATIC Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';' {
		type* t = matrix_type($<tval>2, $<listval>4);
		$<varval>$ = new static_variable($<strval>3, t, new composite_initializer(t , $<listval>7)); 
	}
	| STATIC Type IDENTIFIER '[' ']' array_dimensions '=' '{' struct_or_array_initializer '}' ';' {
		type* t = matrix_type_lazy($<tval>2, $<listval>6, $<listval>9);
		$<varval>$ = new static_variable($<strval>3, t, new composite_initializer(t , $<listval>9)); 
	}
	| STATIC Type IDENTIFIER '[' ']' '=' '{' struct_or_array_initializer '}' ';' {
		type* t = matrix_type_lazy($<tval>2, NULL, $<listval>8);
		$<varval>$ = new static_variable($<strval>3, t, new composite_initializer(t , $<listval>8)); 
	}

	;
vardecl_local_list:
	vardecl_local { $<listval>$ = new sllist($<varval>1); }  | 
	vardecl_local_list vardecl_local { $<listval>$ = new sllist($<listval>1, $<varval>2); };
vardecl_locals: { $<listval>$ = NULL; }
	| vardecl_local_list { $<listval>$ = $<listval>1; }

vardecl_glob: /* Global variable declaration */
	Type IDENTIFIER ';' { 
		variable* v = new static_variable($<strval>2, $<tval>1);
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define($<strval>2);
		} 
	| Type IDENTIFIER '=' expression ';' { 
		variable* v = new static_variable($<strval>2, $<tval>1, $<exprval>4);
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define($<strval>2);
		} 
	| Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';' { 
		variable* v = new static_variable($<strval>2, $<tval>1, new composite_initializer($<tval>1, $<listval>5));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define($<strval>2);
		} 
	| Type IDENTIFIER array_dimensions ';' { 
		variable* v = new static_variable($<strval>2, matrix_type($<tval>1, $<listval>3)); 
		variable_set::glob_instance()->add_var(v);
		v->get_initial()->define($<strval>2);
	}
	| Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';' { 
		type* t = matrix_type($<tval>1, $<listval>3);
		variable* v = new static_variable($<strval>2, t, new composite_initializer(t, $<listval>6));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define($<strval>2);
		} 
	| EXTERN Type IDENTIFIER ';' {
		variable* v = new static_variable($<strval>3, $<tval>2);
		v->set_extern(true);
		variable_set::glob_instance()->add_var(v); 
	}
	| EXTERN Type IDENTIFIER array_dimensions ';' { 
		variable* v = new static_variable($<strval>3, matrix_type($<tval>2, $<listval>4)); 
		v->set_extern(true);
		variable_set::glob_instance()->add_var(v);
	}


/* ******************************************************************* *
 * Datatypes                                                           *
 * ******************************************************************* */
Type:
	TYPE { $<tval>$ = $<tval>1; }
	| struct { $<tval>$ = $<tval>1; }
	| Type '[' decimal ']' { $<tval>$ = new t_array($<tval>1, $<ival>3); }
	| Type '*' { $<tval>$ = new t_ptr($<tval>1); }
	;

	
struct:
	STRUCT '{' struct_fields '}' { $<tval>$ = new t_struct($<listval>3); }
	| STRUCT IDENTIFIER { $<tval>$ = compiler::instance()->struct_ref($<strval>2); }
struct_fields:
	Type IDENTIFIER ';' { $<listval>$ = new sllist($<strval>2, $<tval>1); }
	| Type IDENTIFIER array_dimensions ';' { $<listval>$ = new sllist($<strval>2, matrix_type($<tval>1, $<listval>3)); }
	| struct_fields Type IDENTIFIER ';' { $<listval>$ = new sllist($<listval>1, $<strval>3, $<tval>2); }
	| struct_fields Type IDENTIFIER array_dimensions ';' { $<listval>$ = new sllist($<listval>1, $<strval>3, matrix_type($<tval>2, $<listval>4)); }
struct_declaration:
	STRUCT IDENTIFIER '{' struct_fields '}' { compiler::instance()->decl_struct($<strval>2, new t_struct($<listval>4)); }


/* ******************************************************************* *
 * Expressions							       *
 * ******************************************************************* */

funcall_arg: expression { $<listval>$ = new sllist($<exprval>1); }
	| funcall_arg ',' expression { $<listval>$ = new sllist($<listval>1, $<exprval>3); }

/*
array: '(' Type ')' '[' DECIMAL ']' {
	if($<tval>2->size() == 1) {
		memory_node* n = new array6_node($<ival>5);
		$<exprval>$ = compiler::instance()->get_mmgr()->add(n);
	} else {
		memory_node* n = new array12_node($<ival>5);
		$<exprval>$ = compiler::instance()->get_mmgr()->add(n);
	}
}*/

decimal: 
	DECIMAL { $<ival>$ = $<ival>1; }
	| SIZEOF '(' Type ')' { $<ival>$ = $<tval>3->size(); }
	| SIZEOF '(' expression ')' { $<ival>$ = $<exprval>3->typ()->size(); }
	;

expression: 
	/* Plain old decimal */
	decimal { $<exprval>$ = new constant($<ival>1); }
	| string { memory_node* n = new string_node($<strval>1);
		  $<exprval>$ = compiler::instance()->get_mmgr()->add(n);
		} 
	| SPTEST expression { $<exprval>$ = new sp_test($<exprval>2); }
	| evaluation { $<exprval>$ = $<exprval>1; }
	| assignment { $<exprval>$ = $<exprval>1; }

	| IDENTIFIER '(' ')' { $<exprval>$ = new function_call($<strval>1, compiler::instance()->fun_ref($<strval>1), NULL); }
	| IDENTIFIER '(' funcall_arg ')' { $<exprval>$ = new function_call($<strval>1, 
							compiler::instance()->fun_ref($<strval>1), $<listval>3); }

	| '(' Type ')' expression { $<exprval>$ = new word_caster($<exprval>4, $<tval>2); } 

	/* Negation */
	| '-' expression %prec INVERT { $<exprval>$ = new inverter($<exprval>2); }
	| '+' expression %prec INVERT { $<exprval>$ = $<exprval>2; } // It's in ANSI, and it's easy to implement

//	/* Sign (NOT NEGATION/INVERSION) */
	| '~' expression { $<exprval>$ = new sign($<exprval>2); }


	/* Logical operations */
	| expression '&' expression { $<exprval>$ = new ander($<exprval>1, $<exprval>3); }
	| expression '|' expression { $<exprval>$ = new orer($<exprval>1, $<exprval>3); }
	| expression '^' expression { $<exprval>$ = new xorer($<exprval>1, $<exprval>3); }
	| expression PRM expression { $<exprval>$ = new prm($<exprval>1, $<exprval>3); }
	| expression TSH expression { $<exprval>$ = new tsh($<exprval>1, $<exprval>3); }

	/* Basic arithmetic */
	| expression '+' expression { $<exprval>$ = new adder($<exprval>1, $<exprval>3); }
	| expression '-' expression { $<exprval>$ = new adder($<exprval>1, new inverter($<exprval>3)); }
	| expression '*' expression { $<exprval>$ = new mul($<exprval>1, $<exprval>3); }
	| expression '/' expression { $<exprval>$ = new divider($<exprval>1, $<exprval>3); }
	| expression '%' expression { $<exprval>$ = new modulo($<exprval>1, $<exprval>3); }

	/* Comparisons */
	| expression LOG_AND expression { $<exprval>$ = new logical_ander($<exprval>1, $<exprval>3); }
	| expression LOG_OR expression { $<exprval>$ = new logical_orer($<exprval>1, $<exprval>3); }
	| expression '<' '<' decimal '>' '>' expression %prec COMM_OP { $<exprval>$ = new comm_op($<ival>4, $<exprval>1, $<exprval>7); }
	| expression '>' expression { $<exprval>$ = new greater_than($<exprval>1, $<exprval>3); }
	| expression '<' expression { $<exprval>$ = new less_than($<exprval>1, $<exprval>3); }
	| expression GE expression { $<exprval>$ = new greater_or_equal($<exprval>1, $<exprval>3); }
	| expression LE expression { $<exprval>$ = new less_or_equal($<exprval>1, $<exprval>3); }
	| expression NE expression { $<exprval>$ = new differs($<exprval>1, $<exprval>3); }
	| expression EQ expression { $<exprval>$ = new equals($<exprval>1, $<exprval>3); }

	/* Ternary, quaternary operators * /
	| expression '?' expression ':' expression { /* STUB * / }
	| expression '?' expression ':' expression ':' expression { /*STUB * / }
	*/

	/* Order override */
	| '(' expression ')' { $<exprval>$ = $<exprval>2; }
	;

/*  Expressions pertaining to getting the contents out of some variable
 *
 *
 *
 */

evaluation: 
	/* Variable */
	IDENTIFIER { 
		if(!force_lazy) {
			try {
				$<exprval>$ = function::get_current()->get_symbol($<strval>1);
			} catch (std::exception* e) {
				delete e;
				$<exprval>$ = new lazy_lvalue($<strval>1);
			}
		} else {
			$<exprval>$ = new lazy_lvalue($<strval>1);
		}
	}
	| expression '[' expression ']' %prec INDEX { 
		if(dynamic_cast<const t_array*>($<exprval>1->typ())) {
			$<exprval>$ = array_index($<exprval>1, $<exprval>3);
		} else if($<exprval>1->typ()->can_deref()) {
			$<exprval>$ = ptr_index($<exprval>1, $<exprval>3);
		} else throw new runtime_error("Indexing non-indexable type");
		}
	| '&' expression %prec DEREF_IDENT { 
		lvalue* l = dynamic_cast<lvalue*>($<exprval>2);

		if(!l) throw new runtime_error("Bad dereference");
		$<exprval>$ = l->refer();
	}
	| expression PTRFIELD IDENTIFIER {
		$<exprval>$ = struct_ptr_field($<exprval>1, $<strval>3);
	}
	| expression '.' IDENTIFIER {
		lvalue* lv = dynamic_cast<lvalue*>($<exprval>1);
		if(!lv) throw new runtime_error("Bad lvalue");
		$<exprval>$ = lv->struct_field($<strval>3);
	}
	| '*' expression { $<exprval>$ = new dereference($<exprval>2); }
	;


/*  Expressions pertaining to modifying the contents of some variable
 *
 *
 *
 */
assignment:
	expression '=' expression { 
		$<exprval>$ = new assigner($<exprval>1, $<exprval>3); 
	}

	/* XXX: This is really ugly, and completely kills the point with
	 * assigning operators */
	| expression ADDASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new adder($<exprval>1, $<exprval>3)); }
	| expression SUBASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new adder($<exprval>1, new inverter($<exprval>3))); }
	| expression MULASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new mul($<exprval>1, $<exprval>3)); }
	| expression ANDASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new ander($<exprval>1, $<exprval>3)); }
	| expression XORASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new orer($<exprval>1, $<exprval>3)); }
	| expression ORASSIGN expression { $<exprval>$ = auto_assign($<exprval>1, new xorer($<exprval>1, $<exprval>3)); }

	| INC expression { $<exprval>$ = new pre_increment($<exprval>2); } 
	| expression INC { $<exprval>$ = new post_increment($<exprval>1); } 
	| DEC expression { $<exprval>$ = new pre_decrement($<exprval>2); } 
	| expression DEC { $<exprval>$ = new post_decrement($<exprval>1); } 


