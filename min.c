#include <stdio.h>

#define MAX 100

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

// Push
void push(int x) {
    stack[++top] = x;

    if (minTop == -1 || x <= minStack[minTop]) {
        minStack[++minTop] = x;
    }
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    if (stack[top] == minStack[minTop])
        minTop--;

    top--;
}

// Top
int peek() {
    return stack[top];
}

// Get Minimum
int getMin() {
    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);

    printf("Minimum = %d\n", getMin());

    pop();
    printf("Minimum = %d\n", getMin());

    printf("Top = %d\n", peek());

    return 0;
}