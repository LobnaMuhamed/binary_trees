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
	int left = 0, right = 0;
	binary_tree_t *tmp;

	if (!tree)
		return (0);

	tmp = tree->left;
	while (tmp)
	{
		left++;
		tmp = tmp->left;
	}

	tmp = tree->right;
	while (tmp)
	{
		right++;
		tmp = tmp->right;
	}

	return (left - right);
}

