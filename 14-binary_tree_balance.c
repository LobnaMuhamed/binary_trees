#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Measure the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (
			1 +
			binary_tree_balance(tree->left) -
			binary_tree_balance(tree->right)
		);
}

