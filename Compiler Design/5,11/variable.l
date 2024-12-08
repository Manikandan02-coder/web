%{
#include "variable.tab.h"  // Include Bison's header file
%}

%%

[a-zA-Z][a-zA-Z0-9]*  { return VARIABLE; } // Match valid variable names
\n                     { return NEWLINE; } // Match newline characters
.                      { return yytext[0]; } // Match any other single character

%%

int yywrap() {
    return 1; // End of input
}
