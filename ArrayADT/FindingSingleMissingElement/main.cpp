#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int findMissingElementOfNaturalNumbers(int* array, int size);
void findMissingElementNotStartingFromOne(int* array, int size);
void findMissingElementsInUnsortedList(int* array, int size, int max);
void findDuplicateElementsinSortedList(int* array, int size);
void findDuplicateElementsinSortedListWithHash(int* array, int size, int max);
void findAPairOfELementsWithSum(int* array, int size, int max, int k);
void findAPairOfELementsWithSumInSortedArray(int* array, int size, int max, int k);
void findMaxAndMinSingleScan(int* array, int size);
int main()
{

    //    int array[] = { 1, 2, 3, 4, 5, 7, 9, 10, 21, 22, 23, 24, 26, 28, 29, 30 };
    int array[] = { 15, 26, 33, 14, 45, 364567, 356, 1123, 98, 3523, 987, 244, 2236, 21238, 23459, 230 };

    //    printf("Missing number is %d\n", findMissingElementOfNaturalNumbers(array, 9));

    //    findMissingElementNotStartingFromOne(array, 17);

    //    findMissingElementsInUnsortedList(array, 16, 28);

    //    findDuplicateElementsinSortedListWithHash(array, 16, 28);

    //    findDuplicateElementsinSortedList(array, 16);

    // findAPairOfELementsWithSumInSortedArray(array, 16, 28, 30);

    findMaxAndMinSingleScan(array, 16);
}

int findMissingElementOfNaturalNumbers(int* array, int size)
{

    // Formula for the sum of n natural numbers is n(n+1)/2

    int sumOfNaturalNumbers = (size * (size + 1)) / 2;

    int arraySum = 0;
    for(int i = 0; i < size - 1; i++) {

        arraySum += array[i];
    }

    if(sumOfNaturalNumbers == arraySum) {
        return 0;
    }

    return sumOfNaturalNumbers - arraySum;
}

void findMissingElementNotStartingFromOne(int* array, int size)
{

    // Find difference of first element and index;

    int difference = array[0] - 0;

    for(int i = 0; i < size; i++) {
        if((array[i] - i) != difference) {

            while(difference < array[i] - i) {
                printf("Missing element is %d\n", i + difference);
                difference++;
            }

            // Change difference to find anymore missing elements
        }
    }
}

void findMissingElementsInUnsortedList(int* array, int size, int max)
{

    int hashTable[max + 1] = { 0 };

    for(int i = 0; i < size; i++) {
        hashTable[array[i]] = 1;
    }

    for(int x = 0; x < max; x++) {

        if(hashTable[x] == 0) {

            printf("%d missing\n", x);
        }
    }
}

void findDuplicateElementsinSortedList(int* array, int size)
{

    //    int lastDuplicate = 0;

    for(int i = 0; i < size; i++) {

        if(array[i] == array[i + 1]) {

            int j = i + 1;
            while(array[j] == array[i])
                j++;
            printf("%d appeared %d times.\n", array[i], j - i);
            i = j - 1;
        }
    }
}

void findDuplicateElementsinSortedListWithHash(int* array, int size, int max)
{

    int hashTable[max + 1] = { 0 };

    for(int i = 0; i < size; i++) {

        hashTable[array[i]]++;
    }

    for(int i = 0; i < max + 1; i++) {

        if(hashTable[i] > 1) {
            printf("%d appeared %d times.\n", i, hashTable[i]);
        }
    }
}

void findAPairOfELementsWithSum(int* array, int size, int max, int k)
{

    int hashTable[max + 1] = { 0 };

    for(int i = 0; i < size; i++) {

        int difference = k - array[i];
        if(difference < 0) {
            hashTable[array[i]] = i;
            continue;
        }

        if(hashTable[difference] > 0) {
            printf("%d %d", i, hashTable[difference]);
            break;
        } else {

            hashTable[array[i]] = i;
        }
    }
}

void findAPairOfELementsWithSumInSortedArray(int* array, int size, int max, int k)
{

    int i = 0;
    int j = size - 1;
    while(i < j) {

        if((array[i] + array[j]) == k) {

            printf("%d %d\n", i, j);
            i++;
            j--;

        } else if(array[i] + array[j] > k) {

            j--;

        } else {

            i++;
        }
    }
}

void findMaxAndMinSingleScan(int* array, int size)
{

    int min = 0;
    int max = 0;

    for(int i = 0; i < size; i++) {

        if(array[min] > array[i]) {
            min = i;
        }

        if(array[max] < array[i]) {
            max = i;
        }
    }

    printf("%d %d\n", min, max);
}