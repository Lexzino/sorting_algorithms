#include "sort.h"

/**
 * swap - Swap two integers in the array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partition an array and using pivot
 * @array: The array of intergers
 * @low: The lowest integer
 * @high: The highest integer
 * @size: size of array
 * Return: index of pivot (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_sort - Sorting recursively an Array
 * @array: An array of integer to sort.
 * @low: The lowest value of the array
 * @high:The  highest value of the array
 * @size: The size of The Array
 */

void lomuto_sort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_sort(array, low, i - 1, size);
		lomuto_sort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: An array of intergers.
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, 0, size - 1, size);
}
