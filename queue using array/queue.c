#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *qe)
{
    if ((qe->f) == (qe->r))
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *qe)
{
    if ((qe->r) == qe->size - 1)
    {
        return 1;
    }
    return 0;
}
int enqueue(struct queue *q, int val)
{
    if (!isFull(q))
    {
        q->r++;
        q->arr[q->r] = val;
        return val;
    }
    return 0;
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (!isEmpty(q))
    {
        q->f++;
        a = q->arr[q->f];
        return a;
    }
    return 0;
}

int main()
{
    struct queue qe;
    qe.size = 100;
    qe.f = qe.r = -1;
    qe.arr = (int *)malloc(qe.size * sizeof(int));

    // Enqueue
    printf("\n%d is enqueued.\n", enqueue(&qe, 131));
    printf("%d is enqueued.\n", enqueue(&qe, 133));

    // Dequeue
    printf("\n%d is dequeued.\n", dequeue(&qe));
    printf("%d is dequeued.\n", dequeue(&qe));

    if (isEmpty(&qe))
    {
        printf("\nQueue is empty");
    }
    if (isFull(&qe))
    {
        printf("\nQueue is empty");
    }

    return 0;
}