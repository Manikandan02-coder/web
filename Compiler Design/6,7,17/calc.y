%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();  // Function provided by LEX to tokenize input
%}

%token NUMBER PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN

%left PLUS MINUS           // Left-to-right precedence
%left MULTIPLY DIVIDE      // Higher precedence
%right UMINUS              // Unary minus

%%

calculation:
    calculation expression '\n'   { printf("Result: %d\n", $2); }
    |
    ;

expression:
    expression PLUS expression    { $$ = $1 + $3; }
    | expression MINUS expression { $$ = $1 - $3; }
    | expression MULTIPLY expression { $$ = $1 * $3; }
    | expression DIVIDE expression {
        if ($3 == 0) { yyerror("Division by zero"); exit(1); }
        $$ = $1 / $3;
      }
    | LPAREN expression RPAREN    { $$ = $2; }
    | MINUS expression %prec UMINUS { $$ = -$2; }
    | NUMBER                      { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
