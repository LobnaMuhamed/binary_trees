#include "binary_trees.h"

/**
 * bst_insert - inserting a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp;

	if (!tree)
		return (NULL);
	new_node = binary_tree_node(*tree, value);
	if (!new_node)
		return (NULL);
	if (!(*tree))
	{
		*tree = new_node;
		return (*tree);
	}
	temp = *tree;
	if (value < temp->n)
	{
		if (!temp->left)
		{
			temp->left = new_node;
			return (temp->left);
		}
		return (bst_insert(&(temp->left), value));
	}
	else if (value > temp->n)
	{
		if (!temp->right)
		{
			temp->right = new_node;
			return (temp->right);
		}
		return (bst_insert(&(temp->right), value));
	}
	return (NULL);
}
