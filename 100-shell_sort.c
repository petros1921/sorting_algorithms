#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t space = 0, m, n;
	int p;

	if (size < 2)
		return;

	while ((space = space * 3 + 1) < size)
		;

	space = (space - 1) / 3;

	for (; space > 0; space = (space - 1) / 3)
	{
		for (n = space; n < size; n++)
		{
			p = array[n];
			for (m = n; m >= space && p <= array[m - space]; m -= space)
				array[m] = array[m - space];
			array[m] = p;
		}
		print_array(array, size);
	}
}
