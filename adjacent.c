#include <stdio.h>
#include <string.h>

#define SIZE 100

struct stack
{
    char arr[SIZE];
    int top;
};


void init(struct stack *s)
{
    s->top = -1;
}


int isEmpty(struct stack *s)
{
    return (s->top == -1);
}


void push(struct stack *s, char ch)
{
    s->arr[++(s->top)] = ch;
}


char pop(struct stack *s)
{
    return s->arr[(s->top)--];
}


char peek(struct stack *s)
{
    return s->arr[s->top];
}

int main()
{
    struct stack s;
    char str[SIZE];
    int i;

    init(&s);

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(!isEmpty(&s) && peek(&s) == str[i])
        {
            pop(&s);          
        }
        else
        {
            push(&s, str[i]); 
        }
    }

    printf("String after removing adjacent duplicates: ");

    for(i = 0; i <= s.top; i++)
    {
        printf("%c", s.arr[i]);
    }

    return 0;
}