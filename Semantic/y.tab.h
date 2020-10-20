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
    IF = 258,
    INT = 259,
    CHAR = 260,
    FLOAT = 261,
    DOUBLE = 262,
    LONG = 263,
    SHORT = 264,
    SIGNED = 265,
    UNSIGNED = 266,
    STRUCT = 267,
    UNION = 268,
    RETURN = 269,
    MAIN = 270,
    VOID = 271,
    WHILE = 272,
    FOR = 273,
    DO = 274,
    BREAK = 275,
    CONTINUE = 276,
    ENDIF = 277,
    IDEN = 278,
    ARRAYIDEN = 279,
    FUNCIDEN = 280,
    INTEGER = 281,
    STRING = 282,
    FLOATC = 283,
    CHARACTER = 284,
    SEMICOLON = 285,
    COMMA = 286,
    OP = 287,
    CP = 288,
    OB = 289,
    CB = 290,
    OSB = 291,
    CSB = 292,
    COLON = 293,
    FULLSTOP = 294,
    ELSE = 295,
    LSHIFT = 296,
    RSHIFT = 297,
    XORA = 298,
    ORA = 299,
    ANDA = 300,
    MODA = 301,
    MULA = 302,
    DIVA = 303,
    ADDA = 304,
    SUBA = 305,
    ASS = 306,
    OR = 307,
    AND = 308,
    PIPE = 309,
    UP = 310,
    SAND = 311,
    EQ = 312,
    NEQ = 313,
    LESSTHANA = 314,
    LESSTHAN = 315,
    GRETHANA = 316,
    GRETHAN = 317,
    LEFTSHIFT = 318,
    RIGHTSHIFT = 319,
    ADD = 320,
    SUB = 321,
    MUL = 322,
    DIV = 323,
    MOD = 324,
    SIZEOF = 325,
    QUO = 326,
    EXC = 327,
    INCRI = 328,
    DECRI = 329
  };
#endif
/* Tokens.  */
#define IF 258
#define INT 259
#define CHAR 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define SHORT 264
#define SIGNED 265
#define UNSIGNED 266
#define STRUCT 267
#define UNION 268
#define RETURN 269
#define MAIN 270
#define VOID 271
#define WHILE 272
#define FOR 273
#define DO 274
#define BREAK 275
#define CONTINUE 276
#define ENDIF 277
#define IDEN 278
#define ARRAYIDEN 279
#define FUNCIDEN 280
#define INTEGER 281
#define STRING 282
#define FLOATC 283
#define CHARACTER 284
#define SEMICOLON 285
#define COMMA 286
#define OP 287
#define CP 288
#define OB 289
#define CB 290
#define OSB 291
#define CSB 292
#define COLON 293
#define FULLSTOP 294
#define ELSE 295
#define LSHIFT 296
#define RSHIFT 297
#define XORA 298
#define ORA 299
#define ANDA 300
#define MODA 301
#define MULA 302
#define DIVA 303
#define ADDA 304
#define SUBA 305
#define ASS 306
#define OR 307
#define AND 308
#define PIPE 309
#define UP 310
#define SAND 311
#define EQ 312
#define NEQ 313
#define LESSTHANA 314
#define LESSTHAN 315
#define GRETHANA 316
#define GRETHAN 317
#define LEFTSHIFT 318
#define RIGHTSHIFT 319
#define ADD 320
#define SUB 321
#define MUL 322
#define DIV 323
#define MOD 324
#define SIZEOF 325
#define QUO 326
#define EXC 327
#define INCRI 328
#define DECRI 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
