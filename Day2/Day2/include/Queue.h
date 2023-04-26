#ifndef QUEUE_H
#define QUEUE_H

#define MaxQueSize 5

typedef struct Queue
{
    int Items[MaxQueSize];
    int front, rear;

}Queue;

void EnQueue(Queue *q, int data)
{
    if(q->rear == MaxQueSize - 1)
        return;

    if(q->front == -1)
        q->front++;

    q->rear++;
    q->Items[q->rear] = data;
}

int DeQueue(Queue *q, int *data)
{
    if(q->front == -1)
        return 0;

    *data = q->Items[q->front];
    q->front++;

    return 1;
}



#endif // QUEUE_H
