#include "sort.h"

/**
 * create_copy - Creates a copy of the original array.
 * @original: The original array to be copied.
 * @size: The size of the array.
 *
 * Return: A copy of the original array.
 */
int *create_copy(const int *original, size_t size)
{
	int *copy = malloc(sizeof(int) * size);
	size_t i;

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		copy[i] = original[i];

	return (copy);
}
/**
 * find_max_value - Finds the maximum value in the array.
 * @array: The array to find the maximum value from.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int find_max_value(const int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Function that sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *array_copy = NULL;
	int max_value;
	int *count = NULL;
	size_t b, temp, total = 0;
	int i;

	if (array == NULL || size < 2)
		return;

	array_copy = create_copy(array, size);
	if (array_copy == NULL)
		return;

	max_value = find_max_value(array, size);

	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
	{
		free(array_copy);
		return;
	}
	for (i = 0; i <= max_value; i++)
	{
		count[i] = 0;
	}
	for (b = 0; b < size; b++)
	{
		count[array[b]] += 1;
	}

	for (i = 0; i <= max_value; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (b = 0; b < size; b++)
	{
		array[count[array_copy[b]]] = array_copy[b];
		count[array_copy[b]] += 1;
	}

	print_array(count, max_value + 1);
	free(count);
	free(array_copy);
}
