/*
Name: Bismah Farooq
Date: 09/18/2025
Desc: Lexer.c - tokenizes the mathematical expressions that are listed in 'file.txt' and then displays the list of tokens for each expression.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Structure: token
Stores a complete token.
string lexeme - stores the character(s) for the identified token.
string type - stores the type of token found.
*/
struct token {
   char lexeme[20];
   char type[20];
};

 
/* Function: lexify
Identifies the tokens in the expression and places them in a list of tokens.  Identifiable tokens: +, -, *, /, (, ), =, identifier, number, unknown.  Spaces and returns are identified but not added to the token list.

string line: the expression string to iterate through.
token [] tokens: the initially empty list of token structures.
returns: the number of token structures that were added to the list.
*/
int lexify(char *line, struct token *tokens) {
    int lexeme_count = 0;
    // loop through the expression string
    
       // check for each of the different tokens.

          // construct a token struct for that token and place it in the list
    int i = 0;
    
    // if there is a space in the program it will skip it and moves on while i is not equal to 0 or a new line.
    while (line[i] != '\0' && line[i] != '\n') {
        if (isspace(line[i])) { i++; continue; }
    
    // assigning the symbol and type
    if (isalpha(line[i])) {                                   //Identifier (A-Z, a-z)
        char alphabets[30];
        int x = 0;
        while(isalnum(line[i])){
            alphabets[x++] = line[i++];
        }
        alphabets[x] = '\0';
        strcpy(tokens[lexeme_count].lexeme, alphabets);
        strcpy(tokens[lexeme_count].type, "IDENTIFIER");
        lexeme_count++;
    } else if (isdigit(line[i])){                           // Numbers
        char num[20];
        int y = 0;
        while(isdigit(line[i])){
            num[y++] = line[i++];
        }
        num[y] = '\0';
        strcpy(tokens[lexeme_count].lexeme, num);
        strcpy(tokens[lexeme_count].type, "NUMBER");
        lexeme_count++;
    } else if (line[i] == '+'){                           //Addition
        strcpy(tokens[lexeme_count].lexeme, "+");
        strcpy(tokens[lexeme_count].type, "ADD");
        lexeme_count++;
        i++;
    } else if (line[i] == '-'){                         //Subtraction
        strcpy(tokens[lexeme_count].lexeme, "-");
        strcpy(tokens[lexeme_count].type, "SUB");
        lexeme_count++;
        i++;
    } else if (line[i] == '*'){                         //Multiplication
        strcpy(tokens[lexeme_count].lexeme, "x");
        strcpy(tokens[lexeme_count].type, "MULT");
        lexeme_count++;
        i++;
    } else if (line[i] == '/'){                         //Division
        strcpy(tokens[lexeme_count].lexeme, "/");
        strcpy(tokens[lexeme_count].type, "DIV");
        lexeme_count++;
        i++;
    } else if (line[i] == '('){                         //Left parenthesis
        strcpy(tokens[lexeme_count].lexeme, "(");
        strcpy(tokens[lexeme_count].type, "L-PAREN");
        lexeme_count++;
        i++;
    } else if (line[i] == ')'){                         //Right parenthesis
        strcpy(tokens[lexeme_count].lexeme, ")");
        strcpy(tokens[lexeme_count].type, "R-PAREN");
        lexeme_count++;
        i++;
    } else if (line[i] == '='){                         //Assignment operator
        strcpy(tokens[lexeme_count].lexeme, "=");
        strcpy(tokens[lexeme_count].type, "ASSIGN");
        lexeme_count++;
        i++;
    } else {                                            // else - unknown
        char unknown[2] = {line[i], '\0'};
        strcpy(tokens[lexeme_count].lexeme, unknown);
        strcpy(tokens[lexeme_count].type, "UNKNOWN");
        lexeme_count++;
        i++;
    }
}

    return lexeme_count;
}

int main() {
   // Open file and process each line.
   FILE *fptr = fopen("file.txt", "r");
   char line[100];
   if(fptr != NULL) {
      while(fgets(line, 100, fptr)) {
         struct token tokens[15];
         int num = lexify(line, tokens);

         //display each of the tokens in the expression
         for(int i = 0; i < num; i++) {
            printf("Token: %s \tType: %s\n", tokens[i].lexeme, tokens[i].type);
         }
         printf("\n");
      }
   } else {
      printf("ERROR - cannot open file. \n");
   }
   fclose(fptr);
   return 0;
}

/* Input File:
x = x + 4
(sum + 47) / total
oldsum! - value/100
*/

/* Output:
Token: x    Type: IDENTIFIER
Token: =    Type: ASSIGN
Token: x    Type: IDENTIFIER
Token: +    Type: ADD
Token: 4    Type: NUMBER

Token: (    Type: L-PAREN
Token: sum  Type: IDENTIFIER
Token: +    Type: ADD
Token: 47   Type: NUMBER
Token: )    Type: R-PAREN
Token: /    Type: DIV
Token: total    Type: IDENTIFIER

Token: oldsum   Type: IDENTIFIER
Token: !    Type: UNKNOWN
Token: -    Type: SUB
Token: value    Type: IDENTIFIER
Token: /    Type: DIV
Token: 100  Type: NUMBER

*/

