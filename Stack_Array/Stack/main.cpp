#include "stdio.h"

#include <iostream>

struct Stack {

    int top;
    int size;
    int* S;
};

void create(struct Stack* st)
{

    printf("Enter size ");
    scanf("%d", &st->size);

    st->top = -1;
    st->S = (int*)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{

    for(int i = st.top; i >= 0; i--) {

        printf("%d ", st.S[i]);
    }

    printf("\n");
}

void push(struct Stack* st, int x)
{

    if(st->top == st->size - 1) {

        printf("Stack overflow\n");
    } else {

        st->S[++st->top] = x;
    }
}

int pop(Stack* st)
{

    if(st->top > 0) {

        return st->S[st->top--];
    }

    return -1;
}

int peek(struct Stack st, int index)
{

    if(st.top - index >= 0) {
        return st.S[st.top - index + 1];
    }

    return -1;
}

int main()
{

    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 32230);
    push(&st, 2340);
    push(&st, 654730);

    pop(&st);
    pop(&st);

    printf("\n%d \n", peek(st, 1)
    );

    Display(st);
}