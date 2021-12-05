
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     INT = 259,
     ID = 260,
     WHILE = 261,
     PARAB = 262,
     PARCE = 263,
     CORAB = 264,
     CORCE = 265,
     OP_MAY = 266,
     IF = 267,
     ELSE = 268,
     OP_AS = 269,
     DIM = 270,
     AS = 271,
     COMA = 272,
     STRINGT = 273,
     INTEGER = 274,
     REAL = 275,
     CUAAB = 276,
     CUACE = 277,
     FOR = 278,
     TO = 279,
     NEXT = 280,
     EQUMAX = 281,
     EQUMIN = 282,
     FIN = 283,
     OP_MEN = 284,
     OP_MAYIGU = 285,
     OP_MENIGU = 286,
     OP_IGU = 287,
     OP_DIST = 288,
     DISPLAY = 289,
     GET = 290,
     NOT = 291,
     AND = 292,
     OR = 293,
     REA = 294,
     MAS = 295,
     MENOS = 296,
     POR = 297,
     DIV = 298,
     CONSTANT = 299
   };
#endif
/* Tokens.  */
#define STRING 258
#define INT 259
#define ID 260
#define WHILE 261
#define PARAB 262
#define PARCE 263
#define CORAB 264
#define CORCE 265
#define OP_MAY 266
#define IF 267
#define ELSE 268
#define OP_AS 269
#define DIM 270
#define AS 271
#define COMA 272
#define STRINGT 273
#define INTEGER 274
#define REAL 275
#define CUAAB 276
#define CUACE 277
#define FOR 278
#define TO 279
#define NEXT 280
#define EQUMAX 281
#define EQUMIN 282
#define FIN 283
#define OP_MEN 284
#define OP_MAYIGU 285
#define OP_MENIGU 286
#define OP_IGU 287
#define OP_DIST 288
#define DISPLAY 289
#define GET 290
#define NOT 291
#define AND 292
#define OR 293
#define REA 294
#define MAS 295
#define MENOS 296
#define POR 297
#define DIV 298
#define CONSTANT 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 88 "Sintactico.y"

    char name[20];
    int num;



/* Line 1676 of yacc.c  */
#line 147 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


