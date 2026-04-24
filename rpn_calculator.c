/*
 * ============================================================
 *  Reverse Polish Notation (RPN) Calculator
 *  Course   : IC 2306 - Programming II
 *  Language : C
 * ============================================================
 *
 *  DESCRIPTION:
 *  This program implements a Reverse Polish Notation (RPN)
 *  calculator using a stack data structure. In RPN, operators
 *  follow their operands (postfix notation), eliminating the
 *  need for parentheses.
 *
 *  INSTRUCTIONS:
 *  Use '?' followed by a number to push onto the stack.
 *  Use '+', '-', '*', '/' to perform arithmetic operations.
 *  Use '=' to print the top of the stack (result).
 *  Use 'q' to quit the program.
 *
 *  EXAMPLE:
 *  Input  : ? 3 ? 4 + =
 *  Output : Result: 7.00
 * ============================================================
 */

#include <stdio.h>    /* Standard I/O functions (printf, scanf) */
#include <stdlib.h>   /* Standard library functions (exit)      */

/* ============================================================
 *  CONSTANTS
 * ============================================================ */

/* Maximum number of elements the stack can hold at one time */
#define MAX_SIZE 100

/* ============================================================
 *  STACK DATA STRUCTURE
 * ============================================================ */

/*
 * Stack structure definition.
 * Uses an array-based implementation for simplicity and efficiency.
 *
 * Fields:
 *   data[] - Array that stores the numeric values (double for decimals)
 *   top    - Index pointing to the current top element of the stack
 *            (-1 means the stack is empty)
 */
typedef struct {
    double data[MAX_SIZE]; /* Storage array for stack elements       */
    int top;               /* Index of the topmost element           */
} Stack;

/* ============================================================
 *  STACK OPERATION FUNCTIONS
 * ============================================================ */

/*
 * init()
 * Initializes the stack by setting top to -1.
 * Must be called before using the stack.
 *
 * Parameter: s - pointer to the Stack to initialize
 */
void init(Stack *s) {
    s->top = -1; /* -1 indicates an empty stack */
}

/*
 * isEmpty()
 * Checks whether the stack has no elements.
 *
 * Parameter : s - pointer to the Stack
 * Returns   : 1 (true) if empty, 0 (false) if not empty
 */
int isEmpty(Stack *s) {
    return s->top == -1; /* Returns 1 if top is still at initial value */
}

/*
 * isFull()
 * Checks whether the stack has reached its maximum capacity.
 *
 * Parameter : s - pointer to the Stack
 * Returns   : 1 (true) if full, 0 (false) if not full
 */
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1; /* top reaches last valid index when full */
}

/*
 * push()
 * Adds a new value onto the top of the stack.
 * Prints an error if the stack is already full (overflow).
 *
 * Parameters:
 *   s     - pointer to the Stack
 *   value - the double value to push onto the stack
 */
void push(Stack *s, double value) {
    if (isFull(s)) {
        /* Cannot push — stack has reached maximum capacity */
        printf("Error: Stack overflow. Cannot push %.2f\n", value);
        return;
    }
    /* Increment top first, then store the value at the new top index */
    s->data[++s->top] = value;
}

/*
 * pop()
 * Removes and returns the value from the top of the stack.
 * Terminates the program if the stack is empty (underflow).
 *
 * Parameter : s - pointer to the Stack
 * Returns   : the double value that was on top of the stack
 */
double pop(Stack *s) {
    if (isEmpty(s)) {
        /* Cannot pop — no elements exist in the stack */
        printf("Error: Stack underflow. Not enough operands.\n");
        exit(1); /* Critical error — stop the program */
    }
    /* Return current top value, then decrement top */
    return s->data[s->top--];
}

/*
 * peek()
 * Returns the top value of the stack WITHOUT removing it.
 * Used by the '=' instruction to print the result.
 * Terminates the program if the stack is empty.
 *
 * Parameter : s - pointer to the Stack
 * Returns   : the double value currently on top of the stack
 */
double peek(Stack *s) {
    if (isEmpty(s)) {
        /* Cannot peek — stack is empty, nothing to display */
        printf("Error: Stack is empty. No result to display.\n");
        exit(1); /* Critical error — stop the program */
    }
    /* Return top value without changing top index */
    return s->data[s->top];
}

/* ============================================================
 *  MAIN PROGRAM — RPN CALCULATOR LOGIC
 * ============================================================ */

int main() {

    Stack s;           /* Declare the stack variable                  */
    init(&s);          /* Initialize stack (set top = -1)             */

    char instruction;  /* Stores each instruction character read      */
    double num;        /* Stores a number when '?' instruction is used */
    double a, b;       /* Operands popped from stack for calculations  */
    double result;     /* Stores the calculated result                 */

    /* ---- Welcome Message ---- */
    printf("==============================================\n");
    printf("   Reverse Polish Notation (RPN) Calculator  \n");
    printf("==============================================\n");
    printf("Instructions:\n");
    printf("  ? <number>  - Push a number onto the stack\n");
    printf("  +           - Add top two numbers\n");
    printf("  -           - Subtract top two numbers\n");
    printf("  *           - Multiply top two numbers\n");
    printf("  /           - Divide top two numbers\n");
    printf("  =           - Print the top of the stack\n");
    printf("  q           - Quit the calculator\n");
    printf("==============================================\n\n");

    /* ---- Main Input Loop ---- */
    /* Continuously read instructions until user quits with 'q' */
    while (1) {

        printf("Enter instruction: ");

        /* Read the next non-whitespace character as instruction */
        scanf(" %c", &instruction);

        /* ---- QUIT ---- */
        if (instruction == 'q') {
            /* User wants to exit the calculator */
            printf("\nExiting RPN Calculator. Goodbye!\n");
            break; /* Exit the while loop */

        /* ---- PUSH OPERAND ---- */
        } else if (instruction == '?') {
            /* Read the number that follows '?' */
            scanf("%lf", &num); /* %lf reads a double precision float */

            /* Push the number onto the stack */
            push(&s, num);
            printf("  Pushed: %.2f  |  Stack top: %.2f\n", num, peek(&s));

        /* ---- ADDITION ---- */
        } else if (instruction == '+') {
            b = pop(&s);          /* Pop second operand first (LIFO order) */
            a = pop(&s);          /* Pop first operand                     */
            result = a + b;       /* Perform addition                      */
            push(&s, result);     /* Push result back onto stack           */
            printf("  %.2f + %.2f = %.2f\n", a, b, result);

        /* ---- SUBTRACTION ---- */
        } else if (instruction == '-') {
            b = pop(&s);          /* Pop second operand (subtrahend)       */
            a = pop(&s);          /* Pop first operand (minuend)           */
            result = a - b;       /* Perform subtraction: a minus b        */
            push(&s, result);     /* Push result back onto stack           */
            printf("  %.2f - %.2f = %.2f\n", a, b, result);

        /* ---- MULTIPLICATION ---- */
        } else if (instruction == '*') {
            b = pop(&s);          /* Pop second operand                    */
            a = pop(&s);          /* Pop first operand                     */
            result = a * b;       /* Perform multiplication                */
            push(&s, result);     /* Push result back onto stack           */
            printf("  %.2f * %.2f = %.2f\n", a, b, result);

        /* ---- DIVISION ---- */
        } else if (instruction == '/') {
            b = pop(&s);          /* Pop divisor (bottom number)           */
            a = pop(&s);          /* Pop dividend (top number)             */

            /* Check for division by zero before dividing */
            if (b == 0) {
                printf("  Error: Division by zero is not allowed.\n");
                /* Restore the stack to its previous state */
                push(&s, a);
                push(&s, b);
            } else {
                result = a / b;   /* Perform division                      */
                push(&s, result); /* Push result back onto stack           */
                printf("  %.2f / %.2f = %.2f\n", a, b, result);
            }

        /* ---- PRINT TOP (RESULT) ---- */
        } else if (instruction == '=') {
            /* Print the top of stack without removing it */
            printf("  Result: %.2f\n", peek(&s));

        /* ---- UNKNOWN INSTRUCTION ---- */
        } else {
            /* Handle any unrecognized input gracefully */
            printf("  Unknown instruction '%c'. Please use ?, +, -, *, /, =, q\n",
                   instruction);
        }

    } /* End of main while loop */

    return 0; /* Program completed successfully */
}

/*
 * ============================================================
 *  END OF PROGRAM
 *
 *  TEST CASES TO TRY:
 *
 *  Test 1 - Simple addition:
 *    Input : ? 3 ? 4 + =
 *    Output: Result: 7.00
 *
 *  Test 2 - Expression (a+b)*(c+d):
 *    Input : ? 3 ? 4 + ? 2 ? 5 + * =
 *    Output: Result: 49.00
 *
 *  Test 3 - Mixed operations:
 *    Input : ? 10 ? 3 ? 2 - = * ? 4 + =
 *    Output: (prints b-c=1, then (a*(b-c))+d = 14.00)
 *
 *  Test 4 - Division by zero:
 *    Input : ? 5 ? 0 /
 *    Output: Error: Division by zero is not allowed.
 * ============================================================
 */