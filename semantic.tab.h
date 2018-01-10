/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_SEMANTIC_TAB_H_INCLUDED
# define YY_YY_SEMANTIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

#include "attribs.h"
#include "intermediate_code.c"
#include "symbols.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    INT = 260,
    PRINT = 261,
    VOID = 262,
    IF = 263,
    WHILE = 264,
    BREAK = 265,
    PYC = 266,
    LKEY = 267,
    RKEY = 268,
    TRUE = 269,
    FALSE = 270,
    FLOAT = 271,
    DOUBLE = 272,
    CHAR = 273,
    SWITCH = 274,
    FOR = 275,
    FUNC = 276,
    DEFAULT = 277,
    RETURN = 278,
    STRUCT = 279,
    RLC = 280,
    LLC = 281,
    SC = 282,
    COMMA = 283,
    LBRACK = 284,
    RBRACK = 285,
    GTE = 286,
    LTE = 287,
    ASIG = 288,
    OR = 289,
    AND = 290,
    EQUAL = 291,
    NE = 292,
    GT = 293,
    LT = 294,
    ADD = 295,
    SUB = 296,
    MUL = 297,
    DIV = 298,
    RPAR = 299,
    LPAR = 300,
    IFX = 301,
    ELSE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "semantic.y" /* yacc.c:1909  */

    char sval[32];
    char ssval[3];
    expresion eval;
    condition cval;  
    sentence stval;
    int nval;
    int line;
    type tval;
    arrayType arrtval;

 

#line 116 "semantic.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */
