/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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

#line 167 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
