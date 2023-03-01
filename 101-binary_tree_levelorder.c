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
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	const binary_tree_t *node;
	int front, back;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	front = 0;
	back = 0;
	queue[back++] = tree;

	while (front < back)
	{
		node = queue[front++];

		func(node->n);

		if (node->left != NULL)
		{
			queue[back++] = node->left;
		}

		if (node->right != NULL)
		{
			queue[back++] = node->right;
		}
	}

	free(queue);
}
