#include<stdio.h>

int main() {
    char com[30];
    int i, a = 0;

    printf("Enter comment: ");
    fgets(com, sizeof(com), stdin);  // Using fgets to safely get input

    // Check for newline character and replace it with null terminator
    for (i = 0; i < sizeof(com); i++) {
        if (com[i] == '\n') {
            com[i] = '\0';
            break;
        }
    }

    // Check if the string starts with a comment delimiter
    if (com[0] == '/') {
        if (com[1] == '/') {
            printf("\nIt is a comment");  // Single-line comment
        } else if (com[1] == '*') {
            // Searching for the closing delimiter of a multi-line comment
            for (i = 2; i < sizeof(com) - 1; i++) { // -1 to avoid reading beyond the array
                if (com[i] == '*' && com[i+1] == '/') {
                    printf("\nIt is a comment");
                    a = 1;
                    break;
                }
            }
            if (a == 0) {
                printf("\nIt is not a comment");
            }
        } else {
            printf("\nIt is not a comment");
        }
    } else {
        printf("\nIt is not a comment");
    }

    return 0;
}
