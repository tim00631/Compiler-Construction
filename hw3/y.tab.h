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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    RETURN = 262,
    SEMICOLON = 263,
    PRINT = 264,
    ADDASGN = 265,
    SUBASGN = 266,
    MULASGN = 267,
    DIVASGN = 268,
    MODASGN = 269,
    INC = 270,
    DEC = 271,
    MTE = 272,
    LTE = 273,
    EQ = 274,
    NE = 275,
    VOID = 276,
    INT = 277,
    FLOAT = 278,
    BOOL = 279,
    STRING = 280,
    TRUE = 281,
    FALSE = 282,
    I_CONST = 283,
    F_CONST = 284,
    STR_CONST = 285,
    ID = 286
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define RETURN 262
#define SEMICOLON 263
#define PRINT 264
#define ADDASGN 265
#define SUBASGN 266
#define MULASGN 267
#define DIVASGN 268
#define MODASGN 269
#define INC 270
#define DEC 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define VOID 276
#define INT 277
#define FLOAT 278
#define BOOL 279
#define STRING 280
#define TRUE 281
#define FALSE 282
#define I_CONST 283
#define F_CONST 284
#define STR_CONST 285
#define ID 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "compiler_hw3.y" /* yacc.c:1909  */

    Value val;
    Operator op;

#line 121 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
