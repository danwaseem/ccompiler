%{#include <stdio.h>
#include <string.h>

#define CAPACITY 1000

struct symbol
{
	char key[100];
	char data[100];
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

void insertsymbol(char *str2, char *str1)
{
	if(searchST(str1))
    return;
	else
	{
		int value = hash(str1);
		if(symb[value].length == 0)
		{
			strcpy(symb[value].key,str1);
			strcpy(symb[value].data,str2);
			symb[value].length = strlen(str1);
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
		strcpy(symb[pos].data,str2);
		symb[pos].length = strlen(str1);
	}
}

void insertconstant(char *str2, char *str1)
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

		printf("%s\t\t\t%s\n", symb[i].data,symb[i].key);
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
%}

digit [0-9]
letter [a-zA-Z_]
KEY "while"|"if"|"else"|"for"|"int"|"float"|"return"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"enum"|"extern"|"goto"|"long"|"register"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"
OPER "<="|"=="|"="|"++"|"-"|"*"|"+"|"%"|"<"|">"|"=>"|"!="|"/"|"&"
IDEN {letter}({letter}|{digit})*
INTE {digit}+

%%

\/\*(.*\n)*.*\*\/ {} ;
\/\* {del();}
\/\/(.*) {};
#(.*) {};
{KEY} {printf("Keyword: %s\n",yytext);insertsymbol("KEYWORD\t",yytext);}
\".*\" {printf("String Constant: %s\n",yytext);insertconstant("STRING CONSTANT",yytext);}
\'.*\' {printf("Character Constant: %s\n",yytext);insertconstant("CHARACTER CONSTANT",yytext);}
{INTE}+ {printf("Constant: %s\n",yytext);insertconstant("NUMBER CONSTANT",yytext);}
[(){}|,;] {printf("Seperator: %s\n",yytext);}
{IDEN} {printf("Identifier: %s\n",yytext);insertsymbol("IDENTIFIER",yytext);}
{OPER} {printf("Operator: %s\n",yytext);}
(\")[^\n\"]* {del1();}
(\')[^\n\']* {del1();}
[ \t\n]+ {};
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

int main()
{
  int i;
  for(i-0;i<CAPACITY;i++)
  {
    symb[i].length=0;
    cons[i].length=0;
  }
  yyin=fopen("input.c","r");
  yylex();
  printconstant();
  printsymbol();
}

int yywrap()
{
  return 1;
}
