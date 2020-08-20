%{
%}

%%

\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {} ;
[ \t\n] {};

%%

int yywrap(){}
int main()
{
yyin=fopen("input.c","r");
yyout=fopen("input_copied.c","w");

yylex();
return 0;
}
