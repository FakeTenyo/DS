#include <stdio.h>
#define MAX 5

int stack[MAX];

int top = -1;

void push(int item) {
    if(top == MAX-1) {
        printf("Stack is full. Push operation cannot be performed.\n");
    } else {
        stack[++top] = item;
        printf("Pushed %d into the stack.\n", item);
    }
}

int pop() {
    if(top == -1) {
        printf("Stack is empty. Pop operation cannot be performed.\n");
        return -1;
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        return stack[top--];
    }
}

int main() {
    
    push(10);
    push(20);
    push(30);
    
    pop();
    pop();
    pop();
    
    return 0;
}