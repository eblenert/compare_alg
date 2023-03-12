/**
 * Source: https://www.geeksforgeeks.org/insertion-sort/
**/

// C program for insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/read_from_file.h"

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/* Driver program to test insertion sort */
int main(int argc, char *argv[])
{
    int *arr;
    int n;

    n = readFromFile(argv[1], &arr);
	clock_t begin = clock();
	insertionSort(arr, n);
    clock_t end = clock();
    free(arr);

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Insertion sort for %s took %fs\n", argv[1], time_spent);
	return 0;
}