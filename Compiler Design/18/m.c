#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void eliminateLeftRecursion(char nonTerminal, char productions[][MAX], int count) {
    char alpha[MAX][MAX], beta[MAX][MAX];
    int alphaCount = 0, betaCount = 0;

    // Separate productions into alpha and beta sets
    for (int i = 0; i < count; i++) {
        if (productions[i][0] == nonTerminal) {
            // Left-recursive (A → Aα)
            strcpy(alpha[alphaCount++], productions[i] + 1);
        } else {
            // Non-left-recursive (A → β)
            strcpy(beta[betaCount++], productions[i]);
        }
    }

    // If no left recursion is present
    if (alphaCount == 0) {
        printf("%c → ", nonTerminal);
        for (int i = 0; i < count; i++) {
            printf("%s", productions[i]);
            if (i < count - 1) printf(" | ");
        }
        printf("\n");
        return;
    }

    // Output the transformed grammar
    char newNonTerminal = nonTerminal + '\'';
    printf("%c → ", nonTerminal);
    for (int i = 0; i < betaCount; i++) {
        printf("%s%c", beta[i], newNonTerminal);
        if (i < betaCount - 1) printf(" | ");
    }
    printf("\n");

    printf("%c → ", newNonTerminal);
    for (int i = 0; i < alphaCount; i++) {
        printf("%s%c", alpha[i], newNonTerminal);
        if (i < alphaCount - 1) printf(" | ");
    }
    printf("ε\n");
}

int main() {
    int n;
    printf("Enter the number of productions: ");
    scanf("%d", &n);

    char nonTerminal;
    char productions[MAX][MAX];
    printf("Enter the productions (e.g., A → Aa | b):\n");

    // Input grammar
    scanf(" %c →", &nonTerminal);
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("\nGrammar after eliminating left recursion:\n");
    eliminateLeftRecursion(nonTerminal, productions, n);

    return 0;
}
