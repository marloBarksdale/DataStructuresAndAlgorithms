#include <iostream>
using namespace std;

struct Node {

    int data;
    struct Node* next;
};

struct LinkedList {

    Node* head = NULL;
    Node* last = NULL;
};

void add(LinkedList* list, int num)
{

    if(list->head == NULL) {

        list->head = (struct Node*)malloc(sizeof(struct Node));
        list->head->data = num;

        list->head->next = list->head;
        list->last = list->head;
        list->last->next = list->head;

        return;
    }

    struct Node* next = (struct Node*)malloc(sizeof(struct Node));

    next->data = num;
    next->next = list->head;
    list->last->next = next;
    list->last = next;
};

LinkedList* create(int A[], int n)
{

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));

    for(int i = 0; i < n; i++) {

        add(list, A[i]);
    }

    return list;
}

void displayRecursive(Node* head)
{

    if(head == NULL) {
        return;
    }

    static Node* p = head;
    if(p == NULL) {
        printf("\n");
        p = head;
    }
    printf("%d ", head->data);

    if(head->next != p) {
        displayRecursive(head->next);
    }

    p = NULL;
    return;
}

void insert(Node* head, int pos, int data)
{

    Node* p = head;

    for(int i = 0; i < pos - 1 && p; i++) {

        p = p->next;
    }

    if(p == NULL) {
        return;
    }
    Node* t = (struct Node*)malloc(sizeof(struct Node));

    t->data = data;
    t->next = p->next;
    p->next = t;
}

void deleteNode(Node * head, int pos, LinkedList* list)
{

    Node *p = head;

    if(pos == 1) {

        while(p->next != head) {

            p = p->next;
        }

        if(p == head) {
            delete head;
            head = NULL;
        } else {
            p->next = head->next;

            list->head = p->next;
        }
    } else {

        for(int i = 0; i < pos - 2; i++) {

            p = p->next;
        }

        Node* q = p->next;
        p->next = p->next->next;

        delete q;
    }
}

int main()
{

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));

    int A[] = { 234, 456, 32454, 12, 2354 };

    struct LinkedList* list2 = create(A, 5);
    add(list, 45);
    add(list, 31);
    add(list, 35);
    add(list, 3456);
    add(list, 356);

    insert(list2->head, 3, 9876);

    //    displayRecursive(list2->head);

    printf("\n%d \n", list->head->data);
    deleteNode(list->head, 1, list);
    //    deleteNode(list->head, 1);

    printf("\n%d \n", list->head->data);
    displayRecursive(list->head);
}