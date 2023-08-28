#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *	The value in the node must be passed as a parameter to this function
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *node = tree;


	if (!node || !func)
		return;

	func(node->n);
	binary_tree_preorder(node->left, func);
	binary_tree_preorder(node->right, func);

}

