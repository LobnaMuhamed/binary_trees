#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the tree node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && (tree->left->n >= tree->n))
		return (0);

	if (tree->right && (tree->right->n <= tree->n))
		return (0);

	if (tree->parent && (tree->n < tree->parent->n))
		if ((tree->left &&
				(tree->left->n >= tree->parent->n)) ||
				(tree->right &&
				(tree->right->n >= tree->parent->n)))
			return (0);

	if (tree->parent && (tree->n > tree->parent->n))
		if ((tree->left &&
				(tree->left->n <= tree->parent->n)) ||
				(tree->right &&
				(tree->right->n <= tree->parent->n)))
			return (0);

	if (tree->left)
		left = binary_tree_is_bst(tree->left);
	if (tree->right)
		right = binary_tree_is_bst(tree->right);

	return ((left && right));
}

