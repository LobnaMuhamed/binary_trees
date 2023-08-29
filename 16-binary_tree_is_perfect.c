#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);

	d = depth(tree);

	return (is_perfect(tree, d, 0));

}

/**
 * depth - Calculate the depth
 * @tree: Pointer to root
 *
 * Return: The calculate of the depth
 */

int depth(const binary_tree_t *tree)
{
	int d = 0;
	binary_tree_t *node = tree->left;

	if (tree)
		d++;

	while (node)
	{
		d++;
		node = node->left;
	}

	return (d);
}

/**
 * is_perfect - Check if the tree is perfect
 * @tree: Pointer to root
 * @depth: The depth
 * @level: The level
 *
 * Return: 1 if the root is perfect else 0
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree->left && !tree->right)
		return (depth == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
			is_perfect(tree->right, depth, level + 1));
}

