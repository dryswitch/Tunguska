/* Tunguska, ternary virtual machine
 *
 * Copyright (C) 2007,2008 Viktor Lofgren
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


%{
#define YYERROR_VERBOSE
#include <stdio.h>
#include <stdlib.h>
#include <FlexLexer.h>

#include "assembler.h"
#include "error.h"

extern char* filename;
int yyerror(const char* err) { 
	throw new error(WHERE, std::string(err));
}
int yywrap() { return 1; }
extern int yylex();

%}
%union {
	char* sval;
	int ival;
}
%token NONTRIP NONSEXT DECIMAL ORG XREG YREG ACCUMULATOR EQU DT DW REST _INC
%token ENDLINE ':' '(' ')' FLOATVAL
%token IDENTIFIER COMMENT ASMDEBUG NEWLINE ',' HERE STRING '#'

%nonassoc LOW HIGH
%token '{' '}'
%left  '+' '-'
%left  '*' '/'
%%
commands: //
	|
	commands command 
	;
command:  command_line newline
       	| command_line comment newline
	| comment newline
       	| def_label command_line newline
       	| def_label command_line comment newline
	| def_label comment newline
	| def_label newline
	| inc
	| newline
	;
command_line: opcode 
	| set_origin
	| equ
	| rest
	| dt
	| dw
	| asmdebug
	;
newline: NEWLINE { assembler::instance()->inc_line(); } ;
asmdebug: ASMDEBUG num { printf("@ASMDEBUG(%d)\n", $<ival>2); } ;
comment: COMMENT {};
inc: 	_INC STRING { assembler::instance()->inc($<sval>2); }
def_label: IDENTIFIER ':' { assembler::instance()->ldef($<sval>1); } ;
equ:   EQU IDENTIFIER address { assembler::instance()->equ($<sval>2, $<ival>3); }
   	| IDENTIFIER EQU address { assembler::instance()->equ($<sval>1, $<ival>3); } ;
rest:   REST num {{int i = 0; for(i = 0; i < $<ival>2; i++) assembler::instance()->dt(0); }}
	| REST num ',' num {{ int i = 0; for(i = 0; i < $<ival>2; i++) assembler::instance()->dt($<ival>4); }}
	;
dt:	DT dtlist;
dtlist:  num{ assembler::instance()->dt($<ival>1); }
      	| STRING { assembler::instance()->dtstring($<sval>1); }
      	| dtlist ',' num { assembler::instance()->dt($<ival>3); }
      	| dtlist ',' STRING { assembler::instance()->dtstring($<sval>3); }
	;
dw:	DW dwlist;
dwlist:  num{ assembler::instance()->dw($<ival>1); }
      	| dwlist ',' num { assembler::instance()->dw($<ival>3); }
	;
	
set_origin: ORG num { assembler::instance()->org($<ival>2); } ;
opcode:
      	IDENTIFIER { assembler::instance()->addop($<sval>1, OP_IMPLICIT, 0); }
	| IDENTIFIER ACCUMULATOR { assembler::instance()->addop($<sval>1, OP_ACC, 0); }
	| IDENTIFIER XY { assembler::instance()->addop($<sval>1, OP_XY, 0); }
	| IDENTIFIER directnum { assembler::instance()->addop($<sval>1, OP_IMMEDIATE, $<ival>2); }
	| IDENTIFIER address { assembler::instance()->addop($<sval>1, OP_ABSOLUTE, $<ival>2); }
	| IDENTIFIER addressX { assembler::instance()->addop($<sval>1, OP_ABSOLUTE_X, $<ival>2); }
	| IDENTIFIER addressY { assembler::instance()->addop($<sval>1, OP_ABSOLUTE_Y, $<ival>2); }
	| IDENTIFIER indirect { assembler::instance()->addop($<sval>1, OP_INDIRECT, $<ival>2); }
	| IDENTIFIER indirectX { assembler::instance()->addop($<sval>1, OP_INDIRECT_X, $<ival>2); }
	| IDENTIFIER indirectY { assembler::instance()->addop($<sval>1, OP_INDIRECT_Y, $<ival>2); }
	;
num: 
     	DECIMAL   { $<ival>$ = $<ival>1; }
	| NONTRIP { $<ival>$ = nontriplet($<sval>1); }
	| NONSEXT { $<ival>$ = nonsextet($<sval>1); }
	| FLOATVAL { $<ival>$ = floatval($<sval>1); }
	| '-' num { $<ival>$ = - $<ival>2; }
	| num '+' num { $<ival>$ = $<ival>1 + $<ival>3; }
	| num '-' num { $<ival>$ = $<ival>1 - $<ival>3; }
	| num '*' num { $<ival>$ = $<ival>1 * $<ival>3; }
	| num '/' num { $<ival>$ = $<ival>1 / $<ival>3; }
	| '{' num '}' { $<ival>$ = $<ival>2; }
	| LOW num { $<ival>$ = lowtryte($<ival>2); } 
	| HIGH num{ $<ival>$ = hightryte($<ival>2); } 
	| IDENTIFIER { $<ival>$ = assembler::instance()->label_eval($<sval>1); }
	| HERE { $<ival>$ = assembler::instance()->get_pc(); } 
	;
directnum: '#' num { $<ival>$ = $<ival>2; } ;
address: num { $<ival>$ = $<ival>1; } ;       
addressX: num ',' XREG { $<ival>$ = $<ival>1; } ;
addressY: num ',' YREG { $<ival>$ = $<ival>1; } ;
indirect: '(' address ')' { $<ival>$ = $<ival>2; }
indirectX: '(' addressX ')' { $<ival>$ = $<ival>2; }
indirectY: '(' address ')' ',' YREG { $<ival>$ = $<ival>2; }
XY: XREG ',' YREG {}
