#include "sort.h"

/**
 * adjust_heap - Adjusts a heap
 * @arr: The heap to be adjusted
 * @root: Root of the heap
 * @last_idx: Last index of the heap
 * @arr_size: Size of the array
 *
 * Return: Nothing
 */
void adjust_heap(int *arr, size_t root, size_t last_idx, size_t arr_size)
{
	size_t left_child, right_child, swap_index;
	int temp;

	while ((left_child = (2 * root) + 1) <= last_idx)
	{
		swap_index = root;
		right_child = left_child + 1;
		if (arr[swap_index] < arr[left_child])
		{
			swap_index = left_child;
		}
		if (right_child <= last_idx && arr[swap_index] < arr[right_child])
		{
			swap_index = right_child;
		}
		if (swap_index == root)
		{
			return;
		}

		temp = arr[root];
		arr[root] = arr[swap_index];
		arr[swap_index] = temp;
		print_array(arr, arr_size);
		root = swap_index;
	}
}

/**
 * build_heap - Builds a heap from an unsorted array
 * @arr: Array to turn into a heap
 * @arr_size: Size of the array
 *
 * Return: void
 */
void build_heap(int *arr, size_t arr_size)
{
	size_t parent;

	for (parent = ((arr_size - 1) - 1) / 2; 1; parent--)
	{
		adjust_heap(arr, parent, arr_size - 1, arr_size);
		if (parent == 0)
		{
			break;
		}
	}
}

/**
 * heap_sort - Sorts an array of ints using heap orth algorithm
 * order with the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t last_idx;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	build_heap(array, size);
	last_idx = size - 1;

	while (last_idx > 0)
	{
		temp = array[last_idx];
		array[last_idx] = array[0];
		array[0] = temp;
		print_array(array, size);
		last_idx--;
		adjust_heap(array, 0, last_idx, size);
	}
}
