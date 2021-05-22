#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *qe)
{
    if ((qe->f) == ((qe->r + 1) % qe->size))
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *qe)
{
    if ((qe->r) == qe->f)
    {
        return 1;
    }
    return 0;
}
int enqueue(struct circularQueue *q, int val)
{
    if (!isFull(q))
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        return val;
    }
    printf("Stackoverflow.\n");
    return 0;
}
int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (!isEmpty(q))
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        return a;
    }
    printf("Stackunderflow. \n");
    return 0;
}

int main()
{
    struct circularQueue qe;
    qe.size = 100;
    qe.f = qe.r = 0;
    qe.arr = (int *)malloc(qe.size * sizeof(int));

    // Enqueue
    printf("\n%d is enqueued.\n", enqueue(&qe, 131));
    printf("%d is enqueued.\n", enqueue(&qe, 133));

    // Dequeue
    printf("\n%d is dequeued.\n", dequeue(&qe));
    printf("%d is dequeued.\n", dequeue(&qe));
    printf("%d is dequeued.\n", dequeue(&qe));

    if (isEmpty(&qe))
    {
        printf("\nQueue is empty");
    }
    if (isFull(&qe))
    {
        printf("\nQueue is Full");
    }

    return 0;
}