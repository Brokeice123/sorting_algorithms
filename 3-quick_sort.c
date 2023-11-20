#include "sort.h"

int lomuto_partition(int *array, int left, int right, size_t size);
void lomuto_quicksort(int *array, int left, int right, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, 0, size - 1, size);
}

/**
 * lomuto_quicksort - sorts an array of integers in ascending order
 * using the Lomuto partition scheme
 * @array: array of integers
 * @left: left most index
 * @right: right most index
 * @size: size of the array
 *
 */

void lomuto_quicksort(int *array, int left, int right, size_t size)
{
	int p;

	if (left < right)
	{
		p = lomuto_partition(array, left, right, size);
		lomuto_quicksort(array, left, p - 1, size);
		lomuto_quicksort(array, p + 1, right, size);
	}
}

/**
 * lomuto_partition - sorts an array of integers in ascending order
 * using the Lomuto partition scheme
 * @array: array of integers
 * @left: left most index
 * @right: right most index
 * @size: size of the array
 *
 * Return: partition index
 */

int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	int j, temp;

	for (j = left; j < right; j++)
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
	if (i + 1 != j)
	{
		temp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
