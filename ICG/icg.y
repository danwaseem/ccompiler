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
	void push(char *s);
	void codegen();
	void codeassign();
	char* itoa(int num, char* str, int base);
	void reverse(char str[], int length);
	void swap(char*,char*);
	void label1();
	void label2();
	void label3();
	void label4();
	void label5();
	void label6();
	void genunary();
	void codegencon();
	void funcgen();
	void funcgenend();
	void arggen();
	void callgen();
	int params_count=0;
	int call_params_count=0;

	int top = 0,count=0,ltop=0,lno=0;
	char temp[3] = "t";


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

FDECLAREPARAM		: {params_count=0;} PARAMS CP {funcgen();} STATEMENT {funcgenend();};

PARAMS	: PARAMLIST { insertSTparamscount(currfunc, params_count); }
				| { insertSTparamscount(currfunc, params_count); } ;

PARAMLIST	: TYPE { check_params(CTYPE); }  PARAMIDENL ;

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

CONDST	: IF OP SEXPR CP {label1(); if($3!=1){printf("Condition checking is not of type int\n");exit(0);}} STATEMENT {label2();} CONDSTBR;

CONDSTBR	: ELSE STATEMENT {label3();}
					| {label3();} ;

ITER	: WHILE OP  {label4();} SEXPR CP {label1(); if($4!=1){printf("Condition checking is not of type int\n");exit(0);}} STATEMENT {label5();}
			| FOR OP EXPR SEMICOLON {label4();} SEXPR SEMICOLON {label1(); if($6!=1){printf("Condition checking is not of type int\n");exit(0);}} EXPR CP STATEMENT {label5();}
			| {label4();} DO STATEMENT WHILE OP SEXPR CP {label1();label5(); if($6!=1){printf("Condition checking is not of type int\n");exit(0);}} SEMICOLON;

RETURNS	:	RETURN SEMICOLON {if(strcmp(currfunctype,"void")) {printf("Returning void of a non-void function\n"); exit(0);}}
				| RETURN EXPR SEMICOLON {if(!strcmp(currfunctype, "void")){yyerror("Function is void\n");} if((currfunctype[0]=='i' || currfunctype[0]=='c') && $2!=1)	{	printf("Expression doesn't match return type of function\n"); exit(0); } };


BREAKS	: BREAKCON SEMICOLON ;

BREAKCON	: BREAK
					| CONTINUE;

STRINIT	: ASS STRING { insertvariable(); };

ARRINIT	: ASS OB ARRINTD CB;

ARRINTD	: INTEGER ARRINTDB;

ARRINTDB	: COMMA ARRINTD
					| ;

EXPR	: MUTABLE ASS {push("=");} EXPR {if($1==1 && $4==1)  { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			| MUTABLE ADDA {push("+=");} EXPR {if($1==1 && $4==1)  { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			| MUTABLE SUBA {push("-=");} EXPR {if($1==1 && $4==1)   { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			| MUTABLE MULA {push("*=");} EXPR {if($1==1 && $4==1)  { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			| MUTABLE DIVA {push("/=");} EXPR {if($1==1 && $4==1)  { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			| MUTABLE MODA {push("%=");} EXPR {if($1==1 && $3==1)  { $$=1; } else  {$$=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
			|	MUTABLE INCRI {push("++"); if($1 == 1) $$=1; else $$=-1; genunary(); }
			| MUTABLE DECRI {push("--"); if($1 == 1) $$=1; else $$=-1;}
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

SEXPR	: SEXPR OR ANDEXPR {push("||");} {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen(); }
			| ANDEXPR {if($1 == 1) $$=1; else $$=-1;};


ANDEXPR	: ANDEXPR AND {push("&&");} UNARY {if($1 == 1 && $3==1) $$=1; else $$=-1;codegen(); }
				| UNARY {if($1 == 1) $$=1; else $$=-1;} ;


UNARY	: EXC {push("!");} UNARY {if($2==1) $$=1; else $$=-1; codegen(); }
			| REXPR {if($1 == 1) $$=1; else $$=-1;} ;

REXPR	: REXPR RELATIONAL SUMEXPR {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen(); }
			| SUMEXPR {if($1 == 1) $$=1; else $$=-1;} ;


RELATIONAL	: GRETHANA {push(">=");}
						| LESSTHANA {push("<=");}
						| GRETHAN {push(">");}
						| LESSTHAN {push("<");}
						| EQ {push("==");}
						| NEQ {push("!=");} ;

SUMEXPR	: SUMEXPR sum_operators TERM {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen(); }
				| TERM  {if($1 == 1) $$=1; else $$=-1;} ;

sum_operators	: ADD {push("+");}
							| SUB {push("-");};

TERM	: TERM MULOP FACTOR {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| FACTOR {if($1 == 1) $$=1; else $$=-1;}  ;

MULOP	: MUL {push("*");}
			| DIV {push("/");}
			| MOD {push("%");} ;

FACTOR	: IMMUTABLE {if($1 == 1) $$=1; else $$=-1;}
				| MUTABLE {if($1 == 1) $$=1; else $$=-1;} ;

MUTABLE	: IDEN { push(CID); if(check_id_is_func(CID))  {printf("Function name used as Identifier\n"); exit(8);} if(!checkscope(CID))  {printf("%s\n",CID);printf("Undeclared\n");exit(0);} if(!checkarray(CID)) {printf("%s\n",CID );printf("Array ID has no subscript\n");exit(0);} if(gettype(CID,0)=='i' || gettype(CID,1)== 'c') $$ = 1; else $$ = -1;}
				| ARRAYIDEN {if(!checkscope(CID)){printf("%s\n",CID);printf("Undeclared\n");exit(0);}} OSB EXPR CSB  {if(gettype(CID,0)=='i' || gettype(CID,1)== 'c')	$$ = 1;	else	$$ = -1;	};


IMMUTABLE	: OP EXPR CP {if($2==1) $$=1; else $$=-1;}
					| CALL {if($1==-1) $$=-1; else $$=1;}
					| constant {if($1==1) $$=1; else $$=-1;};

CALL	: IDEN OP {if(!check_declaration(CID, "Function")) { printf("Function not declared\n"); exit(0);} insertSTF(CID); strcpy(currfunccall,CID);  if(gettype(CID,0)=='i' || gettype(CID,1)== 'c') { $$ = 1; } else $$ = -1; call_params_count=0;}
				ARGUMENTS CP { if(strcmp(currfunccall,"printf")){if(getSTparamscount(currfunccall)!=call_params_count){yyerror("Number of arguments in function call doesn't match number of parameters\n");
							exit(8);}	} callgen(); };


ARGUMENTS	: ARGLIST
					| ;

ARGLIST	: ARGLIST COMMA EXP { call_params_count++; }
			 	| EXP { call_params_count++; };

EXP : IDEN {arggen(1);} | INTEGER {arggen(2);} | STRING {arggen(3);} | FLOATC {arggen(4);} | CHARACTER {arggen(5);} ;

STATEMENT	: EXPRST
					| COMPST
					| CONDST
					| ITER
					| RETURNS
					| BREAKS
					| VDECLARE;


constant	: INTEGER 	{ insertvariable(); codegencon(); $$=1; }
					| STRING	{ insertvariable(); codegencon(); $$=-1; }
					| FLOATC	{ insertvariable(); codegencon(); }
					| CHARACTER { insertvariable(); codegencon(); $$=1;  };

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSymboltype(char *,char *);
void insertSymbolvalue(char *, char *);
void incertconstant(char *, char *);
void printsymbol();
void printconstant();

struct stack
{
	char value[100];
	int labelvalue;
}s[100],label[100];


void push(char *x)
{
	strcpy(s[++top].value,x);
}

void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;


    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }


    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';


    reverse(str, i);

    return str;
}

void codegen()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s %s %s\n",temp,s[top-2].value,s[top-1].value,s[top].value);
	top = top - 2;
	strcpy(s[top].value,temp);
	count++;
}

void codegencon()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s\n",temp,CVAL);
	push(temp);
	count++;

}

int isunary(char *s)
{
	if(strcmp(s, "--")==0 || strcmp(s, "++")==0)
	{
		return 1;
	}
	return 0;
}

void genunary()
{
	char temp1[100], temp2[100], temp3[100];
	strcpy(temp1, s[top].value);
	strcpy(temp2, s[top-1].value);

	if(isunary(temp1))
	{
		strcpy(temp3, temp1);
		strcpy(temp1, temp2);
		strcpy(temp2, temp3);
	}
	strcpy(temp, "t");
	char buffer[100];
	itoa(count, buffer, 10);
	strcat(temp, buffer);
	count++;

	if(strcmp(temp2,"--")==0)
	{
		printf("%s = %s - 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	if(strcmp(temp2,"++")==0)
	{
		printf("%s = %s + 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	top = top -2;
}

void codeassign()
{
	printf("%s = %s\n",s[top-2].value,s[top].value);
	top = top - 2;
}

void label1()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("IF not %s GoTo %s\n",s[top].value,temp);
	label[++ltop].labelvalue = lno++;
}

void label2()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("GoTo %s\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;
	label[++ltop].labelvalue=lno++;
}

void label3()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;

}

void label4()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	label[++ltop].labelvalue = lno++;
}


void label5()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop-1].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("GoTo %s:\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop = ltop - 2;


}

void funcgen()
{
	printf("func begin %s\n",currfunc);
}

void funcgenend()
{
	printf("func end\n\n");
}

void arggen(int i)
{
    if(i==1)
    {
	printf("refparam %s\n", CID);
	}
	else
	{
	printf("refparam %s\n", CVAL);
	}
}

void callgen()
{
	printf("refparam result\n");
	push("result");
	printf("call %s, %d\n",currfunccall,call_params_count);
}



int main()
{
	yyin = fopen("test12.c", "r");
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
