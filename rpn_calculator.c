#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Stack structure */
typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

/* Initialize stack */
void init(Stack *s) {
    s->top = -1;
}

/* Check if stack is empty */
int isEmpty(Stack *s) {
    return s->top == -1;
}

/* Check if stack is full */
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

/* Push value onto stack */
void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Error: Stack overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

/* Pop value from stack */
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack underflow - not enough operands\n");
        exit(1);
    }
    return s->data[s->top--];
}

/* Peek at top value without removing */
double peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    init(&s);

    char instruction;
    double num, a, b, result;

    printf("==============================================\n");
    printf("   Reverse Polish Notation (RPN) Calculator  \n");
    printf("==============================================\n");
    printf("  ? <number>  - Push number onto stack\n");
    printf("  + - * /     - Arithmetic operations\n");
    printf("  =           - Print top of stack\n");
    printf("  q           - Quit\n");
    printf("==============================================\n\n");

    while (1) {
        printf("Enter instruction: ");
        scanf(" %c", &instruction);

        if (instruction == 'q') {
            printf("\nExiting RPN Calculator. Goodbye!\n");
            break;

        } else if (instruction == '?') {
            /* Read number and push onto stack */
            scanf("%lf", &num);
            push(&s, num);
            printf("  Pushed: %.2f  |  Stack top: %.2f\n", num, peek(&s));

        } else if (instruction == '+') {
            b = pop(&s);
            a = pop(&s);
            result = a + b;
            push(&s, result);
            printf("  %.2f + %.2f = %.2f\n", a, b, result);

        } else if (instruction == '-') {
            b = pop(&s);
            a = pop(&s);
            result = a - b;
            push(&s, result);
            printf("  %.2f - %.2f = %.2f\n", a, b, result);

        } else if (instruction == '*') {
            b = pop(&s);
            a = pop(&s);
            result = a * b;
            push(&s, result);
            printf("  %.2f * %.2f = %.2f\n", a, b, result);

        } else if (instruction == '/') {
            b = pop(&s);
            a = pop(&s);
            if (b == 0) {
                /* Restore stack on division by zero */
                printf("  Error: Division by zero is not allowed\n");
                push(&s, a);
                push(&s, b);
            } else {
                result = a / b;
                push(&s, result);
                printf("  %.2f / %.2f = %.2f\n", a, b, result);
            }

        } else if (instruction == '=') {
            /* Print result without popping */
            printf("  Result: %.2f\n", peek(&s));

        } else {
            printf("  Unknown instruction '%c'. Use ?, +, -, *, /, =, q\n", instruction);
        }
    }

    return 0;
}