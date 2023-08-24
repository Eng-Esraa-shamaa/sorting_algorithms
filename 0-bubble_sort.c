#include "sort.h"
/**
 *bubble_sort - sort array of integers in asc ord by Bubble sort algo
 *@array: array of integers
 *@size: size of array
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
