#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int level;

	if (tree == NULL || func == NULL)
		return;

	for (level = 1; level <= height + 1; level++)
		binary_tree_traverse_level(tree, level, func);
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: a pointer to the root node of the tree to calculate
 * the height of
 *
 * Return: The height of the tree
 */
int binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_traverse_level - traverses a level of a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @level: the level to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_traverse_level(const binary_tree_t *tree, int level,
	       void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_traverse_level(tree->left, level - 1, func);
		binary_tree_traverse_level(tree->right, level - 1, func);
	}
}
