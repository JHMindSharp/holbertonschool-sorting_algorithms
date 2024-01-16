#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Quick Sort algorithm. It implements the Lomuto partition scheme
 * with the pivot as the last element of the partition being sorted.
 * It prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int stack[size];
	int top = -1;
	int i, j;

	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		int high = stack[top--];
		int low = stack[top--];
		int pivot = array[high];
		i = low;

		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				if (i != j)
				{
					print_array(array, size);
				}
				i++;
			}
		}

		int temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		if (i != high)
		{
			print_array(array, size);
		}

		if (low < i - 1)
		{
			stack[++top] = low;
			stack[++top] = i - 1;
		}
		if (i + 1 < high)
		{
			stack[++top] = i + 1;
			stack[++top] = high;
		}
	}
}
