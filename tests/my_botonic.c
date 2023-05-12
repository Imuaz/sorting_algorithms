#include "sort.h"

/*void print_array(int *array, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
*/
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t i;
        for (i = start; i < start + mid; i++)
        {
            if ((array[i] > array[i + mid] && dir == 1) ||
                (array[i] < array[i + mid] && dir == 0))
            {
                swap_ints(&array[i], &array[i + mid]);
                print_array(array, size);
            }
        }
        bitonic_merge(array, start, mid, dir);
        bitonic_merge(array, start + mid, mid, dir);
    }
}

void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        bitonic_sort_recursive(array, start, mid, 1);
        bitonic_sort_recursive(array, start + mid, mid, 0);
        bitonic_merge(array, start, size, dir);
    }
}

void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
/*
int main()
{
    int array[] = {7, 3, 1, 8, 4, 9, 2, 6};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, size);

    bitonic_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}*/
