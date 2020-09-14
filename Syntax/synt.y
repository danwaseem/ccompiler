%{
	void yyerror(char* s);
	int yylex();
	#include "stdio.h"
	#include "stdlib.h"
	#include "ctype.h"
	#include "string.h"
	void insert();
	void insertvariable();
	int flag=0;

	extern char CID[20];
	extern char CTYPE[20];
	extern char CVAL[20];

%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO
%token BREAK
%token ENDIF
%expect 2

%token IDEN
%token INTEGER STRING FLOATC CHARACTER
%token SEMICOLON COMMA
%token OP CP OB CB OSB CSB
%token COLON FULLSTOP
%nonassoc ELSE

%right LSHIFT RSHIFT
%right XORA ORA
%right ANDA MODA
%right MULA DIVA
%right ADDA SUBA
%right ASS

%left OR
%left AND
%left PIPE
%left UP
%left SAND
%left EQ NEQ
%left LESSTHANA LESSTHAN GRETHANA GRETHAN
%left LEFTSHIFT RIGHTSHIFT
%left ADD SUB
%left MUL DIV MOD

%right SIZEOF
%right QUO EXC
%left INCRI DECRI


%start program

%%
program
			: DECLAREL;

DECLAREL
			: DECLARE D

D
			: DECLAREL
			| ;

DECLARE
			: VDECLARE
			| FDECLARE
			| SDEFINE;

VDECLARE
			: TYPE VDECLAREL SEMICOLON
			| SDECLARE;

VDECLAREL
			: VDECLAREI V;

V
			: COMMA VDECLAREL
			| ;

VDECLAREI
			: IDEN { insert(); } vdi;

vdi : IDENARRAY | ASS EXPR ;

IDENARRAY
			: OSB INITPARAM
			| ;

INITPARAM
			: INTEGER CSB INIT
			| CSB STRINIT;

INIT
			: STRINIT
			| ARRINIT
			| ;

TYPE
			: INT | CHAR | FLOAT | DOUBLE
			| LONG LG
			| SHORT SG
			| UNSIGNED UG
			| SIGNED SIGNG
			| VOID ;

UG
			: INT | LONG LG | SHORT SG | ;

SIGNG
			: INT | LONG LG | SHORT SG | ;

LG
			: INT | ;

SG
			: INT | ;

SDEFINE
			: STRUCT IDEN { insert(); } OB V1  CB SEMICOLON;

V1 : VDECLARE V1 | ;

SDECLARE
			: STRUCT IDEN VDECLAREL;


FDECLARE
			: FDECLARETYPE FDECLAREPARAM;

FDECLARETYPE
			: TYPE IDEN OP  { insert();};

FDECLAREPARAM
			: PARAMS CP STATEMENT;

PARAMS
			: PARAMLIST | ;

PARAMLIST
			: TYPE PARAMIDENL;

PARAMIDENL
			: PARAMIDEN PARAMIDENLBR;

PARAMIDENLBR
			: COMMA PARAMLIST
			| ;

PARAMIDEN
			: IDEN { insert(); } PARAMIDENBR;

PARAMIDENBR
			: OSB CSB
			| ;

STATEMENT
			: EXPRST | COMPST
			| CONDST | ITER
			| RETURNS | BREAKS
			| VDECLARE;

COMPST
			: OB STATEMENTLIST CB ;

STATEMENTLIST
			: STATEMENT STATEMENTLIST
			| ;

EXPRST
			: EXPR SEMICOLON
			| SEMICOLON ;

CONDST
			: IF OP SEXPR CP STATEMENT CONDSTBR;

CONDSTBR
			: ELSE STATEMENT
			| ;

ITER
			: WHILE OP SEXPR CP STATEMENT
			| FOR OP EXPR SEMICOLON SEXPR SEMICOLON EXPR CP
			| DO STATEMENT WHILE OP SEXPR CP SEMICOLON;

RETURNS
			: RETURN RETURNB;

RETURNB
			: SEMICOLON
			| EXPR SEMICOLON ;

BREAKS
			: BREAK SEMICOLON ;

STRINIT
			: ASS STRING { insertvariable(); };

ARRINIT
			: ASS OB ARRINTD CB;

ARRINTD
			: INTEGER ARRINTDB;

ARRINTDB
			: COMMA ARRINTD
			| ;

EXPR
			: MUTABLE EXPRBR
			| SEXPR ;

EXPRBR
			: ASS EXPR
			| ADDA EXPR
			| SUBA EXPR
			| MULA EXPR
			| DIVA EXPR
			| MODA EXPR
			| INCRI
			| DECRI ;

SEXPR
			: ANDEXPR SEXPB;

SEXPB
			: OR ANDEXPR SEXPB | ;

ANDEXPR
			: UNARY ANDEXPRBR;

ANDEXPRBR
			: AND UNARY ANDEXPRBR
			| ;

UNARY
			: EXC UNARY
			| REXPR ;

REXPR
			: SUMEXPR REXPRBR;

REXPRBR
			: RELATIONAL SUMEXPR
			| ;

RELATIONAL
			: GRETHANA | LESSTHANA | GRETHAN
			| LESSTHAN | EQ | NEQ ;

SUMEXPR
			: SUMEXPR sum_operators TERM
			| TERM ;

sum_operators
			: ADD
			| SUB ;

TERM
			: TERM MULOP FACTOR
			| FACTOR ;

MULOP
			: MUL | DIV | MOD ;

FACTOR
			: IMMUTABLE | MUTABLE ;

MUTABLE
			: IDEN
			| MUTABLE MUTABLEBR;

MUTABLEBR
			: OSB EXPR CSB
			| FULLSTOP IDEN;

IMMUTABLE
			: OP EXPR CP
			| CALL | constant;

CALL
			: IDEN OP ARGUMENTS CP;

ARGUMENTS
			: ARGLIST | ;

ARGLIST
			: EXPR A;

A
			: COMMA EXPR A
			| ;

constant
			: INTEGER 	{ insertvariable(); }
			| STRING	{ insertvariable(); }
			| FLOATC	{ insertvariable(); }
			| CHARACTER{ insertvariable(); };

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSymboltype(char *,char *);
void insertSymbolvalue(char *, char *);
void incertconstant(char *, char *);
void printsymbol();
void printconstant();

int main()
{
	yyin = fopen("test1.c", "r");
	yyparse();

	if(flag == 0)
	{
		printf("\n\n\n*****SYMBOL TABLE*****\n\n\n");
		printsymbol();

		printf("\n\n\n*****CONSTANT TABLE*****\n\n\n");
		printconstant();
	}
}

void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf("Parsing Failed\n");
}

void insert()
{
	insertSymboltype(CID,CTYPE);
}

void insertvariable()
{
	insertSymbolvalue(CID,CVAL);
}

int yywrap()
{
	return 1;
}
