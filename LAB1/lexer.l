%{
#include <stdio.h>
%}
%option noyywrap

%%
int|if|else|while|return   { printf("KEYWORD    : %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*    { printf("IDENTIFIER : %s\n", yytext); }
[0-9]+                     { printf("NUMBER     : %s\n", yytext); }
[+\-*/=<>]                 { printf("OPERATOR   : %s\n", yytext); }
[;,{}()]                   { printf("DELIMITER  : %s\n", yytext); }
[ \t\n]+                   { /* skip whitespace */ }
.                          { printf("LEXICAL ERROR: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}