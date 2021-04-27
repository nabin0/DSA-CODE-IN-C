#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
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

int push(struct stack *p, int val)
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

int pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack Underflow cannot pop");
    }
    else
    {
        int val = p->arr[p->top];
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
int main()
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    printf("\n\n\t\t------Stack is created successfully.-------\n\n");

    printf("------BeFore Push Operation.-------\n");
    printf("Before push Operations: Empty %d \n", isEmpty(ptr));
    printf("Before push Operations: Full %d \n\n", isFull(ptr));

    printf("-----Appplying Push operation.-------\n");
    printf("%d is pushed into the stack.\n", push(ptr, 162));
    printf("%d is pushed into the stack.\n", push(ptr, 1132));
    printf("%d is pushed into the stack.\n", push(ptr, 756));
    printf("%d is pushed into the stack.\n", push(ptr, 676));
    printf("%d is pushed into the stack.\n", push(ptr, 346));
    printf("%d is pushed into the stack.\n\n", push(ptr, 121));

    printf("------After Push Operation.-------\n");
    printf("After push Operations: Empty %d \n", isEmpty(ptr));
    printf("After push Operations: Full %d \n\n\n", isFull(ptr));
    printf("------BeFore POP Operation.-------\n");
    printf("Before pop Operations: Empty %d \n", isEmpty(ptr));
    printf("Before pop Operations: Full %d \n\n", isFull(ptr));

    printf("------Applying Pop Operation.-------\n");
    printf("%d is poped out.\n", pop(ptr));
    printf("%d is poped out.\n", pop(ptr));
    printf("%d is poped out.\n\n", pop(ptr));

    printf("------After pop Operation.-------\n");
    printf("\nAfter Operations: Empty %d \n", isEmpty(ptr));
    printf("After Operations: Full %d \n\n", isFull(ptr));

    printf("------After peek Operation.-------\n");
    for (int j = 1; j < ptr->top + 2; j++)
    {
        printf("\nAfter Operations element at %d is :  %d ", j, peek(ptr, j));
    }

    printf("\n\n------Top Element-------\n");
    printf("The top element of stack is: %d", stackTop(ptr));

    printf("\n\n------After peek Operation.-------\n");
    printf("The top element of stack is: %d", stackBottom(ptr));
    return 0;
}
