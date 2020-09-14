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
    RETURN = 268,
    MAIN = 269,
    VOID = 270,
    WHILE = 271,
    FOR = 272,
    DO = 273,
    BREAK = 274,
    ENDIF = 275,
    IDEN = 276,
    INTEGER = 277,
    STRING = 278,
    FLOATC = 279,
    CHARACTER = 280,
    SEMICOLON = 281,
    COMMA = 282,
    OP = 283,
    CP = 284,
    OB = 285,
    CB = 286,
    OSB = 287,
    CSB = 288,
    COLON = 289,
    FULLSTOP = 290,
    ELSE = 291,
    LSHIFT = 292,
    RSHIFT = 293,
    XORA = 294,
    ORA = 295,
    ANDA = 296,
    MODA = 297,
    MULA = 298,
    DIVA = 299,
    ADDA = 300,
    SUBA = 301,
    ASS = 302,
    OR = 303,
    AND = 304,
    PIPE = 305,
    UP = 306,
    SAND = 307,
    EQ = 308,
    NEQ = 309,
    LESSTHANA = 310,
    LESSTHAN = 311,
    GRETHANA = 312,
    GRETHAN = 313,
    LEFTSHIFT = 314,
    RIGHTSHIFT = 315,
    ADD = 316,
    SUB = 317,
    MUL = 318,
    DIV = 319,
    MOD = 320,
    SIZEOF = 321,
    QUO = 322,
    EXC = 323,
    INCRI = 324,
    DECRI = 325
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
#define RETURN 268
#define MAIN 269
#define VOID 270
#define WHILE 271
#define FOR 272
#define DO 273
#define BREAK 274
#define ENDIF 275
#define IDEN 276
#define INTEGER 277
#define STRING 278
#define FLOATC 279
#define CHARACTER 280
#define SEMICOLON 281
#define COMMA 282
#define OP 283
#define CP 284
#define OB 285
#define CB 286
#define OSB 287
#define CSB 288
#define COLON 289
#define FULLSTOP 290
#define ELSE 291
#define LSHIFT 292
#define RSHIFT 293
#define XORA 294
#define ORA 295
#define ANDA 296
#define MODA 297
#define MULA 298
#define DIVA 299
#define ADDA 300
#define SUBA 301
#define ASS 302
#define OR 303
#define AND 304
#define PIPE 305
#define UP 306
#define SAND 307
#define EQ 308
#define NEQ 309
#define LESSTHANA 310
#define LESSTHAN 311
#define GRETHANA 312
#define GRETHAN 313
#define LEFTSHIFT 314
#define RIGHTSHIFT 315
#define ADD 316
#define SUB 317
#define MUL 318
#define DIV 319
#define MOD 320
#define SIZEOF 321
#define QUO 322
#define EXC 323
#define INCRI 324
#define DECRI 325

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
