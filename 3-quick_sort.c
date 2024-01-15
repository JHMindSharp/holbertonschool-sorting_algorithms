#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Helper function to perform quicksort recursively.
 * @array: The array to sort.
 * @low: The lowest index of the sub-array to sort.
 * @high: The highest index of the sub-array to sort.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				if (i != j)
				{
					int temp = array[i];

					array[i] = array[j];
					array[j] = temp;
					print_array(array, size);
				}
			}
		}

		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		if (i + 1 != high)
			print_array(array, size);

		quick_sort_recursive(array, low, i, size);
		quick_sort_recursive(array, i + 2, high, size);
	}
}
