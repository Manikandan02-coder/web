#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure for a node in the AST
typedef struct Node {
    char data;              // Operator or operand
    struct Node *left;      // Left child
    struct Node *right;     // Right child
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Stack to hold AST nodes
Node* stack[100];
int top = -1;

// Push a node onto the stack
void push(Node* node) {
    stack[++top] = node;
}

// Pop a node from the stack
Node* pop() {
    return stack[top--];
}

// Function to build an AST from a postfix expression
Node* buildAST(const char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            // If it's an operand, create a node and push it onto the stack
            push(createNode(ch));
        } else {
            // If it's an operator, pop two nodes, create a new node, and push it back
            Node* right = pop();
            Node* left = pop();
            Node* opNode = createNode(ch);
            opNode->left = left;
            opNode->right = right;
            push(opNode);
        }
    }
    return pop(); // The root of the AST
}

// Function for inorder traversal (to display the tree as an expression)
void inorder(Node* root) {
    if (root != NULL) {
        if (!isalnum(root->data)) printf("("); // Add parentheses for operators
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (!isalnum(root->data)) printf(")");
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Build the AST
    Node* root = buildAST(postfix);

    printf("\nInorder traversal (Expression Tree): ");
    inorder(root);
    printf("\n");

    return 0;
}
