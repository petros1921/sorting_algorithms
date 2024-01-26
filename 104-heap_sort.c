#include "sort.h"

/**
 * int_swaper - Swaps the values of two integer variables.
 * @a1: Pointer to the first integer variable
 * @a2: Pointer to the second integer variable
 * By Kidus Yohannes and Petros Worku.
 */
void int_swaper(int *a1, int *a2)
{
	int tempo;

	tempo = *a1;
	*a1 = *a2;
	*a2 = tempo;
}

/**
 * adjust_heap - Adjusts the heap to maintain the heap property.
 * @arr: Pointer to the array representing the heap
 * @arr_size: Size of the original array
 * @heap_size: Size of the heap
 * @parent: Index of the parent node to adjust
 * By Kidus Yohannes and Petros Worku.
 */
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

/**
 * heap_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * By Kidus Yohannes and Petros Worku.
 */
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
