
%{ 
    #include <stdio.h>
    #include <stdlib.h>
    /*help from geeks for geeks */ 

%}
keyword         bolo|pocho|dobara|agar|warna|ruko|khatam|kam
letter          [a-zA-Z]	
number          -?[0-9](\.[0-9]+)?
string          \"([^\\\"|\\.])*\"
assignment      \=
sum             \+
sub             \-
operator        {sum}|{sub}|{assignment}
identifier      [letter]+

%% 
{string}            {printf("%s is a string\n",yytext);}
{operator}          {printf("%s is a operator\n",yytext);}
{number}            {printf("%s is a Number\n",yytext);}

{keyword}           {printf("%s is a Keyword\n",yytext);}
 
{identifier}        {printf("%s is a identifier\n",yytext);}

%% 
int yywrap(){}
int main(){ 
FILE *fp; 
fp = fopen("humarilanguage.txt","r"); 
yyin = fp; 
yylex(); 
return 0; 

} 
