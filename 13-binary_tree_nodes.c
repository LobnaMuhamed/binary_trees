#include "binary_trees.h"

/**
 * binary_tree_nodes -  a function that counts the nodes with at least 1 child
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: return number of nodes or 0 if failed
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0;

	if (tree)
	{
		count_left = binary_tree_nodes(tree->left);
		count_right = binary_tree_nodes(tree->right);
		if (tree->left || tree->right)
			return (1 + count_left + count_right);
	}
	return (0);
}
