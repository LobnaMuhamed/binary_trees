#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 *
 * Return: Count the leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	else
		count = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (count);
}

