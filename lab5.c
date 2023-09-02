#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to check if a given string is a keyword in C
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    int flag = 0;
    for(int i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    // Open the input file in read mode
    fp = fopen("inputfile.txt", "r");
    if(fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    // Reading characters one by one from the file
    while((ch = fgetc(fp)) != EOF) {
        // If character is an operator, print it
        for(i = 0; i < 6; ++i) {
            if(ch == operators[i]) {
                printf("%c is operator\n", ch);
                break;  // Exit loop once operator is found
            }
        }

        // If character is alphanumeric, append to buffer
        if(isalnum(ch) || ch == '_') { // Added '_' check as identifiers in C can contain underscores
            buffer[j++] = ch;
        } 
        // If space or newline character is encountered, identify if buffer is keyword or identifier
        else if((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';  // Null terminate the buffer string
            j = 0;
            if(isKeyword(buffer)) {
                printf("%s is keyword\n", buffer);
            } else {
                printf("%s is identifier\n", buffer);
            }
        }
    }
    fclose(fp);  // Close the file after reading
    return 0;
}
