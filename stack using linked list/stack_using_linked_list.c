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
        printf("The valueis: %d\n", ptr->data);
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

int main()
{
    struct Node *top = NULL;
    top = push(top, 89);
    top = push(top, 8219);
    top = push(top, 56);
    linkedListTraversel(top);
    printf("\n%d is poped.\n", pop(&top));
    linkedListTraversel(top);
    return 0;
}