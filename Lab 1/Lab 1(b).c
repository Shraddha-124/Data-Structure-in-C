#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2;
    int size;

    // Using malloc to allocate memory for an array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr1 = (int *)malloc(size * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocated successfully using malloc.\n");

    // Using free to release the allocated memory
    free(arr1);
    printf("Memory freed using free.\n");

    // Using calloc to allocate and initialize memory for an array
    arr2 = (int *)calloc(size, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocated and initialized to zero using calloc.\n");

    // Using realloc to resize the allocated memory
    int newSize;
    printf("Enter the new size for the array: ");
    scanf("%d", &newSize);

    arr2 = (int *)realloc(arr2, newSize * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("Memory reallocated successfully using realloc.\n");

    // Using free to release the reallocated memory
    free(arr2);
    printf("Memory freed after reallocation using free.\n");

    return 0;
}
