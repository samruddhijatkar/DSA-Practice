#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

int main()
{
    int n, i, score, total = 0;
    char op[10];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("Enter operations:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "C") == 0)
        {
            pop();
        }
        else if(strcmp(op, "D") == 0)
        {
            push(2 * peek());
        }
        else if(strcmp(op, "+") == 0)
        {
            int first = pop();
            int second = peek();
            push(first);
            push(first + second);
        }
        else
        {
            score = atoi(op);
            push(score);
        }
    }

    for(i = 0; i <= top; i++)
        total += stack[i];

    printf("Final Score = %d", total);

    return 0;
}