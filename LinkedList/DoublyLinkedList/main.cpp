#include <iostream>

struct Node {

    struct Node* prev;
    int data;
    struct Node* next;
}* first = NULL;

void create(int A[], int n)
{

    struct Node *t, *last;

    int i;

    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i = 1; i < n; i++) {

        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p)
{

    while(p) {

        printf("%d ", p->data);
        p = p->next;
    }
}

int length(Node* p)
{

    if(p == NULL) {
        return 0;
    }

    return length(p->next) + 1;
}

void Insert(Node* p, int val, int pos)
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));

    if(pos == 0) {

        t->data = val;
        first->prev = t;
        t->next = first;
        t->prev = NULL;
        first = t;

    } else {

        for(int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->data = val;
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void Delete(Node* p, int pos)
{

    if(pos < 0 || pos > length(p)) {
        return;
    }

    if(pos == 0) {

        first = first->next;
        delete first->prev;
        first->prev = NULL;

    } else {

        for(int i = 0; i < pos; i++) {

            p = p->next;
        }

        Node* toDelete = p;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        delete toDelete;
    }
}

void Reverse(Node* p)
{

    Node* temp;
    while(p) {

        temp = p->next;

        p->next = p->prev;
        p->prev = temp;
        if(p->prev == NULL) {
            first = p;
        }
        p = p->prev;
    }
}

int Mid(Node * p){


    Node * fast = p->next;
    Node * slow  = p;

    while (fast && fast->next){

        fast = fast->next->next;
        slow = slow->next;

    }


    return slow->data;
}

int main()
{
    std::cout << "Hello Testing!" << std::endl;

    int A[] = { 12, 45, 23, 5, 234, 876, 235};

    create(A, 7);

    //    Insert(first, 456, 2);
    //
    //
    //    Insert(first, 458978, 0);
    //    Delete(first, 1);
    //    Delete(first, 7);
    Reverse(first);
    Display(first);
    printf("\n%d ", length(first));
    printf("\nMid: %d ", Mid(first));
    return 0;
}