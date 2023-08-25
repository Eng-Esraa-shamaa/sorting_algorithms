#include "sort.h"
/**
 * quick_sort -- sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void/nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		quick_sorted(array, 0, size - 1, size);
	}
}
/**
 * quick_sorted -- recusrive method to implement quicksort
 * @array: array to be sorted
 * @lower: int
 * @upper: int
 * @size: size of array
 *
 * Return: void/ noting
 */
void quick_sorted(int *array, int lower, int upper, size_t size)
{
	int loc;

	if (lower < upper)
	{
		loc = partition(array, lower, upper, size);
		quick_sorted(array, lower, loc - 1, size);
		quick_sorted(array, loc + 1, upper, size);
	}
}
/**
 * partition -- splits array into 2 parts to sort
 * @array: array of ints to be sorted
 * @lower: int
 * @upper: int
 * @size: size of array
 *
 * Return: int
 */
int partition(int *array, int lower, int upper, size_t size)
{
	int pivot = array[upper];
	int left = lower;
	int right = lower;

	while (right < upper)
	{
		if (array[right] <= pivot)
		{
			swap_ints(&array[left], &array[right]);

			if (left == right)
				;
			else
				print_array(array, size);
			left++;
		}
		right++;
	}
	swap_ints(&array[left], &array[upper]);
	if (left != right)
		print_array(array, size);
	return (left);
}
/**
 * swap_ints -- swaps two integers
 * @a: pointer to first int
 * @b: pointer to second int
 *
 * Return: void/nothing
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

