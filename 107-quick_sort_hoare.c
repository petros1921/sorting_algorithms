#include "sort.h"

void swap_integers(int *num1, int *num2)
{
	int temporary;

	temporary = *num1;
	*num1 = *num2;
	*num2 = temporary;
}

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, left_index, right_index;

	pivot = array[right];
	for (left_index = left - 1, right_index = right + 1; left_index < right_index;)
	{
		do {
			left_index++;
		} while (array[left_index] < pivot);

		do {
			right_index--;
		} while (array[right_index] > pivot);

		if (left_index < right_index)
		{
			swap_integers(array + left_index, array + right_index);
			print_array(array, size);
		}
	}
	return left_index;
}

void hoare_quicksort(int *array, size_t size, int start, int end)
{
	int partition_index;

	if (end - start > 0)
	{
		partition_index = hoare_partition(array, size, start, end);
		hoare_quicksort(array, size, start, partition_index - 1);
		hoare_quicksort(array, size, partition_index, end);
	}
}

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quicksort(array, size, 0, size - 1);
}
