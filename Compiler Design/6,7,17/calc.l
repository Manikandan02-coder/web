%{
#include "calc.tab.h"  // Bison's header file for token definitions
%}

%%

[0-9]+          { yylval = atoi(yytext); return NUMBER; }  // Numbers
"+"             return PLUS;      // Plus
"-"             return MINUS;     // Minus
"*"             return MULTIPLY;  // Multiply
"/"             return DIVIDE;    // Divide
"("             return LPAREN;    // Left parenthesis
")"             return RPAREN;    // Right parenthesis
[\t\n ]+        ;                 // Ignore spaces
.               return yytext[0]; // Any other character

%%

int yywrap() { return 1; }  // End of input
