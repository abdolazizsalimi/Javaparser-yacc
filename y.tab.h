/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    id = 258,
    STRING_LITERAL = 259,
    INTEGER_LITERAL = 260,
    op = 261,
    FOR = 262,
    CLASS = 263,
    PUBLIC = 264,
    STATIC = 265,
    VOID = 266,
    MAIN = 267,
    STRING = 268,
    EXTENDS = 269,
    RETURN = 270,
    INT = 271,
    BOOLEAN = 272,
    IF = 273,
    ELSE = 274,
    WHILE = 275,
    PRINT = 276,
    LENGTH = 277,
    TRUE = 278,
    FALSE = 279,
    THIS = 280,
    NEW = 281
  };
#endif
/* Tokens.  */
#define id 258
#define STRING_LITERAL 259
#define INTEGER_LITERAL 260
#define op 261
#define FOR 262
#define CLASS 263
#define PUBLIC 264
#define STATIC 265
#define VOID 266
#define MAIN 267
#define STRING 268
#define EXTENDS 269
#define RETURN 270
#define INT 271
#define BOOLEAN 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define PRINT 276
#define LENGTH 277
#define TRUE 278
#define FALSE 279
#define THIS 280
#define NEW 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
