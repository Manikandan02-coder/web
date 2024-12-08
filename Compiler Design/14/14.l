%{
#include <stdio.h>
int vowel_count = 0;
int consonant_count = 0;
int numbers_count = 0;	
%}

%%
[aAeEiIoOuU]     { vowel_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonant_count++; }
[0-9] { numbers_count++; }
.                { /* Ignore non-alphabet characters */ }
%%

int main() {
    printf("Enter a string: ");
    yylex();  // Start the lexical analysis
    printf("\nTotal number of vowels: %d\n", vowel_count);
    printf("Total number of consonants: %d\n", consonant_count);
    printf("Number count: %d\n",numbers_count);
    return 0;
}

int yywrap() {
    return 1;
}
