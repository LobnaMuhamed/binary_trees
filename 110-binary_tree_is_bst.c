#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min_value, int max_value);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the tree node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min_value = INT_MIN, max_value = INT_MAX;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (is_bst(tree, min_value, max_value));
}

/**
 * is_bst - Check if Binary Search Tree
 * @tree: Pointer to root
 * @min_value: integer
 * @max_value: integer
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_bst(const binary_tree_t *tree, int min_value, int max_value)
{
/*	int left, right;*/

	if (!tree)
		return (1);


	if (tree->n < min_value || tree->n > max_value)
		return (0);

	return (is_bst(tree->left, min_value, (tree->n - 1)) &&
		is_bst(tree->right, (tree->n + 1), max_value)
		);
}

