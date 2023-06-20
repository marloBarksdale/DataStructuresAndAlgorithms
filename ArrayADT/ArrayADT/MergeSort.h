#include "Array.h"

#include <stdio.h>
#include <stdlib.h>

void merge(Array* a, int l, int m, int r);

void mergeSort(Array* a, int l, int r)
{

    if(l < r) {

        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void merge(Array* a, int l, int m, int r)
{

    int leftArraySize = m -l+1;
    int rightArraySize = r - m;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for(int i = 0; i < leftArraySize; i++) {

        leftArray[i] = a->A[l + i];
    }

    for(int j = 0; j < rightArraySize; j++) {

        rightArray[j] = a->A[m + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < leftArraySize && j < rightArraySize) {

        if(leftArray[i] <= rightArray[j]) {

            a->A[k++] = leftArray[i++];
        } else {
            a->A[k++] = rightArray[j++];
        }
    }

    while(i < leftArraySize) {
        a->A[k++] = leftArray[i++];
    }

    while(j < rightArraySize) {
        a->A[k++] = rightArray[j++];
    }
}