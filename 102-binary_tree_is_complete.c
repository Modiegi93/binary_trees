#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * to measure the size
 *
 * Return: The size of a binary tree,
 * otherwise 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node ofthe tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	const binary_tree_t *node;
	int front, back;
	int has_child = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return (0);
	front = 0;
	back = 0;
	queue[back++] = tree;
	while (front < back)
	{
		node = queue[front++];
		if (node->left != NULL)
		{
			if (has_child)
			{ free(queue);
				return (0);
			}
			queue[back++] = node->left;
		}
		else
			has_child = 1;

		if (node->right != NULL)
		{
			if (has_child)
			{ free(queue);
				return (0);
			}
			queue[back++] = node->right;
		}
		else
			has_child = 1;
	}
		free(queue);
		return (1);
}
