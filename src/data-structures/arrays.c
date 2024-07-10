#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array;
    int size = 5;

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));

    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }

    // Print the array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    // Free the allocated memory
    free(array);

    return 0;
}
