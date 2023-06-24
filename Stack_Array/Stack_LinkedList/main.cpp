#include <iostream>

class push;
struct Node {

    char data;
    struct Node* next;
}* top = NULL;

void push(char x)
{

    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL) {
        printf("stack is full");
    } else {

        t->data = x;
        t->next = top;
        top = t;
    }
}

int peek()
{

    if(top == NULL)
        return -1;

    else
        return top->data;
}

void Display()
{

    Node* t = top;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

bool isEmpty() { return top == NULL; }

char pop()
{

    if(top == NULL)
        return -1;

    Node* t = top;
    top = top->next;

    char x = t->data;

    free(t);

    return x;
}

bool isBalanced(char* exp)
{

    int i;

    for(i = 0; exp[i] != '\0'; i++) {

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
//            printf("%c ", exp[i]);
        } else if((exp[i]!=42) && (peek() == exp[i]-1 || peek()==exp[i]-2)){
//            printf("%d", exp[i]);
            if(isEmpty())
                return false;
            pop();
        }
    }

    return isEmpty();
}

int main()
{

    char* exp = "a+b(*(c-d))";

    printf("%d\n", isBalanced(exp));

    return 0;
}