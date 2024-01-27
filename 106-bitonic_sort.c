#include "sort.h"

void bitonic_merge(int *arr, int left, int right, int isIncreasing)
{
	int temp, i, step = (left + right) / 2, mid = (right - left + 1) / 2;

	if (right - left >= 1)
	{
		for (i = left; i < left + mid; i++)
		{
			if (isIncreasing == (arr[i] > arr[i + mid]))

			{
				temp = arr[i + mid];
				arr[i + mid] = arr[i];
				arr[i] = temp;
			}
		}

		bitonic_merge(arr, left, step, isIncreasing);
		bitonic_merge(arr, step + 1, right, isIncreasing);
	}
}

void bitonic_rec(int *arr, int left, int right, int isIncreasing, size_t size) 
{
    int step;

    if (right - left >= 1) {
        step = (right + left) / 2;

        printf("Merging [%d/%lu] ", right - left + 1, size);
        if (isIncreasing) {
            printf("(UP):\n");
        } else {
            printf("(DOWN):\n");
        }
        print_array(arr + left, right - left + 1);

        bitonic_rec(arr, left, step, 1, size);
        bitonic_rec(arr, step + 1, right, 0, size);
        bitonic_merge(arr, left, right, isIncreasing);

        printf("Result [%d/%lu] ", right - left + 1, size);
        if (isIncreasing) {
            printf("(UP):\n");
        } else {
            printf("(DOWN):\n");
        }
        print_array(arr + left, right - left + 1);
    }
}

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_rec(array, 0, size - 1, 1, size);
}
