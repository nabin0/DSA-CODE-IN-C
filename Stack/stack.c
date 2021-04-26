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

void push(struct stack *p, int val)
{
 if (isFull(p))
 {
    printf("Stack Overflow cannot push the value %d", val);
    
 }
 else{
     p->top++;
     p->arr[p->top] = val;
 }
}

int pop(struct stack *p)
{
 if (isEmpty(p))
 {
    printf("Stack Underflow cannot pop");
    
 }
 else{
     int val = p->top;
     p->top--;
     return val;
 }
}
int main()
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 6;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    printf("Stack created successfully.\n");
    printf("Before push Operations: Empty %d \n", isEmpty(ptr));
    printf("Before push Operations: Full %d \n\n", isFull(ptr));
    push(ptr, 162);
    push(ptr, 1132);
    printf("After push Operations: Empty %d \n", isEmpty(ptr));
    printf("After push Operations: Full %d \n\n\n", isFull(ptr));
       printf("Before pop Operations: Empty %d \n", isEmpty(ptr));
    printf("Before pop Operations: Full %d \n", isFull(ptr));
    pop(ptr);
    printf("\nAfter Operations: Empty %d \n", isEmpty(ptr));
    printf("After Operations: Full %d \n", isFull(ptr));

    return 0;
}