#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function prototypes
void initialize(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int isOperator(char ch);
int compute(char operator, int operand1, int operand2);
int evaluatePostfix(char postfixExpression[]);

int main() {
    char postfixExpression[MAX_SIZE];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    gets(postfixExpression);

    // Evaluate and print the result
    printf("Result: %d\n", evaluatePostfix(postfixExpression));

    return 0;
}

void initialize(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int compute(char operator, int operand1, int operand2) {
    switch (operator) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0) {
            return operand1 / operand2;
        } else {
            printf("Error: Division by zero\n");
            exit(EXIT_FAILURE);
        }
    default:
        printf("Error: Invalid operator\n");
        exit(EXIT_FAILURE);
    }
}

int evaluatePostfix(char postfixExpression[]) {
    struct Stack s;
    initialize(&s);

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
        if (isdigit(postfixExpression[i])) {
            // Operand
            push(&s, postfixExpression[i] - '0');
        } else if (isOperator(postfixExpression[i])) {
            // Operator
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result = compute(postfixExpression[i], op1, op2);
            push(&s, result);
        }
        // Ignore other characters
    }

    return pop(&s);
}
