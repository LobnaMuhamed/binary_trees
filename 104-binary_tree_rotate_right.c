#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performing a right-rotation
 * @tree: is a pointer to the root node of the tree
 * Return: a pointer to the new root node of the tree
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);

	tree->left->parent = tree->parent;

	tree->parent = tree->left;

	tree->left = tree->left->right;

	tree->parent->right = tree;

	return (tree->parent);
}
