#include "binary_trees.h"

/**
 * heap_size - Computes the size of a Max Binary Heap
 * @heap: Pointer to the root node of the heap
 *
 * Return: Size of the heap
 */
size_t heap_size(heap_t *heap)
{
	if (heap == NULL)
		return (0);

	return (heap_size(heap->left) + heap_size(heap->right) + 1);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i, count = heap_size(heap);
	int *array = NULL;

	if (!heap || count == 0)
		return (NULL);

	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);

	for (i = 0; i < count; i++)
	{
		array[i] = heap_extract(&heap);
		if (!array[i])
		{
			free(array);
			return (NULL);
		}
	}

	*size = count;
	return (array);
}
