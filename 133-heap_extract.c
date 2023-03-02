#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * swap_nodes - swaps two binary tree nodes
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * find_last_node - finds the last node in the heap
 * @root: root node of the heap
 *
 * Return: pointer to the last node in the heap
 */
heap_t *find_last_node(heap_t *root)
{
	int height, mask;
	heap_t *node;

	height = 0;
	node = root;
	while (node->left != NULL)
	{
		height++;
		node = node->left;
	}

	mask = 1 << height;
	while (mask > 1)
	{
		if (mask & 1)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}
	return (node);
}


/**
 * heapify_down - restores the heap property by moving the root node down
 *                the heap until it is in the correct position
 * @root: root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *node, *child;

	node = root;
	while (1)
	{
		child = NULL;
		if (node->left != NULL && node->left->n > node->n)
			child = node->left;
		if (node->right != NULL && node->right->n > node->n &&
				(child == NULL || node->right->n > child->n))
			child = node->right;
		if (child == NULL)
			break;
		swap_nodes(node, child);
		node = child;
	}
}


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
	int value;
	heap_t *last_node, *parent;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	last_node = find_last_node(*root);
	if (last_node != *root)
	{
		parent = last_node->parent;
		swap_nodes(*root, last_node);

		if (parent->left == last_node)
			parent->left = NULL;
		else
			parent->right = NULL;
		heapify_down(*root);
	}
	else
		*root = NULL;
	free(last_node);

	return (value);
}
