#include <iostream>

struct Node {

    int data;
    Node* next;
};

struct Queue {

    Node* first;
    Node* last;
};

void enqueue(Queue* q, int x)
{

    Node* t = (Node*)malloc(sizeof(Node));
    if(!t)
        return;
    t->data = x;
    if(q->first == NULL) {
        q->first = q->last = t;

    } else {

        q->last->next = t;
        q->last = t;
    }
}

void display(Queue* q)
{

    Node* p = q->first;
    while(p) {

        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

int dequeue(Queue* q)
{

    if(q->first == NULL)
        return -1;

    int x = q->first->data;

    q->first = q->first->next;

    return x;
}

int main()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q);

    enqueue(q, 435);
    enqueue(q, 8453);
    enqueue(q, 943);

    display(q);
}