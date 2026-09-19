#include <stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int precedence(char op){
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp){
    char* p = exp;
    while(*p != '\0'){
        if(isalnum(*p)){
            printf("%c",*p);
        }
        else if(*p =='('){
            push(*p);
        }
        else if(*p == ')'){
            while(top != -1 && stack[top] != '('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(top != -1 && precedence(stack[top]) >= precedence(*p)){
                printf("%c",pop());
            }
            push(*p);
        }
        p++;
    }
    while(top != -1){
        printf("%c",pop());
    }
}

int main() {
    char exp[] = "A+B*C";
    printf("Infix: %s\nPostfix: ",exp);
    infixToPostfix(exp);
    return 0;
}