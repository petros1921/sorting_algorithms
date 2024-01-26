#include "sort.h"

/**
 * find_maximum - Finds the maximum value in an array.
 * @arr: Pointer to the array
 * @arr_size: Size of the array
 * Returns: The maximum value in the array
 * By Kidus Yohannes and Petros Worku
 */
int find_maximum(int *arr, int arr_size)
{
	int maximum_value, i;

	for (maximum_value = arr[0], i = 1; i < arr_size; i++)
	{
		if (arr[i] > maximum_value)
			maximum_value = arr[i];
	}

	return maximum_value;
}

/**
 * coun_sort - Performs counting sort based on a specific significant digit.
 * @arr: Pointer to the array to be sorted
 * @arr_size: Size of the array
 * @sig_digit: The significant digit to consider for sorting
 * @buff: Temporary buffer array for sorting
 * By Kidus Yohannes and Petros Worku
 */
void coun_sort(int *arr, size_t arr_size, int sig_digit, int *buff)
{
	int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < arr_size; index++)
		digit_count[(arr[index] / sig_digit) % 10] += 1;

	for (index = 1; index < 10; index++)
		digit_count[index] += digit_count[index - 1];

	for (index = arr_size - 1; (int)index >= 0; index--)
	{
		buff[digit_count[(arr[index] / sig_digit) % 10] - 1] = arr[index];
		digit_count[(arr[index] / sig_digit) % 10] -= 1;
	}

	for (index = 0; index < arr_size; index++)
		arr[index] = buff[index];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * By Kidus Yohannes and Petros Worku
 */
void radix_sort(int *array, size_t size)
{
	int max_sort, signt, *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	max_sort = find_maximum(array, size);
	for (signt = 1; max_sort / signt > 0; signt *= 10)
	{
		coun_sort(array, size, signt, b);
		print_array(array, size);
	}

	free(b);
}

