#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: the number of tree's height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int x = 0, y = 0;

	if (!tree)
		return (0);
	if (tree->left)
		x = binary_tree_height(tree->left);
	if (tree->right)
		y = binary_tree_height(tree->right);
	return ((x > y) ? x : y);
}
