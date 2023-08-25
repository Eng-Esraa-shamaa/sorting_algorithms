#include "sort.h"
/**
 * shell_sort -- sorts an array using shell sort and knuth sequenece
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void/nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;
	size_t app_gap = (size / 3);

	if (size < 2)
		return;

	while (gap < app_gap)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
