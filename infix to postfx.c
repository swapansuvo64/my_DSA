#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform the operation specified by an operator on two operands
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Division by zero is not allowed.\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    int length = strlen(postfix);
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    for (int i = 0; i < length; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            // If it's an operand, push it onto the stack
            push(stack, c - '0'); // Convert char to int
        } else if (isOperator(c)) {
            // If it's an operator, pop two operands from the stack and push the result back
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result = performOperation(operand1, operand2, c);
            push(stack, result);
        }
    }

    int finalResult = pop(stack); // The final result is on the stack
    free(stack);

    return finalResult;
}

int main() {
    char infixExpression[] = "238*+/"; // Replace with your infix expression
    printf("Infix expression: %s\n", infixExpression);

    char postfixExpression[100]; // You can store the postfix expression here (if needed)

    // Call a function to convert infix to postfix and evaluate the result
    int result = evaluatePostfix(infixExpression);
    printf("Result: %d\n", result);

    return 0;
}
