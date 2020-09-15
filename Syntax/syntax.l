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
	int lineno;
	int length;
}symb[CAPACITY];

struct constant
{
	char key[100];
	char data[100];
	int length;
}cons[CAPACITY];

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
		return 1;
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
	for(int i = 0 ; i < 1001 ; i++)
	{
		if(strcmp(symb[i].key,str1)==0)
		{
			strcpy(symb[i].data,str2);
		}
	}
	}

void insertSymbolvalue(char *str1, char *str2)
{
	for(int i = 0 ; i < 1001 ; i++)
	{
		if(strcmp(symb[i].key,str1)==0)
		{
			strcpy(symb[i].value,str2);
		}
	}
}

void insertSymbolline(char *str1, int line)
{
	for(int i = 0 ; i < 1001 ; i++)
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
    return;
	else
	{
		int value = hash(str1);
		if(symb[value].length == 0)
		{
			strcpy(symb[value].key,str1);
			strcpy(symb[value].class,str2);
			symb[value].length = strlen(str1);
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

void printsymbol()
{
  printf("\n\n*****SYMBOL TABLE*****\n\n");
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(symb[i].length == 0)
			continue;

		printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%d\n", symb[i].data,symb[i].class,symb[i].key,symb[i].value,symb[i].lineno);
	}
}

void printconstant()
{
  printf("\n\n*****CONSTANT TABLE*****\n\n");
	for(int i = 0 ; i < CAPACITY ; i++)
	{
		if(cons[i].length == 0)
			continue;
		printf("%s\t\t\t%s\n", cons[i].data,cons[i].key);
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
"while" {return WHILE; strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"if" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return IF;}
"else" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return ELSE;}
"for" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return FOR;}
"int" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return INT;}
"float" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return FLOAT;}
"return" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return RETURN;}
"auto" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"break" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return BREAK;}
"case" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"char" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return CHAR;}
"const" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"continue" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"default" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"do" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return DO;}
"double" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return DOUBLE;}
"enum" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"extern" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"goto" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"long" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return LONG;}
"register" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"short" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return SHORT;}
"signed" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return SIGNED;}
"sizeof" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return SIZEOF;}
"static" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"struct" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return STRUCT;}
"switch" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"typedef" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
"union" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");return UNION;}
"unsigned" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return UNSIGNED;}
"void" {strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword"); return VOID;}
"volatile" { strcpy(CTYPE,yytext); insertsymbol(yytext, "Keyword");}
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
