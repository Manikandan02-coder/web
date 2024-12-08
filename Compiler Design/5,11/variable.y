%{
#include <stdio.h>
#include <stdlib.h>
%}

%token VARIABLE NEWLINE

%%

input:
      /* empty */               // Empty input
    | input line                // Multiple lines
    ;

line:
      VARIABLE                { printf("Valid variable: %s\n", yytext); }
    | NEWLINE                   { /* Ignore blank lines */ }
    ;

%%

int main() {
    printf("Enter variable names (Ctrl+D to quit):\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
