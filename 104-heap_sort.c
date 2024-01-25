#include "sort.h"

void int_swaper(int *a1, int *a2)
{
	int tempo;

	tempo = *a1;
	*a1 = *a2;
	*a2 = tempo;
}

void adjust_heap(int *arr, size_t arr_size, size_t heap_size, size_t parent)
{
	size_t left_child, right_child, largest;

	left_child = 2 * parent + 1;
	right_child = 2 * parent + 2;
	largest = parent;

	if (left_child < heap_size && arr[left_child] > arr[largest])
		largest = left_child;
	if (right_child < heap_size && arr[right_child] > arr[largest])
		largest = right_child;

	if (largest != parent)
	{
		int_swaper(arr + parent, arr + largest);
		print_array(arr, arr_size);
		adjust_heap(arr, arr_size, heap_size, largest);
	}
}

void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;
	for (index = (size / 2) - 1; index >= 0; index--)
		adjust_heap(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		int_swaper(array, array + index);
		print_array(array, size);
		adjust_heap(array, size, index, 0);
	}
}
