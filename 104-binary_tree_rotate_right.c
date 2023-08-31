#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performing a right-rotation
 * @tree: is a pointer to the root node of the tree
 * Return: a pointer to the new root node of the tree
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree == NULL || !tree->left)
		return (tree);

	new_tree = tree->left;

	tree->left = new_tree->right;

	new_tree->right = tree;

	return (new_tree);
}
