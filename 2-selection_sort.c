#include "sort.h"
/**
 * selection_sort -- sorts an array using the selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void/nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j, k;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (; i < size - 1 ; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] < array[k])
				k = i;
		}
		if (k != i)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
