#include "sort.h"

/**
 * shell_sort - function that sort an array of integers in ascending order
 * using the knuth sequence
 * @array: An array of integers
 * @size: size of the array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (gap = 1; gap < (size / 3);)
	{
		gap = gap * 3 + 1;
	}

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				temp_swap(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * temp_swap - this function swaps two pointers to integers
 *
 * @x: first integer pointer
 * @y: second integer pointer
 */
void temp_swap(int *x, int *y)
{
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;

}
