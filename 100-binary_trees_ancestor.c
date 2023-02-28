#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the
 * two given nodes or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	       const binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;

	ptr1 = first;
	ptr2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->parent != NULL ? ptr1->parent : second;
		ptr2 = ptr2->parent != NULL ? ptr2->parent : first;
	}

	return ((binary_tree_t *)ptr1);
}

