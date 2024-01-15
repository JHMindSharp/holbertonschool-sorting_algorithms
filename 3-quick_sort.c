#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Helper function to perform quicksort recursively.
 * @array: The array to sort.
 * @low: The lowest index of the sub-array to sort.
 * @high: The highest index of the sub-array to sort.
 * @size: The size of the array.
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: The array to sort.
 * @low: The lowest index of the sub-array to partition.
 * @high: The highest index of the sub-array to partition.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
