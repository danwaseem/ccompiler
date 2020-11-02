%{
	#include "y.tab.h"
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<malloc.h>

	#define CAPACITY 1000
struct symbol
{
	char key[100];
	char class[100];
	char data[100];
	char value[100];
	int nestval;
	int lineno;
	int length;
	int params_count;
}symb[CAPACITY];

struct constant
{
	char key[100];
	char data[100];
	int length;
}cons[CAPACITY];


int currnest = 0;
extern int yylval;

int hash(char *str)
{
	int value = 0;
	for(int i = 0 ; i < strlen(str) ; i++)
	{
		value = 10*value + (str[i] - 'A');
		value = value % CAPACITY;
		while(value < 0)
			value = value + CAPACITY;
	}
	return value;
}
int searchST(char *str)
{
	int value = hash(str);
	if(symb[value].length == 0)
		return 0;
	else if(strcmp(symb[value].key,str)==0)
		return value;
	else
	{
		for(int i = value + 1 ; i!=value ; i = (i+1)%CAPACITY)
    	if(strcmp(symb[i].key,str)==0)
    		return 1;
    return 0;
  }
}
int searchCT(char *str)
{
	int value = hash(str);
  if(cons[value].length == 0)
		return 0;
	else if(strcmp(cons[value].key,str)==0)
		return 1;
	else
	{
		for(int i = value + 1 ; i!=value ; i = (i+1)%CAPACITY)
			if(strcmp(cons[i].key,str)==0)
				return 1;
		return 0;
	}
}
void insertSymboltype(char *str1, char *str2)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,str1)==0)
		{
			strcpy(symb[i].data,str2);
		}
	}
	}

void insertSymbolvalue(char *str1, char *str2)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,str1)==0 && symb[i].nestval == currnest)
		{
			strcpy(symb[i].value,str2);
		}
	}
}

void insertSTnest(char *s, int nest)
{
	if(searchST(s) && symb[searchST(s)].nestval != 99999)
	{
		int pos = 0;
		int value = hash(s);
		for (int i = value + 1 ; i!=value ; i = (i+1)%(CAPACITY+1))
		{
			if(symb[i].length == 0)
			{
				pos = i;
				break;
			}
		}

		strcpy(symb[pos].key,s);
		strcpy(symb[pos].class,"Identifier");
		symb[pos].length = strlen(s);
		symb[pos].nestval = nest;
		symb[pos].params_count = -1;
		symb[pos].lineno = yylineno;
	}
	else
	{
		for(int i = 0 ; i < (CAPACITY+1) ; i++)
		{
			if(strcmp(symb[i].key,s)==0 )
			{
				symb[i].nestval = nest;
			}
		}
	}
}

void insertSTparamscount(char *s, int count)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,s)==0 )
		{
			symb[i].params_count = count;
		}
	}
}

int getSTparamscount(char *s)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,s)==0 )
		{
			return symb[i].params_count;
		}
	}
	return -1;
}

void insertSTF(char *s)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,s)==0 )
		{
			strcpy(symb[i].class,"Function");
			return;
		}
	}

}

void insertSymbolline(char *str1, int line)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(strcmp(symb[i].key,str1)==0)
		{
			symb[i].lineno = line;
		}
	}
}


void insertsymbol(char *str1, char *str2)
{
	if(searchST(str1))
	{

		if(strcmp(symb[searchST(str1)].class,"Identifier")==0 && strcmp(str2,"Array Identifier")==0)
		{
			printf("Error use of array\n");
			exit(0);
		}
		return;
	}
	else
	{
		int value = hash(str1);
		if(symb[value].length == 0)
		{
			strcpy(symb[value].key,str1);
			strcpy(symb[value].class,str2);
			symb[value].length = strlen(str1);
			symb[value].nestval = 99999;
			symb[value].params_count = -1;
			insertSymbolline(str1,yylineno);
			return;
		}

		int pos = 0;

		for (int i = value + 1 ; i!=value ; i = (i+1)%CAPACITY)
			if(symb[i].length == 0)
			{
				pos = i;
				break;
			}

		strcpy(symb[pos].key,str1);
		strcpy(symb[pos].class,str2);
		symb[pos].length = strlen(str1);
		symb[pos].nestval = 99999;
		symb[pos].params_count = -1;
	}
}

void insertconstant(char *str1, char *str2)
{
	if(searchCT(str1))
		return;
	else
	{
		int value = hash(str1);
		if(cons[value].length == 0)
		{
			strcpy(cons[value].key,str1);
			strcpy(cons[value].data,str2);
			cons[value].length = strlen(str1);
			return;
		}

		int pos = 0;

		for (int i = value + 1 ; i!=value ; i = (i+1)%CAPACITY)
			if(cons[i].length == 0)
			{
				pos = i;
				break;
			}

		strcpy(cons[pos].key,str1);
		strcpy(cons[pos].data,str2);
		cons[pos].length = strlen(str1);
	}
}

void deletedata (int nesting)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++)
	{
		if(symb[i].nestval == nesting)
			symb[i].nestval = 99999;
	}
}

int checkscope(char *s)
{
	int flag = 0;
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(strcmp(symb[i].key,s)==0)
		{
			if(symb[i].nestval > currnest)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if(!flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int check_id_is_func(char *s)
{
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(strcmp(symb[i].key,s)==0)
		{
			if(strcmp(symb[i].class,"Function")==0)
				return 1;
		}
	}
	return 0;
}

int checkarray(char *s)
{
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(strcmp(symb[i].key,s)==0)
		{
			if(strcmp(symb[i].class,"Array Identifier")==0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int duplicate(char *s)
{
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(strcmp(symb[i].key,s)==0)
		{
			if(symb[i].nestval == currnest)
			{
        return 1;
			}
		}
	}

	return 0;
}

int check_duplicate(char* str)
{
	for(int i=0; i<(CAPACITY+1); i++)
	{
		if(strcmp(symb[i].key, str) == 0 && strcmp(symb[i].class, "Function") == 0)
		{
			printf("Function redeclaration not allowed\n");
			exit(0);
		}
	}
}

int check_declaration(char* str, char *check_type)
{
	for(int i=0; i<(CAPACITY+1); i++)
	{
		if(strcmp(symb[i].key, str) == 0 && strcmp(symb[i].class, "Function") == 0 || strcmp(symb[i].key,"printf")==0 )
		{
			return 1;
		}
	}
	return 0;
}

int check_params(char* type_specifier)
{
	if(!strcmp(type_specifier, "void"))
	{
		printf("Parameters cannot be of type void\n");
		exit(0);
	}
	return 0;
}

char gettype(char *s, int flag)
{
	for(int i = 0 ; i < (CAPACITY+1) ; i++ )
	{
		if(strcmp(symb[i].key,s)==0)
		{
			return symb[i].data[0];
		}
	}

}

void printsymbol()
{
  printf("\n\n*****SYMBOL TABLE*****\n\n");
	printf("Class\t\t\tType\t\t\tName\t\t\tValue\t\t\tLineNo\t\t\tNesting\t\t\tParams Count\n\n");
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(symb[i].length == 0)
			continue;

		printf("%-24s%-24s%-24s%-24s%-24d%-24d%-24d\n", symb[i].data,symb[i].class,symb[i].key,symb[i].value,symb[i].lineno,	symb[i].nestval, ST[i].params_count );
	}
}



void printconstant()
{
  printf("\n\n*****CONSTANT TABLE*****\n\n");
	printf("Type\t\t\t\tValue\n\n");
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(cons[i].length == 0)
			continue;
		printf("%-32s%-32s\n", cons[i].data,cons[i].key);
	}
}
char CID[20];
char CTYPE[20];
char CVAL[20];



%}

digit [0-9]
letter [a-zA-Z_]
IDEN {letter}({letter}|{digit})*
INTE {digit}+

%%

\n {yylineno++;}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ {} ;
\/\*[^(\*\/)] {del();}
\/\/(.*) {};
#(.*) {};
"while" {return WHILE;  insertsymbol(yytext, "Keyword");}
"if" {  insertsymbol(yytext, "Keyword"); return IF;}
"else" {  insertsymbol(yytext, "Keyword"); return ELSE;}
"for" {  insertsymbol(yytext, "Keyword"); return FOR;}
"int" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return INT;}
"float" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return FLOAT;}
"return" { insertsymbol(yytext, "Keyword"); return RETURN;}
"auto" {  insertsymbol(yytext, "Keyword");}
"break" {  insertsymbol(yytext, "Keyword"); return BREAK;}
"case" {  insertsymbol(yytext, "Keyword");}
"char" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return CHAR;}
"const" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"continue" {  insertsymbol(yytext, "Keyword");}
"default" { insertsymbol(yytext, "Keyword");}
"do" {  insertsymbol(yytext, "Keyword"); return DO;}
"double" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return DOUBLE;}
"enum" {  insertsymbol(yytext, "Keyword");}
"extern" {  insertsymbol(yytext, "Keyword");}
"goto" { insertsymbol(yytext, "Keyword");}
"long" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return LONG;}
"register" { insertsymbol(yytext, "Keyword");}
"short" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return SHORT;}
"signed" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return SIGNED;}
"sizeof" {  insertsymbol(yytext, "Keyword"); return SIZEOF;}
"static" { insertsymbol(yytext, "Keyword");}
"struct" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return STRUCT;}
"switch" {  insertsymbol(yytext, "Keyword");}
"typedef" {  insertsymbol(yytext, "Keyword");}
"union" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");return UNION;}
"unsigned" { insertsymbol(yytext, "Keyword"); return UNSIGNED;}
"void" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return VOID;}
"volatile" { insertsymbol(yytext, "Keyword");}
";" {return SEMICOLON;}
"," {return COMMA;}
"(" {return OP;}
")" {return CP;}
"{" {return OB;}
"}" {return CB;}
":" {return COLON;}
"." {return FULLSTOP;}
"[" {return OSB;}
"]" {return CSB;}

"-="			 {return SUBA;}
"<<="			 {return LSHIFT;}
">>="			 {return RSHIFT;}
"&="			 {return ANDA;}
"^="			 {return XORA;}
"|="			 {return ORA;}
"&"				 {return SAND;}
"!"				 {return EXC;}
"~"				 {return QUO;}
"-"				 {return SUB;}
"+"				 {return ADD;}
"*"				 {return MUL;}
"/"				 {return DIV;}
"%"				 {return MOD;}
"|"				 {return PIPE;}
\=				 {return ASS;}
"++"			{return INCRI;}
"--"		 {return DECRI;}
"<<"			 {return LEFTSHIFT;}
">>"			{return RIGHTSHIFT;}
"<="			 {return LESSTHANA;}
"<"				 {return LESSTHAN;}
">="			 {return GRETHANA;}
">"				 {return GRETHAN;}
"=="			 {return EQ;}
"!="			 {return NEQ;}
"&&"			 {return AND;}
"||"			 {return OR;}
"^"				{return UP;}
"*="			 {return MULA;}
"/="			{return DIVA;}
"%="			 {return MODA;}
"+="			 {return ADDA;}

\".*\" {strcpy(CVAL,yytext); insertconstant(yytext,"String Constant"); return STRING;}
[a-z|A-Z]([a-z|A-Z]|[0-9])*/\[ {strcpy(CID,yytext); insertsymbol(yytext, "Array Identifier"); return ARRAYIDEN;}
\'.*\' {strcpy(CVAL,yytext); insertconstant(yytext,"Character Constant"); return CHARACTER;}
{digit}+ {strcpy(CVAL,yytext); insertconstant(yytext, "Number Constant"); return INTEGER;}
{digit}+"."{digit}+  {strcpy(CVAL,yytext); insertconstant(yytext, "Floating Constant"); return FLOATC;}
{IDEN} {strcpy(CID,yytext);insertsymbol(yytext,"Identifier");  return IDEN;}

(\")[^\"]* {del1();}
(\')[^\']* {del1();}
[ \t]+ {};
. {printf("%s\n",yytext);del2();}


%%

int del()
{
  printf ("\n\n\n***ERROR: INCOMPLETE MULTI LINE COMMENT***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}

int del1()
{
  printf ("\n\n\n***ERROR: INCOMPLETE STRING***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}

int del2()
{
  printf ("\n\n\n***ERROR: UNKNOWN CHARACTER***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}
