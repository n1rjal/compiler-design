#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char a[10];
    int flag, i = 1;

    printf("Enter an identifier: ");
    // Use fgets instead of gets for safety
    fgets(a, sizeof(a), stdin);
    
    // Remove newline character
    size_t len = strlen(a);
    if (a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }

    if (isalpha(a[0]) || a[0] == '_') {
        flag = 1;
    } else {
        printf("Not a valid identifier");
        return 0;  // Exit if the first character is invalid
    }

    while (a[i] != '\0') {
        if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag == 1) {
        printf("\nValid identifier");
    } else {
        printf("\nNot a valid identifier");
    }

    return 0;
}
