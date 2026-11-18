// Write a program to evaluate a postfix expression.

#include <stdio.h>
#include<ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    stack[++top] = value;
}

// Pop operation
int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]){
    int op1,op2;
    for(int i = 0;exp[i] != '\0';i++){
        // If operand push to stack
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else{
            op2 = pop();
            op1 = pop();

            switch(exp[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));
    return 0;
}