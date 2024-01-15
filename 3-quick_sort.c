#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int i, j, pivot, temp, high, low;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;
	pivot = array[high];

	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	if (i > low)
		quick_sort(array, i);
	if (i + 2 < high)
		quick_sort(&array[i + 2], size - i - 2);
}
