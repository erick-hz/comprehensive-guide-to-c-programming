// malloc(Memory Allocation)
// Allocates a specified number of bytes
// Returns a pointer to the allocated memory
// or NULL if the allocation fails.The memory is not initialized.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n = 5;

    // Allocate memory using malloc
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and print array elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory using realloc
    n = 10;
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initialize new elements and print all elements
    for (int i = 5; i < n; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
