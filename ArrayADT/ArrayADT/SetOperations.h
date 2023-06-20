#include "Array.h"

#include <stdlib.h>

#ifndef SetOperations_H
#define SetOperations_H

// Perform union of two sets on two sorted arrays;
int* Union(Array* leftArray, Array* rightArray)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int leftArrayLength = leftArray->length;
    int rightArrayLength = rightArray->length;

    int* a = (int*)malloc(sizeof(int) * (leftArrayLength + rightArrayLength));

    while(i < leftArray->length && j < rightArray->length) {

        if(k > 0) {

            if(leftArray->A[i] == a[k - 1]) {
                i++;
                continue;
            }

            if(rightArray->A[j] == a[k - 1]) {
                j++;

                continue;
            }
        }

        if(leftArray->A[i] < rightArray->A[j]) {

            a[k++] = leftArray->A[i++];
        } else if(leftArray->A[i] == rightArray->A[j]) {

            a[k++] = rightArray->A[j++];
            i++;
        } else {
            a[k++] = rightArray->A[j++];
        }
    }

    while(i < leftArrayLength) {

        if(leftArray->A[i] == a[k - 1]) {
            i++;
            continue;
        }
        a[k++] = leftArray->A[i++];
    }

    while(j < rightArrayLength) {

        if(rightArray->A[j] == a[k - 1]) {
            j++;

            continue;
        }
        a[k++] = rightArray->A[j++];
    }

    return a;
}

// Take only elements occurring in both sorted sets
int* Intersection(Array* leftArray, Array* rightArray)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int leftArrayLength = leftArray->length;
    int rightArrayLength = rightArray->length;

    int* a = (int*)malloc(sizeof(int) * (leftArrayLength + rightArrayLength));

    while(i < leftArray->length && j < rightArray->length) {

        if(leftArray->A[i] < rightArray->A[j]) {

            i++;
        } else if(leftArray->A[i] == rightArray->A[j]) {

            a[k++] = rightArray->A[j++];
            i++;
        } else {
            j++;
        }
    }

    return a;
}

// Select only elements occuring in leftArray
int* Difference(Array* leftArray, Array* rightArray)
{

    int i = 0;
    int j = 0;
    int k = 0;
    int leftArrayLength = leftArray->length;
    int rightArrayLength = rightArray->length;

    int* a = (int*)malloc(sizeof(int) * (leftArrayLength + rightArrayLength));

    while(i < leftArray->length && j < rightArray->length) {

        if(leftArray->A[i] < rightArray->A[j]) {

            a[k++] = leftArray->A[i++];
        } else if(leftArray->A[i] == rightArray->A[j]) {

            j++;
            i++;
        } else {
            j++;
        }
    }

    while(i < leftArrayLength) {
        a[k++] = leftArray->A[i++];
    }

    return a;
}

#endif