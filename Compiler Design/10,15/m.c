#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack for operand management
int stack[MAX_STACK_SIZE];
int top = -1;

// Temporary register counter for machine code
int regCounter = 0;

// Push to the stack
void push(int value) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop from the stack
int pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// Generate unique register names
int newRegister() {
    return regCounter++;
}

// Generate machine code
void generateCode(char op, int reg1, int reg2, int resultReg) {
    printf("R%d = R%d %c R%d\n", resultReg, reg1, op, reg2);
}

// Process postfix expression
void generateMachineCode(const char *postfix) {
    char ch;
    int i = 0;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            // Push operands (numbers) to the stack
            int reg = newRegister();
            printf("R%d = %c\n", reg, ch); // Load operand into a register
            push(reg);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Pop two operands for binary operations
            int reg2 = pop();
            int reg1 = pop();
            int resultReg = newRegister();

            // Generate machine code for the operation
            generateCode(ch, reg1, reg2, resultReg);

            // Push the result register back to the stack
            push(resultReg);
        } else if (ch != ' ') {
            printf("Error: Invalid character '%c' in expression\n", ch);
            exit(1);
        }
    }

    if (top == 0) {
        printf("Final result in R%d\n", stack[top]);
    } else {
        printf("Error: Invalid postfix expression\n");
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    // Remove trailing newline character if present
    postfix[strcspn(postfix, "\n")] = '\0';

    printf("\nGenerated Machine Code:\n");
    generateMachineCode(postfix);

    return 0;
}
