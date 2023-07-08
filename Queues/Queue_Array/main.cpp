#include <iostream>

struct Queue {

    int front;
    int size;
    int rear;
    int* Q;
};

void enqueue(Queue* q, int x)
{

    if(q->rear == q->size - 1) {

        printf("Queue is full");
    } else {

        q->Q[++q->rear] = x;
    }
}

int dequeue(Queue* q)
{

    if(q->rear == q->front) {
        return -1;
    } else {
        return q->Q[q->front++ + 1];
    }
}

void display(Queue* q)
{

    int pointer = q->front;
    while(pointer != q->rear) {

        printf("%d ", q->Q[pointer++ + 1]);
    }

    printf("\n");
}

int main()
{

    printf("Enter the size: ");
    Queue q;
    scanf("%d", &q.size);

    q.Q = (int*)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    display(&q);

    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));

    display(&q);
}