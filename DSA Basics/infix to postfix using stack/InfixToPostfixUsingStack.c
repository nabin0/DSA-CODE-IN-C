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

int isOperator(char opr)
{
    if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
    {
        return 1;
    }
    return 0;
}
int precidence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '-' || ch == '+')
    {
        return 2;
    }
    return 0;
}

char *infixIntoPostfix(char *infix)
{
    struct stack *stc = (struct stack *)malloc(sizeof(struct stack));
    stc->size = strlen(infix);
    stc->top = -1;
    stc->arr = (char *)malloc(stc->size * sizeof(char));
    char *postfix = (char *)malloc((sizeof(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precidence(infix[i]) > precidence(stackTop(stc)))
            {
                push(stc, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(stc);
                j++;
            }
        }
    }
    while (!isEmpty(stc))
    {
        postfix[j] = pop(stc);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a/b-c";
    printf("\nThe postfix expression is: %s", infixIntoPostfix(infix));
    return 0;
}