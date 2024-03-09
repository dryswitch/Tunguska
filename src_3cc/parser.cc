/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "parser.yy"

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


#line 132 "parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE = 258,                    /* TYPE  */
    DECIMAL = 259,                 /* DECIMAL  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    CONTINUE = 261,                /* CONTINUE  */
    BREAK = 262,                   /* BREAK  */
    VOLATILE = 263,                /* VOLATILE  */
    EXTERN = 264,                  /* EXTERN  */
    ISR = 265,                     /* ISR  */
    TYPEDEBUG = 266,               /* TYPEDEBUG  */
    REENTRANT = 267,               /* REENTRANT  */
    RETURN = 268,                  /* RETURN  */
    SPTEST = 269,                  /* SPTEST  */
    ADDASSIGN = 270,               /* ADDASSIGN  */
    SUBASSIGN = 271,               /* SUBASSIGN  */
    MULASSIGN = 272,               /* MULASSIGN  */
    ANDASSIGN = 273,               /* ANDASSIGN  */
    XORASSIGN = 274,               /* XORASSIGN  */
    ORASSIGN = 275,                /* ORASSIGN  */
    LOG_OR = 276,                  /* LOG_OR  */
    LOG_AND = 277,                 /* LOG_AND  */
    GE = 278,                      /* GE  */
    LE = 279,                      /* LE  */
    NE = 280,                      /* NE  */
    EQ = 281,                      /* EQ  */
    PRM = 282,                     /* PRM  */
    TSH = 283,                     /* TSH  */
    COMM_OP = 284,                 /* COMM_OP  */
    INVERT = 285,                  /* INVERT  */
    DEREF_IDENT = 286,             /* DEREF_IDENT  */
    INDEX = 287,                   /* INDEX  */
    INC = 288,                     /* INC  */
    DEC = 289,                     /* DEC  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    STATIC = 292,                  /* STATIC  */
    WHILE = 293,                   /* WHILE  */
    STRING = 294,                  /* STRING  */
    FOR = 295,                     /* FOR  */
    ASM = 296,                     /* ASM  */
    PRAGMA = 297,                  /* PRAGMA  */
    SIZEOF = 298,                  /* SIZEOF  */
    STRUCT = 299,                  /* STRUCT  */
    PTRFIELD = 300                 /* PTRFIELD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TYPE 258
#define DECIMAL 259
#define IDENTIFIER 260
#define CONTINUE 261
#define BREAK 262
#define VOLATILE 263
#define EXTERN 264
#define ISR 265
#define TYPEDEBUG 266
#define REENTRANT 267
#define RETURN 268
#define SPTEST 269
#define ADDASSIGN 270
#define SUBASSIGN 271
#define MULASSIGN 272
#define ANDASSIGN 273
#define XORASSIGN 274
#define ORASSIGN 275
#define LOG_OR 276
#define LOG_AND 277
#define GE 278
#define LE 279
#define NE 280
#define EQ 281
#define PRM 282
#define TSH 283
#define COMM_OP 284
#define INVERT 285
#define DEREF_IDENT 286
#define INDEX 287
#define INC 288
#define DEC 289
#define IF 290
#define ELSE 291
#define STATIC 292
#define WHILE 293
#define STRING 294
#define FOR 295
#define ASM 296
#define PRAGMA 297
#define SIZEOF 298
#define STRUCT 299
#define PTRFIELD 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "parser.yy"

	type* tval;
	expression* exprval;
	lvalue* lval;
	variable* varval;
	char* strval;
	sllist* listval;
	int ival;

#line 285 "parser.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_DECIMAL = 4,                    /* DECIMAL  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_CONTINUE = 6,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_8_ = 8,                         /* '{'  */
  YYSYMBOL_9_ = 9,                         /* '}'  */
  YYSYMBOL_VOLATILE = 10,                  /* VOLATILE  */
  YYSYMBOL_EXTERN = 11,                    /* EXTERN  */
  YYSYMBOL_ISR = 12,                       /* ISR  */
  YYSYMBOL_TYPEDEBUG = 13,                 /* TYPEDEBUG  */
  YYSYMBOL_REENTRANT = 14,                 /* REENTRANT  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_SPTEST = 16,                    /* SPTEST  */
  YYSYMBOL_17_ = 17,                       /* '='  */
  YYSYMBOL_18_ = 18,                       /* '?'  */
  YYSYMBOL_ADDASSIGN = 19,                 /* ADDASSIGN  */
  YYSYMBOL_SUBASSIGN = 20,                 /* SUBASSIGN  */
  YYSYMBOL_MULASSIGN = 21,                 /* MULASSIGN  */
  YYSYMBOL_ANDASSIGN = 22,                 /* ANDASSIGN  */
  YYSYMBOL_XORASSIGN = 23,                 /* XORASSIGN  */
  YYSYMBOL_ORASSIGN = 24,                  /* ORASSIGN  */
  YYSYMBOL_LOG_OR = 25,                    /* LOG_OR  */
  YYSYMBOL_LOG_AND = 26,                   /* LOG_AND  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '~'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_40_ = 40,                       /* '|'  */
  YYSYMBOL_41_ = 41,                       /* '^'  */
  YYSYMBOL_PRM = 42,                       /* PRM  */
  YYSYMBOL_TSH = 43,                       /* TSH  */
  YYSYMBOL_COMM_OP = 44,                   /* COMM_OP  */
  YYSYMBOL_INVERT = 45,                    /* INVERT  */
  YYSYMBOL_DEREF_IDENT = 46,               /* DEREF_IDENT  */
  YYSYMBOL_INDEX = 47,                     /* INDEX  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_INC = 52,                       /* INC  */
  YYSYMBOL_DEC = 53,                       /* DEC  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_n_ = 57,                     /* '\n'  */
  YYSYMBOL_58_ = 58,                       /* '.'  */
  YYSYMBOL_IF = 59,                        /* IF  */
  YYSYMBOL_ELSE = 60,                      /* ELSE  */
  YYSYMBOL_STATIC = 61,                    /* STATIC  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL_STRING = 63,                    /* STRING  */
  YYSYMBOL_FOR = 64,                       /* FOR  */
  YYSYMBOL_ASM = 65,                       /* ASM  */
  YYSYMBOL_PRAGMA = 66,                    /* PRAGMA  */
  YYSYMBOL_SIZEOF = 67,                    /* SIZEOF  */
  YYSYMBOL_68_ = 68,                       /* '#'  */
  YYSYMBOL_STRUCT = 69,                    /* STRUCT  */
  YYSYMBOL_PTRFIELD = 70,                  /* PTRFIELD  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_codelines = 72,                 /* codelines  */
  YYSYMBOL_codeline = 73,                  /* codeline  */
  YYSYMBOL_metacommand = 74,               /* metacommand  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_jump_statement = 76,            /* jump_statement  */
  YYSYMBOL_conditional_statement = 77,     /* conditional_statement  */
  YYSYMBOL_asm = 78,                       /* asm  */
  YYSYMBOL_asm_instruction = 79,           /* asm_instruction  */
  YYSYMBOL_statement_block = 80,           /* statement_block  */
  YYSYMBOL_statements = 81,                /* statements  */
  YYSYMBOL_string = 82,                    /* string  */
  YYSYMBOL_scope = 83,                     /* scope  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_if_cnd_begin = 85,              /* if_cnd_begin  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_if_cnd = 87,                    /* if_cnd  */
  YYSYMBOL_88_3 = 88,                      /* $@3  */
  YYSYMBOL_while_cnd = 89,                 /* while_cnd  */
  YYSYMBOL_90_4 = 90,                      /* $@4  */
  YYSYMBOL_expr_or_null = 91,              /* expr_or_null  */
  YYSYMBOL_for_cnd = 92,                   /* for_cnd  */
  YYSYMBOL_93_5 = 93,                      /* $@5  */
  YYSYMBOL_fundef = 94,                    /* fundef  */
  YYSYMBOL_95_6 = 95,                      /* $@6  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_fundef_args = 97,               /* fundef_args  */
  YYSYMBOL_fundecl_glob_ = 98,             /* fundecl_glob_  */
  YYSYMBOL_fundecl_glob = 99,              /* fundecl_glob  */
  YYSYMBOL_struct_or_array_initializer = 100, /* struct_or_array_initializer  */
  YYSYMBOL_array_dimensions = 101,         /* array_dimensions  */
  YYSYMBOL_vardecl_local = 102,            /* vardecl_local  */
  YYSYMBOL_vardecl_local_list = 103,       /* vardecl_local_list  */
  YYSYMBOL_vardecl_locals = 104,           /* vardecl_locals  */
  YYSYMBOL_vardecl_glob = 105,             /* vardecl_glob  */
  YYSYMBOL_Type = 106,                     /* Type  */
  YYSYMBOL_struct = 107,                   /* struct  */
  YYSYMBOL_struct_fields = 108,            /* struct_fields  */
  YYSYMBOL_struct_declaration = 109,       /* struct_declaration  */
  YYSYMBOL_funcall_arg = 110,              /* funcall_arg  */
  YYSYMBOL_decimal = 111,                  /* decimal  */
  YYSYMBOL_expression = 112,               /* expression  */
  YYSYMBOL_evaluation = 113,               /* evaluation  */
  YYSYMBOL_assignment = 114                /* assignment  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    68,     2,    35,    39,     2,
      50,    51,    36,    33,    54,    34,    58,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    48,
      27,    17,    28,    18,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,    40,     9,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,    10,    11,    12,    13,    14,    15,    16,
      19,    20,    21,    22,    23,    24,    25,    26,    29,    30,
      31,    32,    42,    43,    44,    45,    46,    47,    52,    53,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    69,
      70
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   113,   115,   116,   117,   118,   119,   120,
     124,   125,   126,   127,   128,   131,   131,   140,   141,   142,
     143,   145,   146,   147,   148,   149,   152,   152,   152,   154,
     155,   156,   158,   159,   161,   161,   167,   171,   178,   178,
     184,   184,   189,   189,   190,   192,   192,   198,   199,   200,
     200,   216,   215,   224,   223,   233,   234,   235,   236,   237,
     238,   241,   246,   254,   255,   256,   263,   264,   266,   268,
     272,   273,   279,   280,   281,   286,   287,   292,   296,   299,
     300,   301,   303,   304,   308,   312,   319,   320,   321,   322,
     325,   330,   335,   340,   345,   351,   356,   367,   368,   369,
     370,   375,   376,   378,   379,   380,   381,   383,   390,   391,
     405,   406,   407,   412,   413,   416,   417,   418,   420,   421,
     424,   427,   428,   431,   435,   436,   437,   438,   439,   442,
     443,   444,   445,   446,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   465,   476,   488,   495,   501,   504,   509,
     519,   525,   526,   527,   528,   529,   530,   532,   533,   534,
     535
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "DECIMAL",
  "IDENTIFIER", "CONTINUE", "BREAK", "'{'", "'}'", "VOLATILE", "EXTERN",
  "ISR", "TYPEDEBUG", "REENTRANT", "RETURN", "SPTEST", "'='", "'?'",
  "ADDASSIGN", "SUBASSIGN", "MULASSIGN", "ANDASSIGN", "XORASSIGN",
  "ORASSIGN", "LOG_OR", "LOG_AND", "'<'", "'>'", "GE", "LE", "NE", "EQ",
  "'+'", "'-'", "'%'", "'*'", "'/'", "'~'", "'&'", "'|'", "'^'", "PRM",
  "TSH", "COMM_OP", "INVERT", "DEREF_IDENT", "INDEX", "';'", "':'", "'('",
  "')'", "INC", "DEC", "','", "'['", "']'", "'\\n'", "'.'", "IF", "ELSE",
  "STATIC", "WHILE", "STRING", "FOR", "ASM", "PRAGMA", "SIZEOF", "'#'",
  "STRUCT", "PTRFIELD", "$accept", "codelines", "codeline", "metacommand",
  "statement", "jump_statement", "conditional_statement", "asm",
  "asm_instruction", "statement_block", "statements", "string", "scope",
  "$@1", "if_cnd_begin", "$@2", "if_cnd", "$@3", "while_cnd", "$@4",
  "expr_or_null", "for_cnd", "$@5", "fundef", "$@6", "$@7", "fundef_args",
  "fundecl_glob_", "fundecl_glob", "struct_or_array_initializer",
  "array_dimensions", "vardecl_local", "vardecl_local_list",
  "vardecl_locals", "vardecl_glob", "Type", "struct", "struct_fields",
  "struct_declaration", "funcall_arg", "decimal", "expression",
  "evaluation", "assignment", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,  -303,    56,   -34,    -1,    12,    40,  -303,  -303,  -303,
    -303,   196,  -303,   115,  -303,   -17,   233,   118,   -18,   -45,
     130,  -303,   148,    56,  -303,  -303,    43,  -303,    -9,  -303,
      59,  -303,  -303,    91,  -303,   273,   111,  -303,     3,     5,
      56,   132,    33,  -303,  -303,   129,  -303,   193,  -303,    63,
      59,   160,   180,  -303,   117,   192,   -18,  -303,   210,  -303,
     230,  -303,    35,   270,  -303,   139,    95,   212,   305,   535,
     535,   535,   535,   535,   535,    95,   535,   535,   111,  -303,
     584,  -303,  -303,   282,   299,   144,   225,   284,  -303,    59,
    -303,  -303,  -303,   111,  -303,  -303,  -303,  -303,   285,   294,
     102,   636,   331,   305,    -5,  1156,  1156,   241,   241,  1246,
     241,   241,   104,   688,   293,   293,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   369,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,  -303,  -303,  -303,   535,   303,   307,    58,   290,    56,
     259,  -303,   305,   266,  -303,  -303,   304,  -303,  -303,  -303,
     324,  1156,     2,   280,   407,   535,  -303,  1156,  1156,  1156,
    1156,  1156,  1156,  1156,  1188,  1188,    59,  1214,  1214,  1214,
    1214,  1214,  1214,  1238,  1238,  1246,  1246,  1246,   241,   241,
     241,   241,   241,   740,  -303,  -303,    56,  -303,    58,  -303,
     164,    58,   184,   281,   112,  -303,  -303,  -303,   535,  -303,
    -303,   305,  1156,   293,   326,  -303,   199,  -303,   267,   231,
    -303,   301,   306,   312,  1156,   127,   334,   236,   318,   323,
      58,   535,   433,  -303,   327,   329,   330,  -303,  -303,  -303,
    -303,   367,   267,  -303,   328,  -303,  -303,  -303,   792,   471,
    -303,    -3,   240,   267,   333,   332,  -303,  -303,   535,   509,
    -303,   126,   268,  -303,  -303,  -303,   844,  -303,   896,   535,
     535,   535,  -303,  -303,  -303,  -303,   305,   948,   135,   378,
    -303,   381,   306,   241,   305,  1000,   211,   383,  -303,   267,
    -303,  -303,  1052,  1104,   344,  1156,   267,   151,  -303,   385,
     247,   305,  -303,   332,   183,  -303,   387,   252,   305,   388,
    -303,  -303,   535,  -303,   351,   305,   392,   198,   353,   305,
     396,   205,  -303,   267,   267,   358,  -303,   207,   305,   361,
    -303,   209,   305,   362,  -303,  -303,   535,   365,   216,  -303,
     366,   224,  -303,   373,  -303,   368,  -303,   370,  -303,  -303,
    -303,   267,  -303
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,     0,     0,     0,     0,     0,     2,     9,     7,
      63,     0,     4,     0,    98,     0,     0,     0,     0,     0,
       0,     8,   102,     0,     1,     3,     0,     5,     0,   100,
       0,     6,   102,     0,    37,     0,    30,    12,     0,     0,
       0,     0,     0,   110,    65,     0,    64,     0,    90,     0,
       0,     0,     0,    95,     0,     0,     0,    36,     0,    13,
       0,    11,     0,     0,   101,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   113,
       0,   116,   117,    61,     0,     0,     0,     0,    93,     0,
      99,    96,    29,    31,    14,    10,   107,   103,     0,     0,
       0,     0,     0,     0,     0,    66,   115,   122,   121,   149,
     123,   146,     0,     0,   157,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,   158,   160,     0,     0,     0,    88,    62,     0,
      55,    70,     0,     0,   104,   105,     0,   111,   112,   118,
       0,   108,     0,     0,     0,     0,   143,   150,   151,   152,
     153,   154,   155,   156,   135,   134,     0,   138,   137,   139,
     140,   141,   142,   129,   130,   133,   131,   132,   124,   125,
     126,   127,   128,     0,   148,   147,     0,    86,    89,    51,
       0,    88,     0,     0,     0,    71,   106,   119,     0,    67,
      92,     0,    68,   120,     0,   145,     0,    87,    32,     0,
      53,    58,    56,     0,   109,     0,     0,     0,     0,     0,
      88,     0,     0,    15,     0,     0,     0,    34,    17,    18,
      20,     0,    33,    19,    44,    26,    27,    28,     0,     0,
      72,     0,     0,    32,     0,    57,    94,    69,     0,     0,
      79,     0,     0,    21,    22,    38,     0,    23,     0,     0,
       0,    48,    52,    35,    42,    16,     0,     0,     0,     0,
      75,     0,    59,   136,     0,     0,     0,     0,    82,    32,
      25,    24,     0,     0,     0,    47,     0,     0,    73,     0,
       0,     0,    54,    60,     0,    80,     0,     0,     0,     0,
      40,    45,    48,    43,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    78,     0,     0,     0,
      81,     0,     0,     0,    41,    46,    48,     0,     0,    76,
       0,     0,    83,     0,    74,     0,    85,     0,    49,    77,
      84,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,   411,  -303,  -229,  -303,  -303,    15,  -303,  -147,
    -303,    -4,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -302,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   -98,
     -31,   222,  -303,  -195,  -303,   101,  -303,   386,  -303,  -303,
       7,   -47,  -303,  -303
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,     7,    21,   237,   238,   239,   240,    35,   241,
     242,    78,   243,   289,   244,   323,   245,   296,   246,   324,
     294,   247,   351,     9,   218,   253,    84,    10,    11,   104,
      51,   197,   198,   199,    12,   200,    14,    42,    15,   160,
      79,   105,    81,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    43,    54,    19,   163,   162,   220,    58,    47,    60,
     325,   209,    37,   273,    36,     8,    18,    22,    38,   101,
      23,     8,   106,   107,   108,   109,   110,   111,   113,   114,
     115,    31,    98,    46,   343,   265,     1,    52,     1,    48,
      24,    49,    64,     1,    96,    34,    50,    43,    44,   164,
       1,     2,    93,   278,   204,   161,   164,    86,     2,     1,
      59,     1,    61,    43,    45,    20,     1,   313,   156,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   334,   335,   153,   193,     1,    43,
      67,    13,    16,    17,    16,     3,   281,    13,     4,     5,
      45,    69,     3,   225,    83,     4,     5,   212,   213,   196,
      28,   223,   352,    33,    41,    16,    45,    16,    70,    71,
      43,    72,    16,    73,    74,    39,   257,    63,    29,    53,
      29,    41,   309,    65,    99,    75,    50,    76,    77,   150,
      85,    29,   299,   157,    29,   165,    40,    30,    34,    30,
     314,   224,    45,    65,    16,    91,   164,   100,    29,   219,
      30,   248,    89,    30,    57,    29,   112,    87,   297,    66,
      29,   164,   286,   214,   266,   268,   304,    30,   252,   221,
      50,   255,   318,    45,    30,   248,   262,    43,    67,    30,
      29,    68,   277,   317,   227,   164,   248,   329,    88,    69,
     321,   283,   285,    26,   333,    89,   337,   327,   340,    30,
      29,   331,   292,   293,   295,   345,    70,    71,   306,    72,
     338,    73,    74,   347,   341,    29,    90,   164,    32,    30,
      92,    23,   248,    75,    27,    76,    77,   300,   249,   248,
     202,   303,   164,   259,    30,   307,    34,   279,    86,   164,
      45,   164,   102,   164,   316,   295,    50,    94,    86,   320,
     164,    43,    67,   228,   229,   230,   248,   248,   164,   250,
     231,   151,   232,    69,   260,   287,   251,    95,   280,   295,
     147,   261,   152,   142,   143,    89,   144,   216,   201,   145,
      70,    71,    89,    72,   248,    73,    74,    89,   194,    43,
      67,   146,   195,   103,   203,   233,   288,    75,    97,    76,
      77,    69,   205,    89,    55,    50,   234,    56,   210,   235,
      34,   236,     3,   154,    45,    43,    67,   222,    70,    71,
      89,    72,   155,    73,    74,    -1,    -1,    69,    -1,    50,
     148,    -1,   206,   149,   226,    75,   254,    76,    77,    89,
     256,    50,   258,   146,    70,    71,   263,    72,    34,    73,
      74,   264,    45,    43,    67,   207,   272,   269,   208,   270,
     271,    75,   159,    76,    77,    69,   301,    89,   274,   282,
     302,   308,   312,   315,    34,   319,   176,   322,    45,   326,
     328,   330,    70,    71,   332,    72,   336,    73,    74,   339,
     342,    43,    67,   344,   346,   211,   349,    25,   350,    75,
     217,    76,    77,    69,   348,     0,    62,     0,     0,     0,
       0,     0,    34,     0,     0,     0,    45,    43,    67,     0,
      70,    71,     0,    72,     0,    73,    74,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,    75,     0,    76,
      77,     0,     0,     0,     0,     0,    70,    71,     0,    72,
      34,    73,    74,     0,    45,    43,    67,     0,     0,   276,
       0,   267,     0,    75,     0,    76,    77,    69,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
      45,     0,     0,     0,    70,    71,     0,    72,     0,    73,
      74,     0,     0,    43,    67,     0,     0,   284,     0,     0,
       0,    75,     0,    76,    77,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,    45,    43,
      67,     0,    70,    71,     0,    72,     0,    73,    74,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    76,    77,     0,     0,     0,     0,     0,    70,    71,
       0,    72,    34,    73,    74,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,   116,    45,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   141,     0,     0,     0,   142,   143,     0,   144,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   146,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,   158,   142,   143,
       0,   144,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   146,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,   166,
     142,   143,     0,   144,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   146,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,   144,   215,     0,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     146,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   136,   137,   138,   139,   140,     0,     0,     0,     0,
     275,     0,     0,     0,   142,   143,     0,   144,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   146,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   290,     0,     0,     0,   142,   143,     0,   144,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   146,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,   136,   137,   138,   139,   140,
       0,     0,     0,     0,   291,     0,     0,     0,   142,   143,
       0,   144,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   146,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,   136,   137,   138,
     139,   140,     0,     0,     0,     0,   298,     0,     0,     0,
     142,   143,     0,   144,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   146,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,   136,
     137,   138,   139,   140,     0,     0,     0,     0,   305,     0,
       0,     0,   142,   143,     0,   144,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     146,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,   310,   142,   143,     0,   144,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   146,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,   311,   142,   143,     0,   144,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   146,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,   144,     0,     0,   145,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   146,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,   144,     0,     0,   145,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,   140,   146,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,   144,
       0,     0,   145,   133,   134,   135,     0,   136,   137,   138,
     139,   140,     0,     0,   146,   136,   137,   138,   139,   140,
     142,   143,     0,   144,     0,     0,   145,     0,   142,   143,
       0,   144,     0,     0,   145,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,   146
};

static const yytype_int16 yycheck[] =
{
      47,     4,    33,     4,     9,   103,   201,     4,    17,     4,
     312,     9,    57,   242,    18,     0,    50,     5,    63,    66,
       8,     6,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    48,    63,    26,   336,   230,     3,    30,     3,    48,
       0,    50,     9,     3,     9,    63,    55,     4,     5,    54,
       3,    11,    56,    56,   152,   102,    54,    50,    11,     3,
      57,     3,    57,     4,    67,    66,     3,   296,    99,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   323,   324,    89,   144,     3,     4,
       5,     0,    69,     2,    69,    65,   253,     6,    68,    69,
      67,    16,    65,   211,    51,    68,    69,   164,   165,    61,
       5,     9,   351,     5,    23,    69,    67,    69,    33,    34,
       4,    36,    69,    38,    39,     5,     9,     5,    36,    48,
      36,    40,   289,    42,     5,    50,    55,    52,    53,     5,
      49,    36,    17,    51,    36,    51,     8,    55,    63,    55,
       9,   208,    67,    62,    69,    48,    54,    66,    36,     5,
      55,   218,    55,    55,    63,    36,    75,    17,   276,    50,
      36,    54,    56,   176,   231,   232,   284,    55,   219,     5,
      55,   222,     9,    67,    55,   242,   227,     4,     5,    55,
      36,     8,   249,   301,     5,    54,   253,     9,    48,    16,
     308,   258,   259,    17,     9,    55,     9,   315,     9,    55,
      36,   319,   269,   270,   271,     9,    33,    34,    17,    36,
     328,    38,    39,     9,   332,    36,    56,    54,     5,    55,
      48,     8,   289,    50,    48,    52,    53,   278,    17,   296,
     149,   282,    54,    17,    55,   286,    63,    17,   251,    54,
      67,    54,    50,    54,    17,   312,    55,    57,   261,    17,
      54,     4,     5,     6,     7,     8,   323,   324,    54,    48,
      13,    56,    15,    16,    48,    17,    55,    57,    48,   336,
       8,    55,     8,    52,    53,    55,    55,   196,     8,    58,
      33,    34,    55,    36,   351,    38,    39,    55,     5,     4,
       5,    70,     5,     8,    55,    48,    48,    50,    48,    52,
      53,    16,    56,    55,    51,    55,    59,    54,    48,    62,
      63,    64,    65,    48,    67,     4,     5,    56,    33,    34,
      55,    36,    48,    38,    39,    52,    53,    16,    55,    55,
      51,    58,    48,    54,    28,    50,    55,    52,    53,    55,
      48,    55,    28,    70,    33,    34,    48,    36,    63,    38,
      39,    48,    67,     4,     5,    51,     9,    50,    54,    50,
      50,    50,    51,    52,    53,    16,     8,    55,    60,    56,
       9,     8,    48,     8,    63,     8,    27,     9,    67,    48,
       8,    48,    33,    34,     8,    36,    48,    38,    39,    48,
      48,     4,     5,    48,    48,     8,    48,     6,    48,    50,
     198,    52,    53,    16,    51,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    67,     4,     5,    -1,
      33,    34,    -1,    36,    -1,    38,    39,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      63,    38,    39,    -1,    67,     4,     5,    -1,    -1,     8,
      -1,    48,    -1,    50,    -1,    52,    53,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    33,    34,    -1,    36,    -1,    38,
      39,    -1,    -1,     4,     5,    -1,    -1,     8,    -1,    -1,
      -1,    50,    -1,    52,    53,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,     4,
       5,    -1,    33,    34,    -1,    36,    -1,    38,    39,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    63,    38,    39,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    17,    67,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    70,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    70,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    70,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      70,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    70,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    70,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,    53,
      -1,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    70,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      52,    53,    -1,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    70,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    53,    -1,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      70,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    70,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    70,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,    -1,    -1,    58,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    70,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    55,    -1,    -1,    58,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,
      -1,    -1,    58,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    70,    39,    40,    41,    42,    43,
      52,    53,    -1,    55,    -1,    -1,    58,    -1,    52,    53,
      -1,    55,    -1,    -1,    58,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    65,    68,    69,    72,    73,    78,    94,
      98,    99,   105,   106,   107,   109,    69,   106,    50,     4,
      66,    74,     5,     8,     0,    73,    17,    48,     5,    36,
      55,    48,     5,     5,    63,    79,    82,    57,    63,     5,
       8,   106,   108,     4,     5,    67,   111,    17,    48,    50,
      55,   101,   111,    48,   101,    51,    54,    63,     4,    57,
       4,    57,   108,     5,     9,   106,    50,     5,     8,    16,
      33,    34,    36,    38,    39,    50,    52,    53,    82,   111,
     112,   113,   114,    51,    97,   106,   111,    17,    48,    55,
      56,    48,    48,    82,    57,    57,     9,    48,   101,     5,
     106,   112,    50,     8,   100,   112,   112,   112,   112,   112,
     112,   112,   106,   112,   112,   112,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    39,    40,    41,    42,
      43,    48,    52,    53,    55,    58,    70,     8,    51,    54,
       5,    56,     8,   111,    48,    48,   101,    51,    51,    51,
     110,   112,   100,     9,    54,    51,    51,   112,   112,   112,
     112,   112,   112,   112,   112,   112,    27,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,     5,     5,    61,   102,   103,   104,
     106,     8,   106,    55,   100,    56,    48,    51,    54,     9,
      48,     8,   112,   112,   111,    56,   106,   102,    95,     5,
     104,     5,    56,     9,   112,   100,    28,     5,     6,     7,
       8,    13,    15,    48,    59,    62,    64,    75,    76,    77,
      78,    80,    81,    83,    85,    87,    89,    92,   112,    17,
      48,    55,   101,    96,    55,   101,    48,     9,    28,    17,
      48,    55,   101,    48,    48,   104,   112,    48,   112,    50,
      50,    50,     9,    75,    60,    48,     8,   112,    56,    17,
      48,    80,    56,   112,     8,   112,    56,    17,    48,    84,
      48,    48,   112,   112,    91,   112,    88,   100,    48,    17,
     101,     8,     9,   101,   100,    48,    17,   101,     8,    80,
      51,    51,    48,    75,     9,     8,    17,   100,     9,     8,
      17,   100,     9,    86,    90,    91,    48,   100,     8,     9,
      48,   100,     8,     9,    75,    75,    48,     9,   100,    48,
       9,   100,    48,    91,    48,     9,    48,     9,    51,    48,
      48,    93,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    84,    83,
      86,    85,    88,    87,    87,    90,    89,    91,    91,    93,
      92,    95,    94,    96,    94,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   108,   108,   108,   108,   109,   110,   110,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     2,     1,
       4,     3,     2,     3,     4,     1,     2,     1,     1,     1,
       1,     2,     2,     2,     3,     3,     1,     1,     1,     5,
       1,     3,     0,     1,     1,     2,     2,     1,     0,     5,
       0,     6,     0,     4,     1,     0,     6,     1,     0,     0,
      10,     0,     9,     0,    10,     2,     4,     5,     4,     6,
       7,     4,     5,     1,     3,     3,     1,     3,     3,     5,
       3,     4,     3,     5,     9,     4,     8,    10,     7,     4,
       6,     8,     5,     9,    11,    10,     1,     2,     0,     1,
       3,     5,     7,     4,     8,     4,     5,     1,     1,     4,
       2,     4,     2,     3,     4,     4,     5,     5,     1,     3,
       1,     4,     4,     1,     1,     2,     1,     1,     3,     4,
       4,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     2,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 10: /* metacommand: PRAGMA IDENTIFIER DECIMAL '\n'  */
#line 124 "parser.yy"
                                       { compiler::instance()->pragma((yyvsp[-2].strval), (yyvsp[-1].ival)); }
#line 1809 "parser.cc"
    break;

  case 11: /* metacommand: PRAGMA IDENTIFIER '\n'  */
#line 125 "parser.yy"
                                 { compiler::instance()->pragma((yyvsp[-1].strval)); }
#line 1815 "parser.cc"
    break;

  case 12: /* metacommand: DECIMAL '\n'  */
#line 126 "parser.yy"
                       { compiler::instance()->set_effective_location(NULL, (yyvsp[-1].ival)); }
#line 1821 "parser.cc"
    break;

  case 13: /* metacommand: DECIMAL STRING '\n'  */
#line 127 "parser.yy"
                              { compiler::instance()->set_effective_location((yyvsp[-1].strval), (yyvsp[-2].ival)); }
#line 1827 "parser.cc"
    break;

  case 14: /* metacommand: DECIMAL STRING DECIMAL '\n'  */
#line 128 "parser.yy"
                                      { compiler::instance()->set_effective_location((yyvsp[-2].strval), (yyvsp[-3].ival)); }
#line 1833 "parser.cc"
    break;

  case 16: /* statement: expression ';'  */
#line 132 "parser.yy"
                        {
				if((yyvsp[-1].exprval) != NULL) {  
					expression* p = new cleaner((yyvsp[-1].exprval));
					p->autoeval();
					delete p;
					compiler::instance()->printf("\n");
				} else { printf("Null expression"); }
			}
#line 1846 "parser.cc"
    break;

  case 21: /* jump_statement: CONTINUE ';'  */
#line 145 "parser.yy"
                             { cond_mgr::cont_cond(); }
#line 1852 "parser.cc"
    break;

  case 22: /* jump_statement: BREAK ';'  */
#line 146 "parser.yy"
                            { cond_mgr::brk_cond(); }
#line 1858 "parser.cc"
    break;

  case 23: /* jump_statement: RETURN ';'  */
#line 147 "parser.yy"
                             { function::get_current()->do_return(); }
#line 1864 "parser.cc"
    break;

  case 24: /* jump_statement: RETURN expression ';'  */
#line 148 "parser.yy"
                                        { function::get_current()->do_return((yyvsp[-1].exprval)); }
#line 1870 "parser.cc"
    break;

  case 25: /* jump_statement: TYPEDEBUG expression ';'  */
#line 149 "parser.yy"
                                           { (yyvsp[-1].exprval)->typ()->id(); puts(""); }
#line 1876 "parser.cc"
    break;

  case 30: /* asm_instruction: string  */
#line 155 "parser.yy"
                         { compiler::instance()->printf("\t\t%s\n", (yyvsp[0].strval)); }
#line 1882 "parser.cc"
    break;

  case 31: /* asm_instruction: asm_instruction ',' string  */
#line 156 "parser.yy"
                                             { compiler::instance()->printf("\t\t%s\n", (yyvsp[0].strval)); }
#line 1888 "parser.cc"
    break;

  case 36: /* string: string STRING  */
#line 168 "parser.yy"
        { char* s = (char*) malloc(strlen((yyvsp[-1].strval)) + strlen((yyvsp[0].strval))+1); 
  	  sprintf(s, "%s%s", (yyvsp[-1].strval), (yyvsp[0].strval));
	  (yyval.strval) = s; }
#line 1896 "parser.cc"
    break;

  case 37: /* string: STRING  */
#line 171 "parser.yy"
                 { (yyval.strval) = (yyvsp[0].strval); }
#line 1902 "parser.cc"
    break;

  case 38: /* $@1: %empty  */
#line 178 "parser.yy"
                           { cond_mgr::add_scope();
			     function::get_current()->add_scope((yyvsp[0].listval)); }
#line 1909 "parser.cc"
    break;

  case 39: /* scope: '{' vardecl_locals $@1 statement_block '}'  */
#line 180 "parser.yy"
                            { cond_mgr::end_scope();
			     function::get_current()->end_scope(); }
#line 1916 "parser.cc"
    break;

  case 40: /* $@2: %empty  */
#line 184 "parser.yy"
                              {
			conditional_* c = new if_cnd((yyvsp[-1].exprval));
			cond_mgr::init_cond(c);
			}
#line 1925 "parser.cc"
    break;

  case 42: /* $@3: %empty  */
#line 189 "parser.yy"
                          { cond_mgr::intermediate_cond(); }
#line 1931 "parser.cc"
    break;

  case 43: /* if_cnd: if_cnd_begin ELSE $@3 statement  */
#line 189 "parser.yy"
                                                                       { cond_mgr::dispose_cond(); }
#line 1937 "parser.cc"
    break;

  case 44: /* if_cnd: if_cnd_begin  */
#line 190 "parser.yy"
                       { cond_mgr::intermediate_cond(); cond_mgr::dispose_cond(); }
#line 1943 "parser.cc"
    break;

  case 45: /* $@4: %empty  */
#line 192 "parser.yy"
                                    {
				conditional_* c = new while_cnd((yyvsp[-1].exprval));
				cond_mgr::init_cond(c); }
#line 1951 "parser.cc"
    break;

  case 46: /* while_cnd: WHILE '(' expression ')' $@4 statement  */
#line 196 "parser.yy"
                        { 	cond_mgr::dispose_cond(); 	}
#line 1957 "parser.cc"
    break;

  case 47: /* expr_or_null: expression  */
#line 198 "parser.yy"
                         { (yyval.exprval) = (yyvsp[0].exprval); }
#line 1963 "parser.cc"
    break;

  case 48: /* expr_or_null: %empty  */
#line 199 "parser.yy"
                     { (yyval.exprval) = NULL; }
#line 1969 "parser.cc"
    break;

  case 49: /* $@5: %empty  */
#line 200 "parser.yy"
                                                                    {
				 conditional_* c = new for_cnd((yyvsp[-5].exprval), 
						(yyvsp[-3].exprval), (yyvsp[-1].exprval));
				cond_mgr::init_cond(c); }
#line 1978 "parser.cc"
    break;

  case 50: /* for_cnd: FOR '(' expr_or_null ';' expr_or_null ';' expr_or_null ')' $@5 statement  */
#line 205 "parser.yy"
                        { 	cond_mgr::dispose_cond(); 	}
#line 1984 "parser.cc"
    break;

  case 51: /* $@6: %empty  */
#line 216 "parser.yy"
                   { 
			function_prototype fp((yyvsp[-5].tval), NULL);
		     	compiler::instance()->decl_fun((yyvsp[-4].strval), fp); 
	  	      	function::init_definition(fp, (yyvsp[-4].strval), (yyvsp[-5].tval), NULL, (yyvsp[0].listval)); 
		    }
#line 1994 "parser.cc"
    break;

  case 52: /* fundef: Type IDENTIFIER '(' ')' '{' vardecl_locals $@6 statement_block '}'  */
#line 222 "parser.yy"
                    { function::finish_definition(); }
#line 2000 "parser.cc"
    break;

  case 53: /* $@7: %empty  */
#line 224 "parser.yy"
                 { 
			function_prototype fp((yyvsp[-6].tval), (yyvsp[-3].listval));
			compiler::instance()->decl_fun((yyvsp[-5].strval), fp); 
		      	function::init_definition(fp, (yyvsp[-5].strval), (yyvsp[-6].tval), (yyvsp[-3].listval), (yyvsp[0].listval)); 
		    }
#line 2010 "parser.cc"
    break;

  case 54: /* fundef: Type IDENTIFIER '(' fundef_args ')' '{' vardecl_locals $@7 statement_block '}'  */
#line 230 "parser.yy"
                    { function::finish_definition(); }
#line 2016 "parser.cc"
    break;

  case 55: /* fundef_args: Type IDENTIFIER  */
#line 233 "parser.yy"
                        { (yyval.listval) = new sllist((void*)(yyvsp[-1].tval), (void*)(yyvsp[0].strval)); }
#line 2022 "parser.cc"
    break;

  case 56: /* fundef_args: Type IDENTIFIER '[' ']'  */
#line 234 "parser.yy"
                                  { (yyval.listval) = new sllist(new t_ptr((yyvsp[-3].tval)), (void*)(yyvsp[-2].strval)); }
#line 2028 "parser.cc"
    break;

  case 57: /* fundef_args: Type IDENTIFIER '[' ']' array_dimensions  */
#line 235 "parser.yy"
                                                   { (yyval.listval) = new sllist(new t_ptr(matrix_type((yyvsp[-4].tval), (yyvsp[0].listval))), (void*)(yyvsp[-3].strval)); }
#line 2034 "parser.cc"
    break;

  case 58: /* fundef_args: fundef_args ',' Type IDENTIFIER  */
#line 236 "parser.yy"
                                          { (yyval.listval) = new sllist((yyvsp[-3].listval), (yyvsp[-1].tval), (yyvsp[0].strval)); }
#line 2040 "parser.cc"
    break;

  case 59: /* fundef_args: fundef_args ',' Type IDENTIFIER '[' ']'  */
#line 237 "parser.yy"
                                                  { (yyval.listval) = new sllist(new t_ptr((yyvsp[-3].tval)), (void*)(yyvsp[-2].strval)); }
#line 2046 "parser.cc"
    break;

  case 60: /* fundef_args: fundef_args ',' Type IDENTIFIER '[' ']' array_dimensions  */
#line 238 "parser.yy"
                                                                   { (yyval.listval) = new sllist(new t_ptr(matrix_type((yyvsp[-4].tval), (yyvsp[0].listval))), (void*)(yyvsp[-3].strval)); }
#line 2052 "parser.cc"
    break;

  case 61: /* fundecl_glob_: Type IDENTIFIER '(' ')'  */
#line 241 "parser.yy"
                                { 
		function_prototype fp((yyvsp[-3].tval), NULL);
		compiler::instance()->decl_fun((yyvsp[-2].strval), fp); 
		(yyval.strval) = (yyvsp[-2].strval);
	}
#line 2062 "parser.cc"
    break;

  case 62: /* fundecl_glob_: Type IDENTIFIER '(' fundef_args ')'  */
#line 246 "parser.yy"
                                              { 
		function_prototype fp((yyvsp[-4].tval), (yyvsp[-1].listval));
		compiler::instance()->decl_fun((yyvsp[-3].strval), fp); 
		(yyval.strval) = (yyvsp[-3].strval);
	}
#line 2072 "parser.cc"
    break;

  case 64: /* fundecl_glob: fundecl_glob '=' decimal  */
#line 255 "parser.yy"
                                   { compiler::instance()->printf("%s\t@EQU\t%d\n", (yyvsp[-2].strval), (yyvsp[0].ival)); }
#line 2078 "parser.cc"
    break;

  case 65: /* fundecl_glob: fundecl_glob '=' IDENTIFIER  */
#line 256 "parser.yy"
                                      { 
		compiler::instance()->printf("%s\t@EQU\t%d\n", (yyvsp[-2].strval), (yyvsp[0].strval)); 
	}
#line 2086 "parser.cc"
    break;

  case 66: /* struct_or_array_initializer: expression  */
#line 263 "parser.yy"
                                   { (yyval.listval) = new sllist((yyvsp[0].varval)); }
#line 2092 "parser.cc"
    break;

  case 67: /* struct_or_array_initializer: '{' struct_or_array_initializer '}'  */
#line 265 "parser.yy"
                           { (yyval.listval) = new sllist(NULL, NULL, (yyvsp[-1].listval)); }
#line 2098 "parser.cc"
    break;

  case 68: /* struct_or_array_initializer: struct_or_array_initializer ',' expression  */
#line 267 "parser.yy"
                           {  (yyval.listval) = new sllist((yyvsp[-2].listval), (yyvsp[0].varval));  }
#line 2104 "parser.cc"
    break;

  case 69: /* struct_or_array_initializer: struct_or_array_initializer ',' '{' struct_or_array_initializer '}'  */
#line 269 "parser.yy"
                           { (yyval.listval) = new sllist((yyvsp[-4].listval), NULL, (yyvsp[-1].varval)); }
#line 2110 "parser.cc"
    break;

  case 70: /* array_dimensions: '[' decimal ']'  */
#line 272 "parser.yy"
                        { (yyval.listval) = new sllist((void*)((yyvsp[-1].ival))); }
#line 2116 "parser.cc"
    break;

  case 71: /* array_dimensions: array_dimensions '[' decimal ']'  */
#line 274 "parser.yy"
                        { (yyval.listval) = new sllist((yyvsp[-3].listval), (void*)((yyvsp[-1].ival))); }
#line 2122 "parser.cc"
    break;

  case 72: /* vardecl_local: Type IDENTIFIER ';'  */
#line 279 "parser.yy"
                            { (yyval.varval) = new dynamic_variable((yyvsp[-1].strval), (yyvsp[-2].tval)); }
#line 2128 "parser.cc"
    break;

  case 73: /* vardecl_local: Type IDENTIFIER '=' expression ';'  */
#line 280 "parser.yy"
                                             { (yyval.varval) = new dynamic_variable((yyvsp[-3].strval), (yyvsp[-4].tval), (yyvsp[-1].exprval)); }
#line 2134 "parser.cc"
    break;

  case 74: /* vardecl_local: Type IDENTIFIER '[' ']' '=' '{' struct_or_array_initializer '}' ';'  */
#line 282 "parser.yy"
                        {
				type* t = matrix_type_lazy((yyvsp[-8].tval), NULL, (yyvsp[-2].listval));
				(yyval.varval) = new dynamic_variable((yyvsp[-7].strval), t, new composite_initializer(t, (yyvsp[-2].listval)));; 
			}
#line 2143 "parser.cc"
    break;

  case 75: /* vardecl_local: Type IDENTIFIER array_dimensions ';'  */
#line 286 "parser.yy"
                                               { (yyval.varval) = new dynamic_variable((yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); }
#line 2149 "parser.cc"
    break;

  case 76: /* vardecl_local: Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';'  */
#line 287 "parser.yy"
                                                                                       {
		type* t = matrix_type((yyvsp[-7].tval), (yyvsp[-5].listval));
		(yyval.varval) = new dynamic_variable((yyvsp[-6].strval), t, new composite_initializer(t , (yyvsp[-2].listval))); 
	}
#line 2158 "parser.cc"
    break;

  case 77: /* vardecl_local: Type IDENTIFIER '[' ']' array_dimensions '=' '{' struct_or_array_initializer '}' ';'  */
#line 292 "parser.yy"
                                                                                               {
		type* t = matrix_type_lazy((yyvsp[-9].tval), (yyvsp[-5].listval), (yyvsp[-2].listval));
		(yyval.varval) = new dynamic_variable((yyvsp[-8].strval), t, new composite_initializer(t, (yyvsp[-2].listval))); 
	}
#line 2167 "parser.cc"
    break;

  case 78: /* vardecl_local: Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';'  */
#line 296 "parser.yy"
                                                                      { (yyval.varval) = new dynamic_variable((yyvsp[-5].strval), (yyvsp[-6].tval), new composite_initializer((yyvsp[-6].tval), (yyvsp[-2].listval))); }
#line 2173 "parser.cc"
    break;

  case 79: /* vardecl_local: STATIC Type IDENTIFIER ';'  */
#line 299 "parser.yy"
                                     { (yyval.varval) = new static_variable((yyvsp[-1].strval), (yyvsp[-2].tval)); }
#line 2179 "parser.cc"
    break;

  case 80: /* vardecl_local: STATIC Type IDENTIFIER '=' expression ';'  */
#line 300 "parser.yy"
                                                    { (yyval.varval) = new static_variable((yyvsp[-3].strval), (yyvsp[-4].tval), (yyvsp[-1].exprval)); }
#line 2185 "parser.cc"
    break;

  case 81: /* vardecl_local: STATIC Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';'  */
#line 302 "parser.yy"
                { (yyval.varval) = new static_variable((yyvsp[-5].strval), (yyvsp[-6].tval), new composite_initializer((yyvsp[-6].tval), (yyvsp[-2].listval))); }
#line 2191 "parser.cc"
    break;

  case 82: /* vardecl_local: STATIC Type IDENTIFIER array_dimensions ';'  */
#line 303 "parser.yy"
                                                      { (yyval.varval) = new static_variable((yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); }
#line 2197 "parser.cc"
    break;

  case 83: /* vardecl_local: STATIC Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';'  */
#line 304 "parser.yy"
                                                                                              {
		type* t = matrix_type((yyvsp[-7].tval), (yyvsp[-5].listval));
		(yyval.varval) = new static_variable((yyvsp[-6].strval), t, new composite_initializer(t , (yyvsp[-2].listval))); 
	}
#line 2206 "parser.cc"
    break;

  case 84: /* vardecl_local: STATIC Type IDENTIFIER '[' ']' array_dimensions '=' '{' struct_or_array_initializer '}' ';'  */
#line 308 "parser.yy"
                                                                                                      {
		type* t = matrix_type_lazy((yyvsp[-9].tval), (yyvsp[-5].listval), (yyvsp[-2].listval));
		(yyval.varval) = new static_variable((yyvsp[-8].strval), t, new composite_initializer(t , (yyvsp[-2].listval))); 
	}
#line 2215 "parser.cc"
    break;

  case 85: /* vardecl_local: STATIC Type IDENTIFIER '[' ']' '=' '{' struct_or_array_initializer '}' ';'  */
#line 312 "parser.yy"
                                                                                     {
		type* t = matrix_type_lazy((yyvsp[-8].tval), NULL, (yyvsp[-2].listval));
		(yyval.varval) = new static_variable((yyvsp[-7].strval), t, new composite_initializer(t , (yyvsp[-2].listval))); 
	}
#line 2224 "parser.cc"
    break;

  case 86: /* vardecl_local_list: vardecl_local  */
#line 319 "parser.yy"
                      { (yyval.listval) = new sllist((yyvsp[0].varval)); }
#line 2230 "parser.cc"
    break;

  case 87: /* vardecl_local_list: vardecl_local_list vardecl_local  */
#line 320 "parser.yy"
                                         { (yyval.listval) = new sllist((yyvsp[-1].listval), (yyvsp[0].varval)); }
#line 2236 "parser.cc"
    break;

  case 88: /* vardecl_locals: %empty  */
#line 321 "parser.yy"
                { (yyval.listval) = NULL; }
#line 2242 "parser.cc"
    break;

  case 89: /* vardecl_locals: vardecl_local_list  */
#line 322 "parser.yy"
                             { (yyval.listval) = (yyvsp[0].listval); }
#line 2248 "parser.cc"
    break;

  case 90: /* vardecl_glob: Type IDENTIFIER ';'  */
#line 325 "parser.yy"
                            { 
		variable* v = new static_variable((yyvsp[-1].strval), (yyvsp[-2].tval));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define((yyvsp[-1].strval));
		}
#line 2258 "parser.cc"
    break;

  case 91: /* vardecl_glob: Type IDENTIFIER '=' expression ';'  */
#line 330 "parser.yy"
                                             { 
		variable* v = new static_variable((yyvsp[-3].strval), (yyvsp[-4].tval), (yyvsp[-1].exprval));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define((yyvsp[-3].strval));
		}
#line 2268 "parser.cc"
    break;

  case 92: /* vardecl_glob: Type IDENTIFIER '=' '{' struct_or_array_initializer '}' ';'  */
#line 335 "parser.yy"
                                                                      { 
		variable* v = new static_variable((yyvsp[-5].strval), (yyvsp[-6].tval), new composite_initializer((yyvsp[-6].tval), (yyvsp[-2].listval)));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define((yyvsp[-5].strval));
		}
#line 2278 "parser.cc"
    break;

  case 93: /* vardecl_glob: Type IDENTIFIER array_dimensions ';'  */
#line 340 "parser.yy"
                                               { 
		variable* v = new static_variable((yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); 
		variable_set::glob_instance()->add_var(v);
		v->get_initial()->define((yyvsp[-2].strval));
	}
#line 2288 "parser.cc"
    break;

  case 94: /* vardecl_glob: Type IDENTIFIER array_dimensions '=' '{' struct_or_array_initializer '}' ';'  */
#line 345 "parser.yy"
                                                                                       { 
		type* t = matrix_type((yyvsp[-7].tval), (yyvsp[-5].listval));
		variable* v = new static_variable((yyvsp[-6].strval), t, new composite_initializer(t, (yyvsp[-2].listval)));
		variable_set::glob_instance()->add_var(v); 
		v->get_initial()->define((yyvsp[-6].strval));
		}
#line 2299 "parser.cc"
    break;

  case 95: /* vardecl_glob: EXTERN Type IDENTIFIER ';'  */
#line 351 "parser.yy"
                                     {
		variable* v = new static_variable((yyvsp[-1].strval), (yyvsp[-2].tval));
		v->set_extern(true);
		variable_set::glob_instance()->add_var(v); 
	}
#line 2309 "parser.cc"
    break;

  case 96: /* vardecl_glob: EXTERN Type IDENTIFIER array_dimensions ';'  */
#line 356 "parser.yy"
                                                      { 
		variable* v = new static_variable((yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); 
		v->set_extern(true);
		variable_set::glob_instance()->add_var(v);
	}
#line 2319 "parser.cc"
    break;

  case 97: /* Type: TYPE  */
#line 367 "parser.yy"
             { (yyval.tval) = (yyvsp[0].tval); }
#line 2325 "parser.cc"
    break;

  case 98: /* Type: struct  */
#line 368 "parser.yy"
                 { (yyval.tval) = (yyvsp[0].tval); }
#line 2331 "parser.cc"
    break;

  case 99: /* Type: Type '[' decimal ']'  */
#line 369 "parser.yy"
                               { (yyval.tval) = new t_array((yyvsp[-3].tval), (yyvsp[-1].ival)); }
#line 2337 "parser.cc"
    break;

  case 100: /* Type: Type '*'  */
#line 370 "parser.yy"
                   { (yyval.tval) = new t_ptr((yyvsp[-1].tval)); }
#line 2343 "parser.cc"
    break;

  case 101: /* struct: STRUCT '{' struct_fields '}'  */
#line 375 "parser.yy"
                                     { (yyval.tval) = new t_struct((yyvsp[-1].listval)); }
#line 2349 "parser.cc"
    break;

  case 102: /* struct: STRUCT IDENTIFIER  */
#line 376 "parser.yy"
                            { (yyval.tval) = compiler::instance()->struct_ref((yyvsp[0].strval)); }
#line 2355 "parser.cc"
    break;

  case 103: /* struct_fields: Type IDENTIFIER ';'  */
#line 378 "parser.yy"
                            { (yyval.listval) = new sllist((yyvsp[-1].strval), (yyvsp[-2].tval)); }
#line 2361 "parser.cc"
    break;

  case 104: /* struct_fields: Type IDENTIFIER array_dimensions ';'  */
#line 379 "parser.yy"
                                               { (yyval.listval) = new sllist((yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); }
#line 2367 "parser.cc"
    break;

  case 105: /* struct_fields: struct_fields Type IDENTIFIER ';'  */
#line 380 "parser.yy"
                                            { (yyval.listval) = new sllist((yyvsp[-3].listval), (yyvsp[-1].strval), (yyvsp[-2].tval)); }
#line 2373 "parser.cc"
    break;

  case 106: /* struct_fields: struct_fields Type IDENTIFIER array_dimensions ';'  */
#line 381 "parser.yy"
                                                             { (yyval.listval) = new sllist((yyvsp[-4].listval), (yyvsp[-2].strval), matrix_type((yyvsp[-3].tval), (yyvsp[-1].listval))); }
#line 2379 "parser.cc"
    break;

  case 107: /* struct_declaration: STRUCT IDENTIFIER '{' struct_fields '}'  */
#line 383 "parser.yy"
                                                { compiler::instance()->decl_struct((yyvsp[-3].strval), new t_struct((yyvsp[-1].listval))); }
#line 2385 "parser.cc"
    break;

  case 108: /* funcall_arg: expression  */
#line 390 "parser.yy"
                        { (yyval.listval) = new sllist((yyvsp[0].exprval)); }
#line 2391 "parser.cc"
    break;

  case 109: /* funcall_arg: funcall_arg ',' expression  */
#line 391 "parser.yy"
                                     { (yyval.listval) = new sllist((yyvsp[-2].listval), (yyvsp[0].exprval)); }
#line 2397 "parser.cc"
    break;

  case 110: /* decimal: DECIMAL  */
#line 405 "parser.yy"
                { (yyval.ival) = (yyvsp[0].ival); }
#line 2403 "parser.cc"
    break;

  case 111: /* decimal: SIZEOF '(' Type ')'  */
#line 406 "parser.yy"
                              { (yyval.ival) = (yyvsp[-1].tval)->size(); }
#line 2409 "parser.cc"
    break;

  case 112: /* decimal: SIZEOF '(' expression ')'  */
#line 407 "parser.yy"
                                    { (yyval.ival) = (yyvsp[-1].exprval)->typ()->size(); }
#line 2415 "parser.cc"
    break;

  case 113: /* expression: decimal  */
#line 412 "parser.yy"
                { (yyval.exprval) = new constant((yyvsp[0].ival)); }
#line 2421 "parser.cc"
    break;

  case 114: /* expression: string  */
#line 413 "parser.yy"
                 { memory_node* n = new string_node((yyvsp[0].strval));
		  (yyval.exprval) = compiler::instance()->get_mmgr()->add(n);
		}
#line 2429 "parser.cc"
    break;

  case 115: /* expression: SPTEST expression  */
#line 416 "parser.yy"
                            { (yyval.exprval) = new sp_test((yyvsp[0].exprval)); }
#line 2435 "parser.cc"
    break;

  case 116: /* expression: evaluation  */
#line 417 "parser.yy"
                     { (yyval.exprval) = (yyvsp[0].exprval); }
#line 2441 "parser.cc"
    break;

  case 117: /* expression: assignment  */
#line 418 "parser.yy"
                     { (yyval.exprval) = (yyvsp[0].exprval); }
#line 2447 "parser.cc"
    break;

  case 118: /* expression: IDENTIFIER '(' ')'  */
#line 420 "parser.yy"
                             { (yyval.exprval) = new function_call((yyvsp[-2].strval), compiler::instance()->fun_ref((yyvsp[-2].strval)), NULL); }
#line 2453 "parser.cc"
    break;

  case 119: /* expression: IDENTIFIER '(' funcall_arg ')'  */
#line 421 "parser.yy"
                                         { (yyval.exprval) = new function_call((yyvsp[-3].strval), 
							compiler::instance()->fun_ref((yyvsp[-3].strval)), (yyvsp[-1].listval)); }
#line 2460 "parser.cc"
    break;

  case 120: /* expression: '(' Type ')' expression  */
#line 424 "parser.yy"
                                  { (yyval.exprval) = new word_caster((yyvsp[0].exprval), (yyvsp[-2].tval)); }
#line 2466 "parser.cc"
    break;

  case 121: /* expression: '-' expression  */
#line 427 "parser.yy"
                                      { (yyval.exprval) = new inverter((yyvsp[0].exprval)); }
#line 2472 "parser.cc"
    break;

  case 122: /* expression: '+' expression  */
#line 428 "parser.yy"
                                      { (yyval.exprval) = (yyvsp[0].exprval); }
#line 2478 "parser.cc"
    break;

  case 123: /* expression: '~' expression  */
#line 431 "parser.yy"
                         { (yyval.exprval) = new sign((yyvsp[0].exprval)); }
#line 2484 "parser.cc"
    break;

  case 124: /* expression: expression '&' expression  */
#line 435 "parser.yy"
                                    { (yyval.exprval) = new ander((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2490 "parser.cc"
    break;

  case 125: /* expression: expression '|' expression  */
#line 436 "parser.yy"
                                    { (yyval.exprval) = new orer((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2496 "parser.cc"
    break;

  case 126: /* expression: expression '^' expression  */
#line 437 "parser.yy"
                                    { (yyval.exprval) = new xorer((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2502 "parser.cc"
    break;

  case 127: /* expression: expression PRM expression  */
#line 438 "parser.yy"
                                    { (yyval.exprval) = new prm((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2508 "parser.cc"
    break;

  case 128: /* expression: expression TSH expression  */
#line 439 "parser.yy"
                                    { (yyval.exprval) = new tsh((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2514 "parser.cc"
    break;

  case 129: /* expression: expression '+' expression  */
#line 442 "parser.yy"
                                    { (yyval.exprval) = new adder((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2520 "parser.cc"
    break;

  case 130: /* expression: expression '-' expression  */
#line 443 "parser.yy"
                                    { (yyval.exprval) = new adder((yyvsp[-2].exprval), new inverter((yyvsp[0].exprval))); }
#line 2526 "parser.cc"
    break;

  case 131: /* expression: expression '*' expression  */
#line 444 "parser.yy"
                                    { (yyval.exprval) = new mul((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2532 "parser.cc"
    break;

  case 132: /* expression: expression '/' expression  */
#line 445 "parser.yy"
                                    { (yyval.exprval) = new divider((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2538 "parser.cc"
    break;

  case 133: /* expression: expression '%' expression  */
#line 446 "parser.yy"
                                    { (yyval.exprval) = new modulo((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2544 "parser.cc"
    break;

  case 134: /* expression: expression LOG_AND expression  */
#line 449 "parser.yy"
                                        { (yyval.exprval) = new logical_ander((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2550 "parser.cc"
    break;

  case 135: /* expression: expression LOG_OR expression  */
#line 450 "parser.yy"
                                       { (yyval.exprval) = new logical_orer((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2556 "parser.cc"
    break;

  case 136: /* expression: expression '<' '<' decimal '>' '>' expression  */
#line 451 "parser.yy"
                                                                      { (yyval.exprval) = new comm_op((yyvsp[-3].ival), (yyvsp[-6].exprval), (yyvsp[0].exprval)); }
#line 2562 "parser.cc"
    break;

  case 137: /* expression: expression '>' expression  */
#line 452 "parser.yy"
                                    { (yyval.exprval) = new greater_than((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2568 "parser.cc"
    break;

  case 138: /* expression: expression '<' expression  */
#line 453 "parser.yy"
                                    { (yyval.exprval) = new less_than((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2574 "parser.cc"
    break;

  case 139: /* expression: expression GE expression  */
#line 454 "parser.yy"
                                   { (yyval.exprval) = new greater_or_equal((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2580 "parser.cc"
    break;

  case 140: /* expression: expression LE expression  */
#line 455 "parser.yy"
                                   { (yyval.exprval) = new less_or_equal((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2586 "parser.cc"
    break;

  case 141: /* expression: expression NE expression  */
#line 456 "parser.yy"
                                   { (yyval.exprval) = new differs((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2592 "parser.cc"
    break;

  case 142: /* expression: expression EQ expression  */
#line 457 "parser.yy"
                                   { (yyval.exprval) = new equals((yyvsp[-2].exprval), (yyvsp[0].exprval)); }
#line 2598 "parser.cc"
    break;

  case 143: /* expression: '(' expression ')'  */
#line 465 "parser.yy"
                             { (yyval.exprval) = (yyvsp[-1].exprval); }
#line 2604 "parser.cc"
    break;

  case 144: /* evaluation: IDENTIFIER  */
#line 476 "parser.yy"
                   { 
		if(!force_lazy) {
			try {
				(yyval.exprval) = function::get_current()->get_symbol((yyvsp[0].strval));
			} catch (std::exception* e) {
				delete e;
				(yyval.exprval) = new lazy_lvalue((yyvsp[0].strval));
			}
		} else {
			(yyval.exprval) = new lazy_lvalue((yyvsp[0].strval));
		}
	}
#line 2621 "parser.cc"
    break;

  case 145: /* evaluation: expression '[' expression ']'  */
#line 488 "parser.yy"
                                                    { 
		if(dynamic_cast<const t_array*>((yyvsp[-3].exprval)->typ())) {
			(yyval.exprval) = array_index((yyvsp[-3].exprval), (yyvsp[-1].exprval));
		} else if((yyvsp[-3].exprval)->typ()->can_deref()) {
			(yyval.exprval) = ptr_index((yyvsp[-3].exprval), (yyvsp[-1].exprval));
		} else throw new runtime_error("Indexing non-indexable type");
		}
#line 2633 "parser.cc"
    break;

  case 146: /* evaluation: '&' expression  */
#line 495 "parser.yy"
                                           { 
		lvalue* l = dynamic_cast<lvalue*>((yyvsp[0].exprval));

		if(!l) throw new runtime_error("Bad dereference");
		(yyval.exprval) = l->refer();
	}
#line 2644 "parser.cc"
    break;

  case 147: /* evaluation: expression PTRFIELD IDENTIFIER  */
#line 501 "parser.yy"
                                         {
		(yyval.exprval) = struct_ptr_field((yyvsp[-2].exprval), (yyvsp[0].strval));
	}
#line 2652 "parser.cc"
    break;

  case 148: /* evaluation: expression '.' IDENTIFIER  */
#line 504 "parser.yy"
                                    {
		lvalue* lv = dynamic_cast<lvalue*>((yyvsp[-2].exprval));
		if(!lv) throw new runtime_error("Bad lvalue");
		(yyval.exprval) = lv->struct_field((yyvsp[0].strval));
	}
#line 2662 "parser.cc"
    break;

  case 149: /* evaluation: '*' expression  */
#line 509 "parser.yy"
                         { (yyval.exprval) = new dereference((yyvsp[0].exprval)); }
#line 2668 "parser.cc"
    break;

  case 150: /* assignment: expression '=' expression  */
#line 519 "parser.yy"
                                  { 
		(yyval.exprval) = new assigner((yyvsp[-2].exprval), (yyvsp[0].exprval)); 
	}
#line 2676 "parser.cc"
    break;

  case 151: /* assignment: expression ADDASSIGN expression  */
#line 525 "parser.yy"
                                          { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new adder((yyvsp[-2].exprval), (yyvsp[0].exprval))); }
#line 2682 "parser.cc"
    break;

  case 152: /* assignment: expression SUBASSIGN expression  */
#line 526 "parser.yy"
                                          { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new adder((yyvsp[-2].exprval), new inverter((yyvsp[0].exprval)))); }
#line 2688 "parser.cc"
    break;

  case 153: /* assignment: expression MULASSIGN expression  */
#line 527 "parser.yy"
                                          { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new mul((yyvsp[-2].exprval), (yyvsp[0].exprval))); }
#line 2694 "parser.cc"
    break;

  case 154: /* assignment: expression ANDASSIGN expression  */
#line 528 "parser.yy"
                                          { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new ander((yyvsp[-2].exprval), (yyvsp[0].exprval))); }
#line 2700 "parser.cc"
    break;

  case 155: /* assignment: expression XORASSIGN expression  */
#line 529 "parser.yy"
                                          { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new orer((yyvsp[-2].exprval), (yyvsp[0].exprval))); }
#line 2706 "parser.cc"
    break;

  case 156: /* assignment: expression ORASSIGN expression  */
#line 530 "parser.yy"
                                         { (yyval.exprval) = auto_assign((yyvsp[-2].exprval), new xorer((yyvsp[-2].exprval), (yyvsp[0].exprval))); }
#line 2712 "parser.cc"
    break;

  case 157: /* assignment: INC expression  */
#line 532 "parser.yy"
                         { (yyval.exprval) = new pre_increment((yyvsp[0].exprval)); }
#line 2718 "parser.cc"
    break;

  case 158: /* assignment: expression INC  */
#line 533 "parser.yy"
                         { (yyval.exprval) = new post_increment((yyvsp[-1].exprval)); }
#line 2724 "parser.cc"
    break;

  case 159: /* assignment: DEC expression  */
#line 534 "parser.yy"
                         { (yyval.exprval) = new pre_decrement((yyvsp[0].exprval)); }
#line 2730 "parser.cc"
    break;

  case 160: /* assignment: expression DEC  */
#line 535 "parser.yy"
                         { (yyval.exprval) = new post_decrement((yyvsp[-1].exprval)); }
#line 2736 "parser.cc"
    break;


#line 2740 "parser.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

