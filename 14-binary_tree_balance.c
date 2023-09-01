#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

int calc_height(const binary_tree_t *tree, int);

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

	int left = calc_height(tree->left, 0);
	int right = calc_height(tree->right, 0);

	return (left - right);
}

/**
 * calc_height - Calc the height
 * @tree: Pointer to root
 * @height: The height
 *
 * Return: The height
 */

int calc_height(const binary_tree_t *tree, int height)
{
	if (!tree)
		return (0);

	int left = calc_height(tree->left, height);
	int right = calc_height(tree->right, height);

	height = (left > right ? left : right) + 1;

	return (height);
}

