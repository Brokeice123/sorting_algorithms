#include "sort.h"

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
