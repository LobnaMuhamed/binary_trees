#include "binary_trees.h"

/**
 * bst_insert - inserting a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	temp = *tree;
	if (value < temp->n)
	{
		if (!temp->left)
		{
			temp->left = binary_tree_node(temp, value);
			return (temp->left);
		}
		return (bst_insert(&(temp->left), value));
	}
	else if (value > temp->n)
	{
		if (!temp->right)
		{
			temp->right = binary_tree_node(temp, value);
			return (temp->right);
		}
		return (bst_insert(&(temp->right), value));
	}
	return (NULL);
}
