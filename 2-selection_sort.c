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
	size_t j, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (; i < size - 1 ; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
