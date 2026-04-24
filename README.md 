# Reverse Polish Notation (RPN) Calculator
### IC 2306 - Programming II | Final Group Project

---

## What is Reverse Polish Notation?

Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical
notation where operators follow their operands. This eliminates the need for
parentheses to define operation order.

**Normal (Infix):**  `(3 + 4) * (2 + 5)`  
**RPN (Postfix):**   `? 3 ? 4 + ? 2 ? 5 + * =`

This concept was proposed by Australian philosopher Charles L. Hamblin in the
late 1950s and is widely used in compilers and calculators.

---

## How It Works

This program uses a **stack data structure** (Last In, First Out) to evaluate
RPN expressions:

1. When `?` is encountered → read the next number and **push** it onto the stack
2. When an operator (`+`, `-`, `*`, `/`) is encountered → **pop** two numbers, calculate, and **push** the result
3. When `=` is encountered → **print** the top of the stack (the result)

---

## Instructions / Supported Commands

| Command | Description |
|---------|-------------|
| `? <number>` | Push a number onto the stack |
| `+` | Add the top two numbers |
| `-` | Subtract the top two numbers |
| `*` | Multiply the top two numbers |
| `/` | Divide the top two numbers |
| `=` | Print the current top of the stack |
| `q` | Quit the calculator |

---

## How to Compile and Run

### Requirements
- GCC compiler (or any C compiler)
- Linux / macOS / Windows (with MinGW or WSL)

### Compile
```bash
gcc rpn_calculator.c -o rpn_calculator
```

### Run
```bash
./rpn_calculator
```

---

## Test Cases

### Test 1 — Simple Addition
```
Input  : ? 3 ? 4 + =
Output : Result: 7.00
```

### Test 2 — Expression: (3 + 4) * (2 + 5)
```
Input  : ? 3 ? 4 + ? 2 ? 5 + * =
Output : Result: 49.00
```

### Test 3 — Mixed Operations: (a * (b - c)) + d
```
Input  : ? 10 ? 3 ? 2 - = * ? 4 + =
Output : Result: 14.00
```

### Test 4 — Division by Zero Handling
```
Input  : ? 5 ? 0 /
Output : Error: Division by zero is not allowed.
```

---

## Project Structure

```
rpn-calculator-c/
├── rpn_calculator.c   ← Main C source code
├── README.md          ← Project documentation
└── .gitignore         ← Git ignore rules
```

---

## Language & Tools

- **Language**: C
- **IDE**: Any (GCC / VS Code / Code::Blocks)
- **Data Structure**: Stack (Array-based)

---

## Course Information

- **Course**: IC 2306 - Programming II
- **Project**: Final Group Project — Reverse Polish Calculator