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
    NONTRIP = 258,                 /* NONTRIP  */
    NONSEXT = 259,                 /* NONSEXT  */
    DECIMAL = 260,                 /* DECIMAL  */
    ORG = 261,                     /* ORG  */
    XREG = 262,                    /* XREG  */
    YREG = 263,                    /* YREG  */
    ACCUMULATOR = 264,             /* ACCUMULATOR  */
    EQU = 265,                     /* EQU  */
    DT = 266,                      /* DT  */
    DW = 267,                      /* DW  */
    REST = 268,                    /* REST  */
    _INC = 269,                    /* _INC  */
    ENDLINE = 270,                 /* ENDLINE  */
    FLOATVAL = 271,                /* FLOATVAL  */
    IDENTIFIER = 272,              /* IDENTIFIER  */
    COMMENT = 273,                 /* COMMENT  */
    ASMDEBUG = 274,                /* ASMDEBUG  */
    NEWLINE = 275,                 /* NEWLINE  */
    HERE = 276,                    /* HERE  */
    STRING = 277,                  /* STRING  */
    LOW = 278,                     /* LOW  */
    HIGH = 279                     /* HIGH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NONTRIP 258
#define NONSEXT 259
#define DECIMAL 260
#define ORG 261
#define XREG 262
#define YREG 263
#define ACCUMULATOR 264
#define EQU 265
#define DT 266
#define DW 267
#define REST 268
#define _INC 269
#define ENDLINE 270
#define FLOATVAL 271
#define IDENTIFIER 272
#define COMMENT 273
#define ASMDEBUG 274
#define NEWLINE 275
#define HERE 276
#define STRING 277
#define LOW 278
#define HIGH 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.yy"

	char* sval;
	int ival;

#line 120 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
