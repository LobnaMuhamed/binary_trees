#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree
 *	using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *	The value in the node must be passed as a parameter to this function
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *node = tree;


	if (!node || !func)
		return;

	binary_tree_postorder(node->left, func);
	binary_tree_postorder(node->right, func);
	func(node->n);

}

