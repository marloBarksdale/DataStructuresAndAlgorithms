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

        list->head->next = NULL;
        list->last = list->head;

        return;
    }

    struct Node* next = (struct Node*)malloc(sizeof(struct Node));

    next->data = num;
    next->next = NULL;
    list->last->next = next;
    list->last = next;
};

void display(struct Node* ptr)
{

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    cout << endl;
}

void displayRecursive(struct Node* ptr)
{

    if(ptr == NULL) {
        cout << endl;
        return;
    }

    printf("%d ", ptr->data);
    ptr = ptr->next;
    displayRecursive(ptr);
}

void displayRecursiveReverse(struct Node* ptr)
{

    if(ptr == NULL) {
        cout << endl;
        return;
    }

    displayRecursiveReverse(ptr->next);
    printf("%d ", ptr->data);
}

int countNodes(struct Node* ptr)
{

    if(ptr == NULL) {
        return 0;
    }

    return countNodes(ptr->next) + 1;
}

// Sum of nodes
int sumOfNodes(struct Node* ptr)
{

    if(ptr == NULL) {
        return 0;
    }

    return sumOfNodes(ptr->next) + ptr->data;
}

int maxOfLinkedList(Node* ptr)
{

    struct Node* max = ptr;

    if(max == NULL)
        return INT32_MIN;
    while(ptr != NULL) {

        if(ptr->data > max->data) {

            max = ptr;
        }
        ptr = ptr->next;
    }

    return max->data;
}

int maxOfLinkedListRecursive(struct Node* ptr)
{

    if(ptr == NULL) {
        return INT32_MIN;
    }

    int max = maxOfLinkedListRecursive(ptr->next);

    if(max > ptr->data) {

        return max;
    } else {
        return ptr->data;
    }
}

Node* search(Node* ptr, int key)
{

    while(ptr != NULL) {

        if(ptr->data == key) {
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

Node* Rsearch(Node* ptr, int key)
{

    if(ptr == NULL) {
        return NULL;
    }

    if(ptr->data == key)
        return ptr;

    return Rsearch(ptr->next, key);
}

void insertAtHead(LinkedList* list, int n)
{

    if(list->head == NULL) {

        add(list, n);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = n;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAfter(LinkedList* list, int pos, int val)
{

    struct Node* ptr = list->head;

    while(ptr != NULL && pos > 1) {

        ptr = ptr->next;
        pos--;
    }

    if(ptr == NULL) {
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = ptr->next;
    ptr->next = newNode;
    if(ptr == list->last) {

        list->last = newNode;
    }
}

void insertLast(LinkedList* list, int val)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if(list->head == NULL) {
        list->head = newNode;
        list->last = newNode;

    } else {

        list->last->next = newNode;
        list->last = newNode;
    }
}

void insertSorted(LinkedList* list, int val)
{

    if(countNodes(list->head) == 0) {
        insertAtHead(list, val);
    } else {

        int count = 0;
        Node* ptr = list->head;
        while(ptr != NULL && ptr->data < val) {

            ptr = ptr->next;
            count++;
        }

        if(count == 0) {
            insertAtHead(list, val);
        } else {
            insertAfter(list, count, val);
        }
    }
}

void deleteNode(LinkedList* list, int pos)
{

    if(pos < 0 || pos > countNodes(list->head))
        return;

    Node* ptr = list->head;
    Node* q = NULL;
    for(int i = 1; i < pos; i++) {
        q = ptr;
        ptr = ptr->next;
    }

    if(ptr == list->head) {

        Node* p = list->head;
        list->head = list->head->next;
        delete p;

    } else {

        q->next = ptr->next;

        if(q->next == NULL) {
            list->last = q;
        }
        delete ptr;
    }
}

bool isSorted(LinkedList* list)
{

    Node* p = list->head;

    while(p && p->next) {

        if(p->data > p->next->data) {
            return false;
        }

        p = p->next;
    }

    return true;
}

void removeDuplicates(LinkedList* list)
{

    Node* p = list->head;
    Node* q = p->next;

    while(q) {

        if(p->data != q->data) {

            p = q;
            q = q->next;
        } else {

            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverseLinkedList(LinkedList* list)
{
    Node *p, *q, *r;

    p = list->head;
    r = q = NULL;

    while(p) {

        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    printf("Head: %d\n", list->head->data);

    Node* temp = list->head;
    list->head = list->last;
    list->last = temp;

    printf("Head: %d\n", list->head->data);
}

void reverseLinkedListRecursive(LinkedList* list, Node* q, Node* p)
{

    if(p == NULL) {

        list->head = q;
        return;
    }

    reverseLinkedListRecursive(list, p, p->next);

    p->next = q;
    list->last = p;
}

Node* mergeLinkedList(Node* first, Node* second)
{

    Node* third;
    Node* last;
    Node* mergedHead;

    if(first->data < second->data) {
        mergedHead = third = last = first;
        first = first->next;
        third->next = NULL;
    } else {
        mergedHead = third = last = second;
        second = second->next;
        third->next = NULL;
    }

    while(second && first) {
        if(first->data < second->data) {

            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        } else {

            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }

        if(second) {
            last->next = second;
        } else {
            last->next = first;
        }
    }

    return mergedHead;
}

bool hasLoop(Node* p)
{

    Node* q = p;
    p = p->next->next;

    while(p && p->next) {

        if(p == q) {
            return true;
        }

        q = q->next;
        p = p->next->next;
    }

    return false;
}

int main()
{

    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    struct LinkedList* list2 = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list2->head = NULL;

    //    add(list, 105);
    //    add(list, 878);

    //    add(list, 75);
    //    insertLast(list, 6000);
    insertSorted(list, 42);
    insertSorted(list, 5);
    insertSorted(list, 254);
    insertSorted(list, 34);
    insertSorted(list, 595);
    insertSorted(list, 3343);
    insertSorted(list, 34);
    insertSorted(list, 234);
    insertSorted(list, 2344);
    insertSorted(list2, 734);
    insertSorted(list2, 2234);
    insertSorted(list2, 809);
    insertSorted(list2, 2372);
    insertSorted(list2, 4);
    insertSorted(list2, 15);
    insertSorted(list2, 419);
    insertSorted(list2, 232);
    insertSorted(list2, 663);
    insertSorted(list2, -1);
    insertSorted(list2, -5);

    //    add(list, 200);
    //
    displayRecursive(list->head);
    displayRecursive(list2->head);
    //    displayRecursive(mergeLinkedList(list->head, list2->head));

//   list->last->next = list->last;

    if(hasLoop(list->head)) {

        printf("\ntrue\n");
    } else {
        printf("\nfalse\n");
    }

    //    reverseLinkedListRecursive(list, NULL, list->head);
    //    reverseLinkedListRecursive(list2, NULL, list2->head);
    //    displayRecursive(list->head);
    //    displayRecursive(list2->head);

    //    displayRecursiveReverse(list->head);
    //    insertAfter(list, 4, 45);
    //    displayRecursive(list->head);
    //    add(list, 200);
    //    add(list, 500);
    //    insertAfter(list, 5, 555);
//       displayRecursive(list->head);
//    //    insertAfter(list, 3, 590);

    //    removeDuplicates(list);
    //    displayRecursive(list->head);
    //    cout << endl;
    //    deleteNode(list, 5);
    //    deleteNode(list, 1);
    //    deleteNode(list, 28);
    //    //    insertLast(list, 2);
    //    displayRecursive(list->head);
    //    //    displayRecursiveReverse(list->head);
    //
    //    printf("\n%d nodes.", countNodes(list->head));
    //    printf("\n%d total.", sumOfNodes(list->head));
    //    printf("\n%d max.", maxOfLinkedList(list->head));
    //    int searchVal = 75;
    //
    //    if(isSorted(list)) {
    //        printf("\nis Sorted.");
    //    } else {
    //        printf("\nnot Sorted.");
    //    }
    //
    //    Node* result = search(list->head, searchVal);
    //
    //    if(result != NULL) {
    //
    //        printf("\n%d found.", searchVal);
    //    } else {
    //        printf("\n%d not found.", searchVal);
    //    }
}
