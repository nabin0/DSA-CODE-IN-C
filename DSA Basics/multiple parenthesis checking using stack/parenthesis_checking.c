#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *p)
{
    if (p->top == p->size - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct stack *p, char val)
{
    if (isFull(p))
    {
        printf("Stack Overflow cannot push the value %d", val);
        return -1;
    }
    else
    {
        p->top++;
        p->arr[p->top] = val;
        return val;
    }
}

char pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack Underflow cannot pop");
    }
    else
    {
        char val = p->arr[p->top];
        p->top--;
        return val;
    }
}

int peek(struct stack *p, int index)
{
    int arrPos = p->top - index + 1;
    if (arrPos < 0)
    {
        printf("Invalid Position");
        return -1;
    }
    else
    {

        return p->arr[arrPos];
    }
}

int stackTop(struct stack *p)
{
    return p->arr[p->top];
}
int stackBottom(struct stack *p)
{
    return p->arr[0];
}

int match(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
    {
        return 1;
    }
    return 0;
}

int paranthesisMathching(char *exp)
{

    struct stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            popped_char = pop(sp);
            if (!match(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "*1[121-43{12(34)22}43*3]";
    if (paranthesisMathching(exp))
    {
        printf("\nThe Expression is balanced.\n");
    }
    else
    {
        printf("\nThe Expression is not balanced.\n");
    }

    return 0;
}