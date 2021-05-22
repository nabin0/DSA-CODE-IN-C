#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversel(struct Node *h)
{
    while (h != NULL)
    {
        printf("THe value of element in queue is %d\n", h->data);
        h = h->next;
    }
}

int isEmpty()
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

int enqueue(int val)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if (q == NULL)
    {
        printf("Invalid Params\n");
    }
    else
    {
        q->data = val;
        q->next = NULL;
        if (f == NULL)
        {
            f = r = q;
        }
        r->next = q;
        r = q;
        return val;
    }
}
int dequeue()
{
    int val = -1;
    if (isEmpty(f))
    {
        printf("Invalid Params\n");
        return val;
    }
    else
    {
        struct Node *temp = f;
        f = f->next;
        val = temp->data;
        free(temp);
        return val;
    }
}

int main()
{

    printf("Enqueue.\n");

    int i = 0;
    while (i < 5)
    {
        int a;
        printf("Enter Value.\n");
        scanf("%d", &a);
        printf("The value %d is queued\n", enqueue(a));
        i++;
    }

    printf("\nPrinting Elements in the queue.\n");
    linkedListTraversel(f);
    printf("\nDequeue.\n");
    printf("The value %d is dequeued\n", dequeue());
    printf("The value %d is dequeued\n", dequeue());
    printf("The value %d is dequeued\n", dequeue());
    printf("\nPrinting Elements in the queue.\n");
    linkedListTraversel(f);

    return 0;
}
