/**
 * Source: https://www.geeksforgeeks.org/selection-sort/
 **/

// C program for implementation of selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/read_from_file.h"
#include "../utils/swap.h"

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// Driver program to test above functions
int main(int argc, char *argv[])
{
    printf("Reading %s for selection sort\n\n", argv[1]);
    int *arr;
    int n;
    n = readFromFile(argv[1], &arr);

    clock_t begin = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Took %fs\n", time_spent);

    free(arr);
    return 0;
}

