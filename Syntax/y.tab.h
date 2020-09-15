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
    INTEGER = 279,
    STRING = 280,
    FLOATC = 281,
    CHARACTER = 282,
    SEMICOLON = 283,
    COMMA = 284,
    OP = 285,
    CP = 286,
    OB = 287,
    CB = 288,
    OSB = 289,
    CSB = 290,
    COLON = 291,
    FULLSTOP = 292,
    ELSE = 293,
    LSHIFT = 294,
    RSHIFT = 295,
    XORA = 296,
    ORA = 297,
    ANDA = 298,
    MODA = 299,
    MULA = 300,
    DIVA = 301,
    ADDA = 302,
    SUBA = 303,
    ASS = 304,
    OR = 305,
    AND = 306,
    PIPE = 307,
    UP = 308,
    SAND = 309,
    EQ = 310,
    NEQ = 311,
    LESSTHANA = 312,
    LESSTHAN = 313,
    GRETHANA = 314,
    GRETHAN = 315,
    LEFTSHIFT = 316,
    RIGHTSHIFT = 317,
    ADD = 318,
    SUB = 319,
    MUL = 320,
    DIV = 321,
    MOD = 322,
    SIZEOF = 323,
    QUO = 324,
    EXC = 325,
    INCRI = 326,
    DECRI = 327
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
#define INTEGER 279
#define STRING 280
#define FLOATC 281
#define CHARACTER 282
#define SEMICOLON 283
#define COMMA 284
#define OP 285
#define CP 286
#define OB 287
#define CB 288
#define OSB 289
#define CSB 290
#define COLON 291
#define FULLSTOP 292
#define ELSE 293
#define LSHIFT 294
#define RSHIFT 295
#define XORA 296
#define ORA 297
#define ANDA 298
#define MODA 299
#define MULA 300
#define DIVA 301
#define ADDA 302
#define SUBA 303
#define ASS 304
#define OR 305
#define AND 306
#define PIPE 307
#define UP 308
#define SAND 309
#define EQ 310
#define NEQ 311
#define LESSTHANA 312
#define LESSTHAN 313
#define GRETHANA 314
#define GRETHAN 315
#define LEFTSHIFT 316
#define RIGHTSHIFT 317
#define ADD 318
#define SUB 319
#define MUL 320
#define DIV 321
#define MOD 322
#define SIZEOF 323
#define QUO 324
#define EXC 325
#define INCRI 326
#define DECRI 327

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
