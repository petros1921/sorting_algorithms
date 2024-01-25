#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array, max_value, element, first_loop, second_loop;
	size_t loop_i, loop_k, loop_m, loop_n;

	if (size < 2)
		return;

	max_value = array[0];
	for (loop_i = 1; loop_i < size; loop_i++)
		if (array[loop_i] > max_value)
			max_value = array[loop_i];

	count_array = malloc(sizeof(size_t) * (max_value + 1));
	output_array = malloc(sizeof(int) * size);

	for (first_loop = 0; first_loop <= max_value; first_loop++)
		count_array[first_loop] = 0;

	for (loop_k = 0; loop_k < size; loop_k++)
	{
		element = array[loop_k];
		count_array[element] += 1;
	}
	for (second_loop = 1; second_loop <= max_value; second_loop++)
		count_array[second_loop] += count_array[second_loop - 1];

	print_array(count_array, max_value + 1);
	for (loop_m = 0; loop_m < size; loop_m++)
	{
		output_array[count_array[array[loop_m]] - 1] = array[loop_m];
		count_array[array[loop_m]]--;
	}
	for (loop_n = 0; loop_n < size; loop_n++)
		array[loop_n] = output_array[loop_n];
	free(count_array);
	free(output_array);
}
