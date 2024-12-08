%{
#include <stdio.h>
%}

KEYWORD      (int|main)
ASSIGNMENT   =
IDENTIFIER   [a-zA-Z_][a-zA-Z0-9_]*
CONSTANT     [0-9]*
OPERATOR     [\+\-\*\%]

%%

{KEYWORD}      { printf("\"%s\" is a keyword \n", yytext); }
{IDENTIFIER}   { printf("\"%s\" is an Identifier \n", yytext); printf("Identifier %s is entered in the symbol table \n", yytext); }
{CONSTANT}     { printf("\"%s\" is a number \n", yytext); }
{ASSIGNMENT}   { printf("\"%s\" is an Assignment operator \n", yytext); }
{OPERATOR}     { printf("\"%s\" is an Operator \n", yytext); }
.              { printf("\"%s\" is an Unknown token \n", yytext); }

%%

int yywrap() { return 1; }

int main(int argc, char **argv) {
    if (argc > 1 && (yyin = fopen(argv[1], "r")) == NULL) {
        perror("Failed to open file");
        return 1;
    }

    yylex();
    return 0;
}