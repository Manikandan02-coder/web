#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string starts with a given prefix
bool startsWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

// Function to check valid control structure
void checkControlStructure(const char *code) {
    if (startsWith(code, "for(") || startsWith(code, "for (")) {
        printf("This is a valid 'for' loop structure.\n");
    } else if (startsWith(code, "while(") || startsWith(code, "while (")) {
        printf("This is a valid 'while' loop structure.\n");
    } else if (startsWith(code, "if(") || startsWith(code, "if (")) {
        printf("This is a valid 'if' structure.\n");
    } else if (strstr(code, "else if(") || strstr(code, "else if (")) {
        printf("This is a valid 'if-else-if' structure.\n");
    } else if (startsWith(code, "switch(") || startsWith(code, "switch (")) {
        printf("This is a valid 'switch-case' structure.\n");
    } else if (startsWith(code, "else")) {
        printf("This is a valid 'else' structure.\n");
    } else {
        printf("This is not a valid control structure.\n");
    }
}

int main() {
    char code[100];

    printf("Enter a line of code: ");
    fgets(code, sizeof(code), stdin);

    checkControlStructure(code);

    return 0;
}