#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100], left[15], right[15];
int i = 1, j = 0, no = 0, tmpch = 90;

struct exp {
    int pos;
    char op;
} k[15];

void findOperators();
void explore();
void findLeft(int);
void findRight(int);

int main() {
    printf("Enter the Expression: ");
    scanf("%s", str);

    printf("The intermediate code:\t\tExpression\n");
    
    findOperators();
    explore();
    
    return 0;
}

void findOperators() {
    for (i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case ':':
                k[j].pos = i;
                k[j++].op = ':';
                break;
            case '/':
                k[j].pos = i;
                k[j++].op = '/';
                break;
            case '*':
                k[j].pos = i;
                k[j++].op = '*';
                break;
            case '+':
                k[j].pos = i;
                k[j++].op = '+';
                break;
            case '-':
                k[j].pos = i;
                k[j++].op = '-';
                break;
        }
    }
}

void explore() {
    i = 1;

    while (k[i].op != '\0') {
        findLeft(k[i].pos);
        findRight(k[i].pos);
        
        str[k[i].pos] = tmpch--;
        
        printf("\t%c := %s%c%s\t\t", str[k[i].pos], left, k[i].op, right);

        for (j = 0; j < strlen(str); j++) {
            if (str[j] != '$') {
                printf("%c", str[j]);
            }
        }

        printf("\n");
        i++;
    }
    
    findRight(-1);

    if (no == 0) {
        findLeft(strlen(str));
        printf("\t%s := %s", right, left);
        exit(0);
    }
    
    printf("\t%s := %c", right, str[k[--i].pos]);
}

void findLeft(int x) {
    int w = 0, flag = 0;

    x--;

    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && 
           str[x] != '-' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

void findRight(int x) {
    int w = 0, flag = 0;
    
    x++;

    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' && str[x] != '=' && 
           str[x] != ':' && str[x] != '-' && str[x] != '/') {
        if (str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}
