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

int main() {
    
    return 0;
}