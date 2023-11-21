#include "sort.h"

/**
 * merge_arrays - sorts a subarray of integers
 * @arr: a subarray of an array of integers to sort
 * @temp: a buffer to store the sorted subarray
 * @start: the start index of the array
 * @mid: the mid index of the array
 * @end: the end index of the array
 *
 * Return: nothing
 */
void merge_arrays(int *arr, int *temp, size_t start, size_t mid, size_t end)
{
	size_t x, y;
	size_t z = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + start, mid - start);

	printf("[right]: ");
	print_array(arr + mid, end - mid);

	for (x = start, y = mid; x < mid && y < end; z++)
		temp[z] = (arr[x] < arr[y]) ? arr[x++] : arr[y++];

	for (; x < mid; x++)
		temp[z++] = arr[x];

	for (; y < end; y++)
		temp[z++] = arr[y];

	for (x = start, z = 0; x < end; x++)
		arr[x] = temp[z++];

	printf("[Done]: ");
	print_array(arr + start, end - start);
}

/**
 * recursive_merge_sort - implements the merge sort algorithm through recursion
 * @arr: a subarray of an array of integers to sort
 * @temp: a buffer to store the sorted result
 * @start: the start index of the subarray
 * @end: the end index of the subarray
 *
 * Return: nothing
 */
void recursive_merge_sort(int *arr, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		recursive_merge_sort(arr, temp, start, mid);
		recursive_merge_sort(arr, temp, mid, end);
		merge_arrays(arr, temp, start, mid, end);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order
 * using the merge sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	recursive_merge_sort(array, temp, 0, size);
	free(temp);
}
