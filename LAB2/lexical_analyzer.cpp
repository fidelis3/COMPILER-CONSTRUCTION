#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
// Define token types
enum TokenType {
KEYWORD,
OPERATOR,
RELATIONAL_OPERATOR,
PUNCTUATION,
IDENTIFIER,
CONSTANT
};
// Token structure
struct Token {
string lexeme;
TokenType type;
};
// Define token categories
const vector<string> keywords = {"int", "if", "then", "else", "endif", "while", "do",
"enddo", "print"};
const vector<string> operators = {"=", "[", "]", "(", ")", "+", "-", "*", "/"};
const vector<string> relational_operators = {"<", "<=", "==", ">=", ">", "!="};
const vector<char> punctuation = {';', ','};
const string letters =
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string digits = "0123456789";
// Function to check if a string is a keyword
bool isKeyword(const string& word) {
for (const string& keyword : keywords) {
if (word == keyword) {
return true;
}
}
return false;
}
// Function to check if a string is an operator
bool isOperator(const string& op) {
for (const string& o : operators) {
if (op == o) {
return true;
}
}
return false;
}
// Function to check if a string is a relational operator
bool isRelationalOperator(const string& op) {
for (const string& o : relational_operators) {
if (op == o) {
return true;
}
}
return false;
}
// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
for (char p : punctuation) {
if (c == p) {
return true;
}
}
return false;
}
// Function to check if a character is a letter
bool isLetter(char c) {
return isalpha(c);
}
// Function to check if a character is a digit
bool isDigit(char c) {
return isdigit(c);
}
// Function to tokenize the input program
vector<Token> tokenize(const string& program) {
vector<Token> tokens;
string lexeme;
for (size_t i = 0; i < program.size(); ++i) {
char currentChar = program[i];
// Skip whitespace characters
if (isspace(currentChar)) {
continue;
}
// Check for keywords, operators, and relational operators
lexeme += currentChar;
if (isKeyword(lexeme) || isOperator(lexeme) || isRelationalOperator(lexeme)) {
tokens.push_back({lexeme, KEYWORD});
lexeme = "";
continue;
}
// Check for punctuation
if (isPunctuation(currentChar)) {
tokens.push_back({string(1, currentChar), PUNCTUATION});
continue;
}
// Check for identifiers
if (isLetter(currentChar)) {
while (isLetter(program[i]) || isDigit(program[i])) {
lexeme += program[i++];
}
tokens.push_back({lexeme, IDENTIFIER});
lexeme = "";
--i;
continue;
}
// Check for constants
if (isDigit(currentChar)) {
while (isDigit(program[i])) {
lexeme += program[i++];
}
tokens.push_back({lexeme, CONSTANT});
lexeme = "";
--i;
continue;
}
}
return tokens;
}
// Function to print tokens
void printTokens(const vector<Token>& tokens) {
for (const Token& token : tokens) {
string tokenType;
switch (token.type) {
case KEYWORD:
tokenType = "Keyword";
break;
case OPERATOR:
tokenType = "Operator";
break;
case RELATIONAL_OPERATOR:
tokenType = "Relational Operator";
break;
case PUNCTUATION:
tokenType = "Punctuation";
break;
case IDENTIFIER:
tokenType = "Identifier";
break;
case CONSTANT:
tokenType = "Constant";
break;
default:
tokenType = "Unknown";
break;
}
cout << token.lexeme << " : " << tokenType << endl;
}
}
int main() {
string program = "int x = 10; if (x < 20) then print(x); endif";
vector<Token> tokens = tokenize(program);
cout << "Tokens:" << endl;
printTokens(tokens);
return 0;
}