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
    STRING = 259,
    CHARACTER = 260,
    NUM = 261,
    NUMR = 262,
    NOT = 263,
    INT = 264,
    PRINT = 265,
    VOID = 266,
    IF = 267,
    WHILE = 268,
    BREAK = 269,
    PYC = 270,
    LKEY = 271,
    RKEY = 272,
    TRUE = 273,
    FALSE = 274,
    FLOAT = 275,
    CHAR = 276,
    SWITCH = 277,
    FOR = 278,
    FUNC = 279,
    DEFAULT = 280,
    RETURN = 281,
    STRUCT = 282,
    RLC = 283,
    LLC = 284,
    SC = 285,
    COMMA = 286,
    LBRACK = 287,
    RBRACK = 288,
    GTE = 289,
    LTE = 290,
    ASIG = 291,
    OR = 292,
    AND = 293,
    EQUAL = 294,
    NE = 295,
    GT = 296,
    LT = 297,
    ADD = 298,
    SUB = 299,
    MOD = 300,
    MUL = 301,
    DIV = 302,
    RPAR = 303,
    LPAR = 304,
    IFX = 305,
    ELSE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 47 "semantic.y" /* yacc.c:1909  */

    char sval[32];
    char ssval[3];
    expresion eval;
    condition cval;  
    sentence stval;
    int nval;
    float fval;
    int line;
    type tval;
    arrayType arrtval;
    char charval;
    NodeParam paramlistval;
 

#line 122 "semantic.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */
