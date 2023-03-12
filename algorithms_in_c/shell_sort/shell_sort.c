/*
* Source: https://www.geeksforgeeks.org/shellsort/
*/

// C++ implementation of Shell Sort adapted to C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/read_from_file.h"

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
    int *arr;
    int n;
    n = readFromFile(argv[1], &arr);


    clock_t begin = clock();
	shellSort(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Shell sort for %s took %fs\n", argv[1], time_spent);

    free(arr);
	return 0;
}
