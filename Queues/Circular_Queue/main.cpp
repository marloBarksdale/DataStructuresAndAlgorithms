#include <iostream>

struct Queue {

    int front;
    int size;
    int rear;
    int* Q;
};

void enqueue(Queue* q, int x)
{
    int next = (q->rear + 1) % q->size;

    if(next != q->front) {

        q->rear = next;

        q->Q[next] = x;
    }
}

int dequeue(Queue* q)
{

    if(q->rear == q->front) {
        return -1;
    } else {

        int x = q->Q[(q->front + 1) % q->size];
        q->front = (q->front + 1) % q->size;

        return x;
    }
}

void display(Queue* q)
{

    int pointer = q->front;
    while(pointer != q->rear) {

        printf("%d ", q->Q[(pointer + 1)%q->size]);

        pointer = (pointer + 1) % q->size;
    }

    printf("\n");
}

int main()
{

    printf("Enter the size: ");
    Queue q;
    scanf("%d", &q.size);

    q.Q = (int*)malloc(q.size * sizeof(int));
    q.front = q.rear = 0;

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
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));

    display(&q);

    enqueue(&q, 15);
    enqueue(&q, 46);
    enqueue(&q, 77);
    enqueue(&q, 28);
    enqueue(&q, 2678);
    enqueue(&q, 238);

    display(&q);


        printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));

        display(&q);

}