#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Measures the depth of a node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
        size_t depth = 0;

        if (!tree || !tree->parent)
                return (0);

        depth = binary_tree_depth(tree->parent);

        return (1 + depth);

}


/**
 * binary_tree_is_complete - checking if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if it's complete, 0 if it's not
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t depth = 0, height = 0;

	if (!tree)
		return 0;
	depth = binary_tree_depth(tree);
	while (height < depth && tree)
	{
		if (tree->left && tree->right)
		{
			height++;
			if (height == depth - 1)
				return (1);
		}
		else
			break;
		tree = tree->left;
	}
	return (0);
}
