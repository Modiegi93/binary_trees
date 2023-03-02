#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 *
 * Description: The root node must be freed and replace with
 * the last level-order node of the heap.Once replaced, the
 * heap must be rebuilt if necessary
 *
 * Return: the value stored in the root node.
 * If your function fails, return 0
 */
int heap_extract(heap_t **root)
{

	

