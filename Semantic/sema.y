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
	extern int currnest;
	void deletedata (int );
	int checkscope(char*);
	int check_id_is_func(char *);
	void insertST(char*, char*);
	void insertSTnest(char*, int);
	void insertSTparamscount(char*, int);
	int getSTparamscount(char*);
	int check_duplicate(char*);
	int check_declaration(char*, char *);
	int check_params(char*);
	int duplicate(char *s);
	int checkarray(char*);
	char currfunctype[100];
	char currfunc[100];
	char currfunccall[100];
	void insertSTF(char*);
	char gettype(char*,int);
	char getfirst(char*);
	extern int params_count;
	int call_params_count;


%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT UNION
%token RETURN MAIN
%token VOID
%token WHILE FOR DO
%token BREAK CONTINUE
%token ENDIF
%expect 1

%token IDEN ARRAYIDEN FUNCIDEN
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


%start START

%%
START : DECLAREL;

DECLAREL : DECLARE D

D			: DECLAREL
			| ;

DECLARE		: VDECLARE
					| FDECLARE;

VDECLARE	: TYPE VDECLAREL SEMICOLON ;

VDECLAREL	: VDECLAREL COMMA VDECLAREI
					|	VDECLAREI;

V		: COMMA VDECLAREL
		| ;



VDECLAREI	: IDEN { if(duplicate(CID)){printf("Duplicate\n");exit(0);}insertSTnest(CID,currnest); insert(); } vdi
					|	ARRAYIDEN {if(duplicate(CID)){printf("Duplicate\n");exit(0);}insertSTnest(CID,currnest); insert(); } vdi;


vdi : IDENARRAY
		| ASS EXPR ;

IDENARRAY	: OSB INITPARAM
					| ;

INITPARAM	: INTEGER CSB INIT {if($$ < 1) {printf("Wrong array size\n"); exit(0);} }
					| CSB STRINIT;

INIT	: STRINIT
			| ARRINIT
			| ;


UG		: INT
			| LONG LG
			| SHORT SG
			| ;

SIGNG	: INT
			| LONG LG
			| SHORT SG
			| ;

LG		: INT
			| ;

SG		: INT
			| ;


FDECLARE	: FDECLARETYPE FDECLAREPARAM;

FDECLARETYPE	: TYPE IDEN OP  { strcpy(currfunctype, CTYPE); strcpy(currfunc, CID); check_duplicate(CID); insertSTF(CID);  insert();};

FDECLAREPARAM		: PARAMS CP STATEMENT;

PARAMS	: PARAMLIST
				| ;

PARAMLIST	: TYPE { check_params(CTYPE); }  PARAMIDENL { insertSTparamscount(currfunc, params_count); } ;

PARAMIDENL	: PARAMIDEN PARAMIDENLBR;

PARAMIDENLBR	: COMMA PARAMLIST
							| ;

PARAMIDEN	: IDEN { insert(); insertSTnest(CID,1); params_count++; } PARAMIDENBR;

PARAMIDENBR		: OSB CSB
							| ;

COMPST	: {currnest++;}  OB STATEMENTLIST CB {deletedata(currnest);currnest--;}  ;

STATEMENTLIST	: STATEMENT STATEMENTLIST
							| ;

EXPRST	: EXPR SEMICOLON
				| SEMICOLON ;

CONDST	: IF OP SEXPR CP {if($3!=1){printf("Condition checking is not of type int\n");exit(0);}} STATEMENT CONDSTBR;

CONDSTBR	: ELSE STATEMENT
					| ;

ITER	: WHILE OP SEXPR CP {if($3!=1){printf("Condition checking is not of type int\n");exit(0);}} STATEMENT
			| FOR OP EXPR SEMICOLON SEXPR SEMICOLON {if($5!=1){printf("Condition checking is not of type int\n");exit(0);}} EXPR CP
			| DO STATEMENT WHILE OP SEXPR CP {if($5!=1){printf("Condition checking is not of type int\n");exit(0);}} SEMICOLON;

RETURNS	:	RETURN SEMICOLON {if(strcmp(currfunctype,"void")) {printf("Returning void of a non-void function\n"); exit(0);}}
				| RETURN EXPR SEMICOLON {if(!strcmp(currfunctype, "void")){yyerror("Function is void");} if((currfunctype[0]=='i' || currfunctype[0]=='c') && $2!=1)	{	printf("Expression doesn't match return type of function\n"); exit(0); } };


BREAKS	: BREAKCON SEMICOLON ;

BREAKCON	: BREAK
					| CONTINUE;

STRINIT	: ASS STRING { insertvariable(); };

ARRINIT	: ASS OB ARRINTD CB;

ARRINTD	: INTEGER ARRINTDB;

ARRINTDB	: COMMA ARRINTD
					| ;

EXPR	: MUTABLE ASS EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			| MUTABLE ADDA EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			| MUTABLE SUBA EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			| MUTABLE MULA EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			| MUTABLE DIVA EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			| MUTABLE MODA EXPR {if($1==1 && $3==1)   $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} }
			|	MUTABLE INCRI {if($1 == 1) $$=1; else $$=-1;}
			| MUTABLE DECRI {if($1 == 1) $$=1; else $$=-1;}
			| SEXPR {if($1 == 1) $$=1; else $$=-1;} ;



TYPE	: INT
			| CHAR
			| FLOAT
			| DOUBLE
			| LONG LG
			| SHORT SG
			| UNSIGNED UG
			| SIGNED SIGNG
			| VOID ;

SEXPR	: SEXPR OR ANDEXPR {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| ANDEXPR {if($1 == 1) $$=1; else $$=-1;};


ANDEXPR	: ANDEXPR AND UNARY {if($1 == 1 && $3==1) $$=1; else $$=-1;}
				| UNARY {if($1 == 1) $$=1; else $$=-1;} ;


UNARY	: EXC UNARY {if($2==1) $$=1; else $$=-1;}
			| REXPR {if($1 == 1) $$=1; else $$=-1;} ;

REXPR	: REXPR RELATIONAL SUMEXPR {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| SUMEXPR {if($1 == 1) $$=1; else $$=-1;} ;


RELATIONAL	: GRETHANA
						| LESSTHANA
						| GRETHAN
						| LESSTHAN
						| EQ
						| NEQ ;

SUMEXPR	: SUMEXPR sum_operators TERM {if($1 == 1 && $3==1) $$=1; else $$=-1;}
				| TERM  {if($1 == 1) $$=1; else $$=-1;} ;

sum_operators	: ADD
							| SUB ;

TERM	: TERM MULOP FACTOR {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| FACTOR {if($1 == 1) $$=1; else $$=-1;}  ;

MULOP	: MUL
			| DIV
			| MOD ;

FACTOR	: IMMUTABLE {if($1 == 1) $$=1; else $$=-1;}
				| MUTABLE {if($1 == 1) $$=1; else $$=-1;} ;

MUTABLE	: IDEN { if(check_id_is_func(CID))  {printf("Function name used as Identifier\n"); exit(8);} if(!checkscope(CID))  {printf("%s\n",CID);printf("Undeclared\n");exit(0);} if(!checkarray(CID)) {printf("%s\n",CID );printf("Array ID has no subscript\n");exit(0);} if(gettype(CID,0)=='i' || gettype(CID,1)== 'c') $$ = 1; else $$ = -1;}
				| ARRAYIDEN {if(!checkscope(CID)){printf("%s\n",CID);printf("Undeclared\n");exit(0);}} OSB EXPR CSB  {if(gettype(CID,0)=='i' || gettype(CID,1)== 'c')	$$ = 1;	else	$$ = -1;	};


IMMUTABLE	: OP EXPR CP {if($2==1) $$=1; else $$=-1;}
					| CALL
					| constant {if($1==1) $$=1; else $$=-1;};

CALL	: IDEN OP {if(!check_declaration(CID, "Function")) { printf("Function not declared"); exit(0);} insertSTF(CID); strcpy(currfunccall,CID); }
				ARGUMENTS CP { if(strcmp(currfunccall,"printf")){if(getSTparamscount(currfunccall)!=call_params_count){yyerror("Number of arguments in function call doesn't match number of parameters");
							//printf("Number of arguments in function call %s doesn't match number of parameters\n", currfunccall);
							exit(8);}	}  };


ARGUMENTS	: ARGLIST
					| ;

ARGLIST	: EXPR { call_params_count++; } A;

A	: COMMA EXPR { call_params_count++; } A
	| ;

STATEMENT	: EXPRST
					| COMPST
					| CONDST
					| ITER
					| RETURNS
					| BREAKS
					| VDECLARE;


constant	: INTEGER 	{ insertvariable();  $$=1; }
					| STRING	{ insertvariable();$$=-1; }
					| FLOATC	{ insertvariable(); }
					| CHARACTER{ insertvariable(); $$=1;  };

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
	yyin = fopen("test2.c", "r");
	yyparse();

	if(flag == 0)
	{
		printsymbol();

		printconstant();
	}
}

void yyerror(char *s)
{
	printf("On Line Number %d %s %s\n", yylineno, s, yytext);
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
