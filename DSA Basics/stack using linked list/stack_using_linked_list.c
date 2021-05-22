#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversel(struct Node *ptr)
{
    printf("\nThe Elements in the list are: \n");
    while (ptr != NULL)
    {
        printf(" %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {

        return 0;
    }
}

struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
        nw->data = data;
        nw->next = top;
        top = nw;
        return top;
    }
}
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *del = *top;
        *top = (*top)->next;
        int ret = del->data;
        free(del);
        return ret;
    }
}

int peek(struct Node *top, int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1;
}

int stackTop(struct Node *top)
{
    if (top != NULL)
    {
        return top->data;
    }
    return -1;
}
int stackBottom(struct Node *top)
{
    struct Node *a = top;
    while (a->next != NULL)
    {
        a = a->next;
    }
    if (a == NULL)
    {
        return -1;
    }

    return a->data;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 89);
    top = push(top, 8219);
    top = push(top, 56);
    linkedListTraversel(top);
    printf("\n%d is poped.\n", pop(&top));
    linkedListTraversel(top);
    printf("\nThe element at position %d is : %d", 2, peek(top, 2));
    printf("\n\nThe top element is : %d", stackTop(top));
    printf("\n\nThe Bottom element is : %d", stackBottom(top));

    return 0;
}
