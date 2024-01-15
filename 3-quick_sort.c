#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers in an array.
 * @a: Pointer to the first integer whose value is swapped.
 * @b: Pointer to the second integer whose value is swapped.
 *
 * Description:
 * This function takes two pointers to integers, 'a' and 'b', and swaps their
 * values in the array they point to. After calling this function, the value
 * originally stored in 'a' will be in 'b', and the value originally stored in
 * 'b' will be in 'a'. This is useful for reordering elements in an array or
 * exchanging values between two integer variables.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort.
 * @array: The array of integers to sort.
 * @low: The lowest index of the sub-array to partition.
 * @high: The highest index of the sub-array to partition.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 *
 * Description:
 * This function takes an array of integers 'array' and partitions it into two
 * sub-arrays around a 'pivot' element using the Lomuto partition scheme. It
 * selects the pivot element, rearranges the elements so that all elements less
 * than the pivot are to its left, and all elements greater than the pivot are
 * to its right. The function returns the final index of the pivot element
 * after the partition is completed. This partitioning process
 * is a crucial step
 * in the Quick Sort algorithm for sorting arrays.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[high] != array[i])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Helper function to perform Quick Sort recursively.
 * @array: The array of integers to sort.
 * @low: The lowest index of the sub-array to sort.
 * @high: The highest index of the sub-array to sort.
 * @size: The size of the array.
 *
 * Description:
 * This function is a helper for the Quick Sort algorithm. It takes an array of
 * integers 'array' and sorts the sub-array between 'low' and 'high' indexes
 * (inclusive) in ascending order. The Quick Sort algorithm works
 * by selecting a pivot element, partitioning the array into two sub-arrays
 * (elements less than the pivot and elements greater than the pivot), and
 * then recursively sorting those sub-arrays. This helper function is called
 * recursively to perform the sorting on each sub-array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *               Sort algorithm with the Lomuto partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description:
 * This function takes an array of integers 'array' and its
 * size 'size' as input and sorts the array in ascending order using
 * the Quick Sort algorithm with the Lomuto partition scheme.
 * Quick Sort is a divide-and-conquer sorting algorithm that works by
 * selecting a pivot element, partitioning the array
 * into two sub-arrays (elements less than the pivot and elements greater than
 * the pivot), and then recursively sorting those sub-arrays. This function
 * serves as the entry point to initiate the Quick Sort process.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
