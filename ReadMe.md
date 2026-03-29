# Compiler Construction Lab (Lex)

This repository is for learning basic Compiler Construction concepts, starting with **Lexical Analysis** using Lex/Flex.

The current lab (`LAB1`) contains a simple lexer that reads source-like input and classifies tokens such as:

- Keywords
- Identifiers
- Numbers
- Operators
- Delimiters
- Invalid characters (lexical errors)


## What the Lexer Recognizes

From `LAB1/lexer.l`, the lexer currently recognizes:

- **Keywords**: `int`, `if`, `else`, `while`, `return`
- **Identifiers**: names like `total`, `sum`, `my_var1`
- **Numbers**: integers like `25`, `50`
- **Operators**: `+ - * / = < >`
- **Delimiters**: `; , { } ( )`

It ignores whitespace and reports unknown characters as lexical errors.

## How to Run

### 1) Go to lab folder

```powershell
cd .\LAB1
```

### 2) Generate lexer source

If you have Flex installed:

```powershell
flex lexer.l
```

This creates `lex.yy.c`.

### 3) Compile generated C file

Using GCC:

```powershell
gcc lex.yy.c -o lexer
```

On Windows this creates `lexer.exe`.

### 4) Run with sample input

```powershell
.\lexer.exe < input.cpp
```

## Sample Input (`input.cpp`)

```cpp
int total = sum + 25;
if (total > 50) {
		total = total - 10;
}
```

## Lab 2: C++ Lexical Analyzer

`LAB2` contains a lexical analyzer implemented in C++ (`lexical_analyzer.cpp`).
It tokenizes a small program string and prints each lexeme with its token category.

The analyzer currently works with categories such as:

- Keywords
- Identifiers
- Constants
- Punctuation
- Operators and relational operators

### How to Build and Run (Lab 2)

```powershell
cd .\LAB2
g++ lexical_analyzer.cpp -o lexical_analyzer
.\lexical_analyzer.exe
```

By default, it analyzes the sample program defined inside `main()`.




