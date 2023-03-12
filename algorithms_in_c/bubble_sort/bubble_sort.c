// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/read_from_file.h"
#include "../utils/print_array.h"
#include "../utils/swap.h"

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


// Driver program to test above functions
int main(int argc, char *argv[])
{
    int *arr;
    int n;
	
    n = readFromFile(argv[1], &arr);

    clock_t begin = clock();
	bubbleSort(arr, n);
    clock_t end = clock();

    free(arr);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Bubble sort for %s took %fs\n", argv[1], time_spent);
	return 0;
}
