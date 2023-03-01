#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where
 * you will remove a node
 * @value: the value to remove in the tree
 *
 * Description: Once located, the node containing a value
 * equals to value must be removed and freed. If the node
 * to be deleted has two children, it must be replaced
 * with its first in-order successor
 *
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		else
		{
			successor = root->right;
			while (successor->left != NULL)
				successor = successor->left;
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return (root);
}
