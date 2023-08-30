#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min_value,
	int max_value, int height, int check_h);
int calc_height(const binary_tree_t *, int *);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the tree node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int min_value = INT_MIN, max_value = INT_MAX;
	int height = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	calc_height(tree, &height);

	return (is_bst(tree, min_value, max_value, height, 1));
}

/**
 * is_bst - Check if Binary Search Tree
 * @tree: Pointer to root
 * @min_value: integer
 * @max_value: integer
 * @height: integer
 * @check_h: integer
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_bst(const binary_tree_t *tree, int min_value,
		int max_value, int height, int check_h)
{
	if (!tree)
	{
		if ((check_h - height) > 1 || (height - check_h) > 1)
			return (0);
		return (1);
	}

	if (tree->n < min_value || tree->n > max_value)
		return (0);

	return (is_bst(tree->left, min_value, (tree->n - 1),
				height, check_h + 1) &&
		is_bst(tree->right, (tree->n + 1), max_value,
			height, check_h + 1)
		);
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
