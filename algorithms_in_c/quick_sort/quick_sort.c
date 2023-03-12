/**
 * https://www.geeksforgeeks.org/quick-sort/
 */
/* C++ implementation of QuickSort adapted to C */

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/read_from_file.h"
#include "../utils/swap.h"

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i
		= (low
		- 1); // Index of smaller element and indicates
				// the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Driver Code
int main(int argc, char *argv[])
{
    printf("Reading %s for quick sort\n\n", argv[1]);
    int *arr;
    int n;
    n = readFromFile(argv[1], &arr);

    clock_t begin = clock();
	quickSort(arr, 0, n - 1);
    clock_t end = clock();
    free(arr);

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Took %fs\n", time_spent);
	return 0;
}

// This code is contributed by rathbhupendra
