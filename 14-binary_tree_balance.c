#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

int calc_height(const binary_tree_t *tree, int *);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Measure the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;
	int height = 0;

	if (!tree)
		return (0);

	left = calc_height(tree->left, &height);
	right = calc_height(tree->right, &height);

	return (left - right);
}

/**
 * calc_height - Calc the height
 * @tree: Pointer to root
 * @height: The height
 *
 * Return: The height
 */

int calc_height(const binary_tree_t *tree, int *height)
{
	int left = 0, right = 0;

	if (!tree)
		return (1);

	left += calc_height(tree->left, height);
	right += calc_height(tree->right, height);

	*height = (left > right ? left : right) + 1;

	return (*height);
}

