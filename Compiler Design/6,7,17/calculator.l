%{
#include "calculator.tab.h"
%}

%%

[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[\t\n ]+        ;  // Ignore whitespace
"+"             return PLUS;
"-"             return MINUS;
"*"             return MULTIPLY;
"/"             return DIVIDE;
"("             return LPAREN;
")"             return RPAREN;

.               return yytext[0];  // Return any other character as is

%%

int yywrap() {
    return 1;  // Indicate end of input
}
