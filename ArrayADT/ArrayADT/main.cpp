#include "Array.h"
#include "BinarySearch.h"
#include "SetOperations.h"

#include <MergeSort.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void enterElements(Array* a);
void display(Array* a);
void insert(Array* a, int index, int value);
void deleteAtIndex(Array* a, int index);
int linearSearch(Array* a, int key);
int get(Array* a, int index);
void reverse(Array* a);
void insertInSortedList(Array* a, int value);
void moveAllNegativeNumbersToTheLeft(Array* a);
int* mergeArray(Array* leftArray, Array* rightArray);

int main()
{

    int a[] = { 1, 1, 1, 2, 3 };
    int b[]{ 1, 2, 3, 3, 3, 12 };

    Array arr = { a, 5, 5 };
    Array arr2 = { b, 6, 6 };

    //    printf("Enter size of an array ");
    //    scanf("%d", &arr.size);
    //
    //    arr.A = (int*)malloc(arr.size * sizeof(int));
    //    arr.length = 0;

    //    enterElements(&arr);
    //    display(&arr);
    //    insert(&arr, 2, 200);
    //    display(&arr);
    //    deleteAtIndex(&arr, 2);

    mergeSort(&arr, 0, arr.length - 1);
    mergeSort(&arr2, 0, arr2.length - 1);

    int* p = Union(&arr, &arr2);

    Array arr3 = { p, arr.length + arr2.length, arr.length + arr2.length };

    //    reverse(&arr);
    //    display(&arr);
    //
    //    insertInSortedList(&arr, -1000);
    //
    //    insertInSortedList(&arr, 0);
    //    insertInSortedList(&arr, -6);
    //
    //    moveAllNegativeNumbersToTheLeft(&arr);

    //    printf("%d\n", linearSearch(&arr, 3));
    //    printf("%d\n", binarySearch(&arr, 3));

    display(&arr);
    display(&arr2);
    display(&arr3);
}

void enterElements(Array* a)
{

    printf("How many numbers would you like to enter? ");

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        printf("Enter number %d: ", i + 1);

        int x;
        scanf("%d", &x);

        a->A[i] = x;
        a->length++;
    }
}

void display(Array* a)
{

    for(int i = 0; i < a->length; i++) {

        printf("%d ", a->A[i]);
    }
    printf("\n");
}

void insert(Array* a, int index, int value)
{

    for(int i = a->length - 1; i >= index; i--) {

        a->A[i + 1] = a->A[i];
    }

    a->A[index] = value;
    a->length++;
}

void deleteAtIndex(Array* a, int index)
{

    for(int i = index; i < a->length - 1; i++) {

        a->A[i] = a->A[i + 1];
    }

    a->length--;
}

int linearSearch(Array* a, int key)
{

    for(int i = 0; i < a->length; i++) {

        if(a->A[i] == key) {
            return i;
        }
    }

    return -1;
}

int get(Array* a, int index) { return a->A[index]; }
void set(Array* a, int index, int value) { a->A[index] = value; }

void reverse(Array* a)
{

    int length = a->length;
    for(int i = 0; i < a->length / 2; i++) {

        int temp = a->A[i];
        a->A[i] = a->A[length - i - 1];
        a->A[length - i - 1] = temp;
    }
}

void insertInSortedList(Array* a, int value)
{

    int i = a->length - 1;

    // Return if the array is already full
    if(a->length == a->size)
        return;

    // Starting from the end of the array, right shift all values greater than the value to be inserted
    while(value < a->A[i] && i >= 0) {

        a->A[i + 1] = a->A[i];
        i--;
    }

    a->A[i + 1] = value;

    a->length++;
}

//
void moveAllNegativeNumbersToTheLeft(Array* a)
{

    int i = 0;
    int j = a->length - 1;

    while(i < j) {

        while(a->A[i] < 0) {
            i++;
        }

        while(a->A[j] >= 0) {
            j--;
        }

        if(i < j) {

            int temp = a->A[i];
            a->A[i] = a->A[j];
            a->A[j] = temp;
        }
    }
}

int* mergeArray(Array* leftArray, Array* rightArray)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int leftArrayLength = leftArray->length;
    int rightArrayLength = rightArray->length;

    int* a = (int*)malloc(sizeof(int) * (leftArrayLength + rightArrayLength));

    while(i < leftArray->length && j < rightArray->length) {

        if(leftArray->A[i] <= rightArray->A[j]) {

            a[k++] = leftArray->A[i++];
        } else {
            a[k++] = rightArray->A[j++];
        }
    }

    while(i < leftArrayLength) {
        a[k++] = leftArray->A[i++];
    }

    while(j < rightArrayLength) {
        a[k++] = rightArray->A[j++];
    }

    return a;
}