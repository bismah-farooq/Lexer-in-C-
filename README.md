# Lexer in C

## Name
**Bismah Farooq**

---

## Description
This program implements a simple **lexer (lexical analyzer)** written in C.  
It reads expressions and breaks them into meaningful components called **tokens**, such as identifiers, numbers, operators, and parentheses.

The purpose of this program is to demonstrate how lexical analysis works as part of a compiler or interpreter pipeline.

---

## Features
- Tokenizes input expressions
- Identifies:
  - Identifiers
  - Numbers
  - Operators (`+`, `-`, `*`, `/`)
  - Parentheses (`(` and `)`)
- Ignores whitespace
- Uses C structures to store token information
- Prints tokens with their corresponding types

---

## How the Program Works
1. The program reads an input expression.
2. Each character is analyzed sequentially.
3. Characters are grouped into lexemes.
4. Each lexeme is classified into a token type.
5. Tokens are printed with their lexeme and type.

---

## Sample Output
```text
Expression: a + 3 * (b - 2)

Lexeme: a        Type: IDENTIFIER
Lexeme: +        Type: OPERATOR
Lexeme: 3        Type: NUMBER
Lexeme: *        Type: OPERATOR
Lexeme: (        Type: LEFT_PAREN
Lexeme: b        Type: IDENTIFIER
Lexeme: -        Type: OPERATOR
Lexeme: 2        Type: NUMBER
Lexeme: )        Type: RIGHT_PAREN
```

## Compilation and Execution 
To compile and run the program using a terminal:
```text
gcc main.c -o lexer
./lexer
```

## Notes
* The lexer ignores spaces and newline characters
* Token classification is done using character checks
* Designed for educational purposes to demonstrate lexical analysis
