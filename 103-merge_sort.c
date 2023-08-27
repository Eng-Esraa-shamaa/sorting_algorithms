#include "sort.h"
/**
 * merge_sort -- sorts an array using merge sort algorithm
 * @array: array of ints
 * @size: size of array
 *
 * Return: nothing/ void
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return;

	merge_sorted(array, tmp, 0, size);
	free(tmp);
}
/**
 * merge_sorted -- uses recusion to implement merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array
 * @left: start of the array
 * @right: end of array
 *
 * Return: void
 */
void merge_sorted(int *array, int *tmp, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = left + (right - left) / 2;
		merge_sorted(array, tmp, left, middle);
		merge_sorted(array, tmp, middle, right);
		merge(array, tmp, left, middle, right);
	}
}
/**
 * merge -- sorts an array based on merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array to sort the ints in
 * @left: beginning of array
 * @middle: middle of array to divide
 * @right: end of array
 *
 * Return: void/nothing
 */
void merge(int *array, int *tmp, size_t left, size_t middle, size_t right)
{
	size_t tmp_idx = 0;
	size_t r_idx = middle;
	size_t l_idx = left;
	size_t i;

	printf("Merging...\n[left]: ");
	print_array(&array[left], middle - left);
	printf("[right]: ");
	print_array(&array[middle], right - middle);

	while (l_idx < middle && r_idx < right)
	{
		if (array[l_idx] <= array[r_idx])
			tmp[tmp_idx] = array[l_idx++];
		else
			tmp[tmp_idx] = array[r_idx++];
		tmp_idx++;
	}
	while (l_idx < middle)
		tmp[tmp_idx++] = array[l_idx++];
	while (r_idx < right)
		tmp[tmp_idx++] = array[r_idx++];

	for (tmp_idx = left, i = 0; tmp_idx < right; tmp_idx++)
		array[tmp_idx] = tmp[i++];

	printf("[Done]: ");
	print_array(&array[left], right - left);
}
