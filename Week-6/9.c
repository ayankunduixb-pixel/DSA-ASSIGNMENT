// Write a program to check balanced parentheses using stack.
#include <stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top == -1){
        return '\0';
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

int isBalanced(char exp[]){
    char ch;
    for(int i = 0;exp[i] != '\0';i++){
        ch = exp[i];

        // Opening brackets
        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }

        // Closing brackets
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(top == -1){
                return 0;
            }
            char popped = pop();

            if(!isMatchingPair(popped,ch)){
                return 0;
            }
        }
    }
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s",exp);

    if(isBalanced(exp)){
        printf("Balanced Paranthesis");
    }
    else{
        printf("Not a balanced Paranthesis");
    }
    return 0;
}