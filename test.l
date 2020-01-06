%{ 
    #include <stdio.h>
    #include <stdlib.h>
%}
keyword         bolo|pocho|dobara|agar|warna|ruko|khatam|kam
letter          [a-zA-Z]
identifier      {letter}+
number          -?[0-9](\.[0-9]+)?
string          \"([^\\\"|\\.])*\"
assignment      \=
sum             \+
sub             \-
terminator      \:
modulo          \%
operator        {sum}|{sub}|{assignment}|{modulo}
error           \.{identifier}
%% 
{keyword}           {printf("%s is a Keyword\n",yytext);}
{identifier}        {printf("%s is a identifier\n",yytext);}
{string}            {printf("%s is a string\n",yytext);}
{operator}          {printf("%s is a operator\n",yytext);}
{number}            {printf("%s is a Number\n",yytext);}
{terminator}        {printf("%s is a terminator\n",yytext);}
{error}             {printf("%s is an Invalid input\n",yytext);}
%% 
int yywrap(){}
int main(){ 
FILE *fp; 
fp = fopen("code.us","r"); 
yyin = fp; 
yylex(); 
return 0; 
} 
