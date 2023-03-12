#include <stdio.h>
#include <stdlib.h>

#include "read_from_file.h"

int readFromFile(char *filename, int **arr)
{
    FILE *file = fopen(filename, "r");
    int n;
    fscanf(file, "%d", &n);

    *arr = (int*)malloc(n*sizeof (int));
    for(int i = 0; i<n; i+=1) {
        fscanf(file, "%d", &(*arr)[i]);
    }

	fclose(file);
    return n;
}