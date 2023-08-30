#include "binary_trees.h"
/**
 * binary_trees_ancestor - finding the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: pointer to the lowest ancestor node of the two given nodes or NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	while (first)
	{
		if (first == second)
			return ((binary_tree_t *)(first));
		if (first->parent == second->parent)
			return ((binary_tree_t *)(first->parent));
		if (first->left == second || first->right == second)
			return ((binary_tree_t *)(first));
		if (second->left == first || second->right == first)
			return ((binary_tree_t *)(second));
		if (first->n < second->n)
			first = first->parent;
		else if (first->n > second->n)
			second = second->parent;
		else
			break;
	}
	return (NULL);
}
