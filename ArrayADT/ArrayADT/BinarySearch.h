#include "Array.h"

#include <stdio.h>
#include <stdlib.h>

int binarySearch(Array* a, int key)
{

    int low = 0;
    int high = a->length-1;




    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(a->A[mid] == key) {
            return mid;
        }

        else if(a->A[mid] > key) {

            high = mid - 1;
        } else if(a->A[mid] < key) {

            low = mid + 1;
        }
    }

    return -1;
}