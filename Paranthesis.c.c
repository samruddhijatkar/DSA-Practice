#include <stdio.h>
#define SIZE 50

struct stack
{
    char arr[SIZE];
    int top;
};


void init_stack(struct stack *sp)
{
    sp->top = -1;
}


int stack_empty(struct stack *sp)
{
    if (sp->top == -1)
        return 1;
    else
        return 0;
}


void push(struct stack *sp, char ch)
{
    sp->top++;
    sp->arr[sp->top] = ch;
}


char pop(struct stack *sp)
{
    return sp->arr[(sp->top)--];
}

int main()
{
    struct stack s1;
    char exp[100];
    char ch;
    int i;

    init_stack(&s1);

    printf("Enter Expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s1, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(stack_empty(&s1))
            {
                printf("Expression is Not Balanced");
                return 0;
            }

            ch = pop(&s1);

            if((exp[i] == ')' && ch != '(') ||
               (exp[i] == '}' && ch != '{') ||
               (exp[i] == ']' && ch != '['))
            {
                printf("Expression is Not Balanced");
                return 0;
            }
        }
    }

    if(stack_empty(&s1))
        printf("Expression is Balanced");
    else
        printf("Expression is Not Balanced");

    return 0;
}