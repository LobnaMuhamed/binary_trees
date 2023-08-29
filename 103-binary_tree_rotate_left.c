#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	tree->right->parent = tree->parent;
	tree->parent = tree->right;

	tree->right = tree->right->left;
	tree->parent->left = tree;

	return (tree->parent);
}

