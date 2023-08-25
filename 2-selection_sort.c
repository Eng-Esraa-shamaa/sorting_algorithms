#include "sort.h"
/**
 * selection_sort -- sorts an array using the selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void/nothing
*/
void selection_sort(int *array, size_t size)
{
	int i = 0;
	int j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for(; i < size - 1 ; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		print_array(array, size);
	}
}
