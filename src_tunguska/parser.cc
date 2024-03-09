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
#line 21 "parser.yy"

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


#line 89 "parser.cc"

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

#line 195 "parser.cc"

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
  YYSYMBOL_NONTRIP = 3,                    /* NONTRIP  */
  YYSYMBOL_NONSEXT = 4,                    /* NONSEXT  */
  YYSYMBOL_DECIMAL = 5,                    /* DECIMAL  */
  YYSYMBOL_ORG = 6,                        /* ORG  */
  YYSYMBOL_XREG = 7,                       /* XREG  */
  YYSYMBOL_YREG = 8,                       /* YREG  */
  YYSYMBOL_ACCUMULATOR = 9,                /* ACCUMULATOR  */
  YYSYMBOL_EQU = 10,                       /* EQU  */
  YYSYMBOL_DT = 11,                        /* DT  */
  YYSYMBOL_DW = 12,                        /* DW  */
  YYSYMBOL_REST = 13,                      /* REST  */
  YYSYMBOL__INC = 14,                      /* _INC  */
  YYSYMBOL_ENDLINE = 15,                   /* ENDLINE  */
  YYSYMBOL_16_ = 16,                       /* ':'  */
  YYSYMBOL_17_ = 17,                       /* '('  */
  YYSYMBOL_18_ = 18,                       /* ')'  */
  YYSYMBOL_FLOATVAL = 19,                  /* FLOATVAL  */
  YYSYMBOL_IDENTIFIER = 20,                /* IDENTIFIER  */
  YYSYMBOL_COMMENT = 21,                   /* COMMENT  */
  YYSYMBOL_ASMDEBUG = 22,                  /* ASMDEBUG  */
  YYSYMBOL_NEWLINE = 23,                   /* NEWLINE  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_HERE = 25,                      /* HERE  */
  YYSYMBOL_STRING = 26,                    /* STRING  */
  YYSYMBOL_27_ = 27,                       /* '#'  */
  YYSYMBOL_LOW = 28,                       /* LOW  */
  YYSYMBOL_HIGH = 29,                      /* HIGH  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_commands = 37,                  /* commands  */
  YYSYMBOL_command = 38,                   /* command  */
  YYSYMBOL_command_line = 39,              /* command_line  */
  YYSYMBOL_newline = 40,                   /* newline  */
  YYSYMBOL_asmdebug = 41,                  /* asmdebug  */
  YYSYMBOL_comment = 42,                   /* comment  */
  YYSYMBOL_inc = 43,                       /* inc  */
  YYSYMBOL_def_label = 44,                 /* def_label  */
  YYSYMBOL_equ = 45,                       /* equ  */
  YYSYMBOL_rest = 46,                      /* rest  */
  YYSYMBOL_dt = 47,                        /* dt  */
  YYSYMBOL_dtlist = 48,                    /* dtlist  */
  YYSYMBOL_dw = 49,                        /* dw  */
  YYSYMBOL_dwlist = 50,                    /* dwlist  */
  YYSYMBOL_set_origin = 51,                /* set_origin  */
  YYSYMBOL_opcode = 52,                    /* opcode  */
  YYSYMBOL_num = 53,                       /* num  */
  YYSYMBOL_directnum = 54,                 /* directnum  */
  YYSYMBOL_address = 55,                   /* address  */
  YYSYMBOL_addressX = 56,                  /* addressX  */
  YYSYMBOL_addressY = 57,                  /* addressY  */
  YYSYMBOL_indirect = 58,                  /* indirect  */
  YYSYMBOL_indirectX = 59,                 /* indirectX  */
  YYSYMBOL_indirectY = 60,                 /* indirectY  */
  YYSYMBOL_XY = 61                         /* XY  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    27,     2,     2,     2,     2,
      17,    18,    34,    32,    24,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    19,    20,    21,    22,    23,    25,    26,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    53,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    65,    66,    67,    68,    69,    70,    71,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    83,
      84,    85,    86,    87,    89,    90,    91,    94,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   123,   124,   125,   126,   127,   128,   129,   130
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
  "\"end of file\"", "error", "\"invalid token\"", "NONTRIP", "NONSEXT",
  "DECIMAL", "ORG", "XREG", "YREG", "ACCUMULATOR", "EQU", "DT", "DW",
  "REST", "_INC", "ENDLINE", "':'", "'('", "')'", "FLOATVAL", "IDENTIFIER",
  "COMMENT", "ASMDEBUG", "NEWLINE", "','", "HERE", "STRING", "'#'", "LOW",
  "HIGH", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "$accept", "commands",
  "command", "command_line", "newline", "asmdebug", "comment", "inc",
  "def_label", "equ", "rest", "dt", "dtlist", "dw", "dwlist", "set_origin",
  "opcode", "num", "directnum", "address", "addressX", "addressY",
  "indirect", "indirectX", "indirectY", "XY", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,   156,   -31,   130,    -2,    94,   130,   130,   -25,    33,
     -31,   130,   -31,   -31,    12,   -31,   -31,    16,   -31,   174,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   130,   130,   130,   130,   -19,   130,   -31,    17,
     -19,    21,   -19,   -12,   -31,    24,   -31,   130,   -31,   130,
     130,   119,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -19,   -31,    16,   -31,    76,    12,   -31,    16,   -19,   -19,
      -7,    30,   130,   130,   130,   130,   -19,   -31,   112,   130,
     130,    43,   -31,   140,    37,    55,   -19,    60,   -31,   -31,
      16,   -31,   -31,    30,    30,   -31,   -31,   -31,   -19,   -19,
     -19,   -31,    67,    54,   -31,   -31,   -31,   -31,    79,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,    38,
      22,     0,    20,     3,     0,    12,    19,     0,    11,     0,
      15,    16,    17,    18,    14,    13,    49,    50,    48,    51,
      60,    61,     0,     0,     0,     0,    37,     0,    31,    29,
      30,    34,    35,    27,    23,     0,    39,     0,    24,     0,
       0,    63,    41,    42,    43,    44,    45,    46,    47,    40,
      21,     4,     0,     6,    38,     0,    10,     0,    58,    59,
       0,    52,     0,     0,     0,     0,    63,    25,     0,     0,
       0,     0,    26,    63,     0,     0,    62,     0,     5,     7,
       0,     9,    57,    53,    54,    55,    56,    33,    32,    36,
      28,    69,     0,    66,    67,    64,    65,     8,     0,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,    65,    -8,   -31,    -9,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,    -3,   -31,   -30,
      39,   -31,   -31,   -31,   -31,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    39,    23,    41,    24,    25,    51,    52,    53,
      54,    55,    56,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    44,    40,    42,    43,    62,    61,    77,    60,    63,
      67,    66,    80,    72,    73,    74,    75,    82,    37,    84,
      72,    73,    74,    75,    92,    72,    73,    74,    75,    68,
      69,    70,    71,    10,    76,    12,    26,    27,    28,    12,
      45,    78,    46,    47,    76,    79,    83,    86,    81,    48,
      49,   101,    29,    30,    88,   103,    90,    89,    31,    91,
      50,    32,    33,    34,    74,    75,    35,   105,   106,    93,
      94,    95,    96,   104,   105,    98,    99,   100,   108,    26,
      27,    28,   107,    45,    65,    46,    47,   109,    85,     0,
       0,     0,     0,    49,     0,    29,    30,    26,    27,    28,
       0,    31,     0,    50,    32,    33,    34,     0,     0,    35,
       0,     0,     0,    29,    30,    26,    27,    28,     0,    31,
      38,     0,    32,    33,    34,     0,     0,    35,     0,     0,
       0,    29,    30,    26,    27,    28,     0,    31,    97,     0,
      32,    33,    34,    87,     0,    35,     0,     0,     0,    29,
      30,    72,    73,    74,    75,    31,     2,     0,    32,    33,
      34,     0,     3,    35,   102,     0,     4,     5,     6,     7,
       8,     0,    72,    73,    74,    75,     9,    10,    11,    12,
       3,     0,     0,     0,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     0,    64,    10,    11,    12
};

static const yytype_int8 yycheck[] =
{
       3,    26,     5,     6,     7,    14,    14,    37,    11,    17,
      19,    19,    24,    32,    33,    34,    35,    47,    20,    49,
      32,    33,    34,    35,    31,    32,    33,    34,    35,    32,
      33,    34,    35,    21,    37,    23,     3,     4,     5,    23,
       7,    24,     9,    10,    47,    24,    49,    50,    24,    16,
      17,     8,    19,    20,    62,    18,    65,    65,    25,    67,
      27,    28,    29,    30,    34,    35,    33,     7,     8,    72,
      73,    74,    75,    18,     7,    78,    79,    80,    24,     3,
       4,     5,    90,     7,    19,     9,    10,     8,    49,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,     3,     4,     5,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    -1,    33,
      -1,    -1,    -1,    19,    20,     3,     4,     5,    -1,    25,
      26,    -1,    28,    29,    30,    -1,    -1,    33,    -1,    -1,
      -1,    19,    20,     3,     4,     5,    -1,    25,    26,    -1,
      28,    29,    30,    24,    -1,    33,    -1,    -1,    -1,    19,
      20,    32,    33,    34,    35,    25,     0,    -1,    28,    29,
      30,    -1,     6,    33,    24,    -1,    10,    11,    12,    13,
      14,    -1,    32,    33,    34,    35,    20,    21,    22,    23,
       6,    -1,    -1,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,     0,     6,    10,    11,    12,    13,    14,    20,
      21,    22,    23,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,    51,    52,     3,     4,     5,    19,
      20,    25,    28,    29,    30,    33,    53,    20,    26,    48,
      53,    50,    53,    53,    26,     7,     9,    10,    16,    17,
      27,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      53,    40,    42,    40,    20,    39,    40,    42,    53,    53,
      53,    53,    32,    33,    34,    35,    53,    55,    24,    24,
      24,    24,    55,    53,    55,    56,    53,    24,    40,    40,
      42,    40,    31,    53,    53,    53,    53,    26,    53,    53,
      53,     8,    24,    18,    18,     7,     8,    40,    24,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    39,    39,    39,    39,    39,    39,    39,
      40,    41,    42,    43,    44,    45,    45,    46,    46,    47,
      48,    48,    48,    48,    49,    50,    50,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    55,    56,    57,    58,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     2,     3,     4,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     3,     3,     2,     4,     2,
       1,     1,     3,     3,     2,     1,     3,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     2,     1,     3,     3,     3,     3,     5,     3
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
  case 20: /* newline: NEWLINE  */
#line 73 "parser.yy"
                 { assembler::instance()->inc_line(); }
#line 1320 "parser.cc"
    break;

  case 21: /* asmdebug: ASMDEBUG num  */
#line 74 "parser.yy"
                       { printf("@ASMDEBUG(%d)\n", (yyvsp[0].ival)); }
#line 1326 "parser.cc"
    break;

  case 22: /* comment: COMMENT  */
#line 75 "parser.yy"
                 {}
#line 1332 "parser.cc"
    break;

  case 23: /* inc: _INC STRING  */
#line 76 "parser.yy"
                    { assembler::instance()->inc((yyvsp[0].sval)); }
#line 1338 "parser.cc"
    break;

  case 24: /* def_label: IDENTIFIER ':'  */
#line 77 "parser.yy"
                          { assembler::instance()->ldef((yyvsp[-1].sval)); }
#line 1344 "parser.cc"
    break;

  case 25: /* equ: EQU IDENTIFIER address  */
#line 78 "parser.yy"
                              { assembler::instance()->equ((yyvsp[-1].sval), (yyvsp[0].ival)); }
#line 1350 "parser.cc"
    break;

  case 26: /* equ: IDENTIFIER EQU address  */
#line 79 "parser.yy"
                                 { assembler::instance()->equ((yyvsp[-2].sval), (yyvsp[0].ival)); }
#line 1356 "parser.cc"
    break;

  case 27: /* rest: REST num  */
#line 80 "parser.yy"
                 {{int i = 0; for(i = 0; i < (yyvsp[0].ival); i++) assembler::instance()->dt(0); }}
#line 1362 "parser.cc"
    break;

  case 28: /* rest: REST num ',' num  */
#line 81 "parser.yy"
                           {{ int i = 0; for(i = 0; i < (yyvsp[-2].ival); i++) assembler::instance()->dt((yyvsp[0].ival)); }}
#line 1368 "parser.cc"
    break;

  case 30: /* dtlist: num  */
#line 84 "parser.yy"
            { assembler::instance()->dt((yyvsp[0].ival)); }
#line 1374 "parser.cc"
    break;

  case 31: /* dtlist: STRING  */
#line 85 "parser.yy"
                 { assembler::instance()->dtstring((yyvsp[0].sval)); }
#line 1380 "parser.cc"
    break;

  case 32: /* dtlist: dtlist ',' num  */
#line 86 "parser.yy"
                         { assembler::instance()->dt((yyvsp[0].ival)); }
#line 1386 "parser.cc"
    break;

  case 33: /* dtlist: dtlist ',' STRING  */
#line 87 "parser.yy"
                            { assembler::instance()->dtstring((yyvsp[0].sval)); }
#line 1392 "parser.cc"
    break;

  case 35: /* dwlist: num  */
#line 90 "parser.yy"
            { assembler::instance()->dw((yyvsp[0].ival)); }
#line 1398 "parser.cc"
    break;

  case 36: /* dwlist: dwlist ',' num  */
#line 91 "parser.yy"
                         { assembler::instance()->dw((yyvsp[0].ival)); }
#line 1404 "parser.cc"
    break;

  case 37: /* set_origin: ORG num  */
#line 94 "parser.yy"
                    { assembler::instance()->org((yyvsp[0].ival)); }
#line 1410 "parser.cc"
    break;

  case 38: /* opcode: IDENTIFIER  */
#line 96 "parser.yy"
                   { assembler::instance()->addop((yyvsp[0].sval), OP_IMPLICIT, 0); }
#line 1416 "parser.cc"
    break;

  case 39: /* opcode: IDENTIFIER ACCUMULATOR  */
#line 97 "parser.yy"
                                 { assembler::instance()->addop((yyvsp[-1].sval), OP_ACC, 0); }
#line 1422 "parser.cc"
    break;

  case 40: /* opcode: IDENTIFIER XY  */
#line 98 "parser.yy"
                        { assembler::instance()->addop((yyvsp[-1].sval), OP_XY, 0); }
#line 1428 "parser.cc"
    break;

  case 41: /* opcode: IDENTIFIER directnum  */
#line 99 "parser.yy"
                               { assembler::instance()->addop((yyvsp[-1].sval), OP_IMMEDIATE, (yyvsp[0].ival)); }
#line 1434 "parser.cc"
    break;

  case 42: /* opcode: IDENTIFIER address  */
#line 100 "parser.yy"
                             { assembler::instance()->addop((yyvsp[-1].sval), OP_ABSOLUTE, (yyvsp[0].ival)); }
#line 1440 "parser.cc"
    break;

  case 43: /* opcode: IDENTIFIER addressX  */
#line 101 "parser.yy"
                              { assembler::instance()->addop((yyvsp[-1].sval), OP_ABSOLUTE_X, (yyvsp[0].ival)); }
#line 1446 "parser.cc"
    break;

  case 44: /* opcode: IDENTIFIER addressY  */
#line 102 "parser.yy"
                              { assembler::instance()->addop((yyvsp[-1].sval), OP_ABSOLUTE_Y, (yyvsp[0].ival)); }
#line 1452 "parser.cc"
    break;

  case 45: /* opcode: IDENTIFIER indirect  */
#line 103 "parser.yy"
                              { assembler::instance()->addop((yyvsp[-1].sval), OP_INDIRECT, (yyvsp[0].ival)); }
#line 1458 "parser.cc"
    break;

  case 46: /* opcode: IDENTIFIER indirectX  */
#line 104 "parser.yy"
                               { assembler::instance()->addop((yyvsp[-1].sval), OP_INDIRECT_X, (yyvsp[0].ival)); }
#line 1464 "parser.cc"
    break;

  case 47: /* opcode: IDENTIFIER indirectY  */
#line 105 "parser.yy"
                               { assembler::instance()->addop((yyvsp[-1].sval), OP_INDIRECT_Y, (yyvsp[0].ival)); }
#line 1470 "parser.cc"
    break;

  case 48: /* num: DECIMAL  */
#line 108 "parser.yy"
                  { (yyval.ival) = (yyvsp[0].ival); }
#line 1476 "parser.cc"
    break;

  case 49: /* num: NONTRIP  */
#line 109 "parser.yy"
                  { (yyval.ival) = nontriplet((yyvsp[0].sval)); }
#line 1482 "parser.cc"
    break;

  case 50: /* num: NONSEXT  */
#line 110 "parser.yy"
                  { (yyval.ival) = nonsextet((yyvsp[0].sval)); }
#line 1488 "parser.cc"
    break;

  case 51: /* num: FLOATVAL  */
#line 111 "parser.yy"
                   { (yyval.ival) = floatval((yyvsp[0].sval)); }
#line 1494 "parser.cc"
    break;

  case 52: /* num: '-' num  */
#line 112 "parser.yy"
                  { (yyval.ival) = - (yyvsp[0].ival); }
#line 1500 "parser.cc"
    break;

  case 53: /* num: num '+' num  */
#line 113 "parser.yy"
                      { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1506 "parser.cc"
    break;

  case 54: /* num: num '-' num  */
#line 114 "parser.yy"
                      { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1512 "parser.cc"
    break;

  case 55: /* num: num '*' num  */
#line 115 "parser.yy"
                      { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1518 "parser.cc"
    break;

  case 56: /* num: num '/' num  */
#line 116 "parser.yy"
                      { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
#line 1524 "parser.cc"
    break;

  case 57: /* num: '{' num '}'  */
#line 117 "parser.yy"
                      { (yyval.ival) = (yyvsp[-1].ival); }
#line 1530 "parser.cc"
    break;

  case 58: /* num: LOW num  */
#line 118 "parser.yy"
                  { (yyval.ival) = lowtryte((yyvsp[0].ival)); }
#line 1536 "parser.cc"
    break;

  case 59: /* num: HIGH num  */
#line 119 "parser.yy"
                  { (yyval.ival) = hightryte((yyvsp[0].ival)); }
#line 1542 "parser.cc"
    break;

  case 60: /* num: IDENTIFIER  */
#line 120 "parser.yy"
                     { (yyval.ival) = assembler::instance()->label_eval((yyvsp[0].sval)); }
#line 1548 "parser.cc"
    break;

  case 61: /* num: HERE  */
#line 121 "parser.yy"
               { (yyval.ival) = assembler::instance()->get_pc(); }
#line 1554 "parser.cc"
    break;

  case 62: /* directnum: '#' num  */
#line 123 "parser.yy"
                   { (yyval.ival) = (yyvsp[0].ival); }
#line 1560 "parser.cc"
    break;

  case 63: /* address: num  */
#line 124 "parser.yy"
             { (yyval.ival) = (yyvsp[0].ival); }
#line 1566 "parser.cc"
    break;

  case 64: /* addressX: num ',' XREG  */
#line 125 "parser.yy"
                       { (yyval.ival) = (yyvsp[-2].ival); }
#line 1572 "parser.cc"
    break;

  case 65: /* addressY: num ',' YREG  */
#line 126 "parser.yy"
                       { (yyval.ival) = (yyvsp[-2].ival); }
#line 1578 "parser.cc"
    break;

  case 66: /* indirect: '(' address ')'  */
#line 127 "parser.yy"
                          { (yyval.ival) = (yyvsp[-1].ival); }
#line 1584 "parser.cc"
    break;

  case 67: /* indirectX: '(' addressX ')'  */
#line 128 "parser.yy"
                            { (yyval.ival) = (yyvsp[-1].ival); }
#line 1590 "parser.cc"
    break;

  case 68: /* indirectY: '(' address ')' ',' YREG  */
#line 129 "parser.yy"
                                    { (yyval.ival) = (yyvsp[-3].ival); }
#line 1596 "parser.cc"
    break;

  case 69: /* XY: XREG ',' YREG  */
#line 130 "parser.yy"
                  {}
#line 1602 "parser.cc"
    break;


#line 1606 "parser.cc"

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

