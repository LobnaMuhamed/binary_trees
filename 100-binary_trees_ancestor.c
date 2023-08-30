#include "binary_trees.h"
/**
 * binary_trees_ancestor - finding the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: pointer to the lowest ancestor node of the two given nodes or NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	int n1, n2;

	n1 = first->n;
	n2 = second->n;
	return ((n1 > n2) ? second : first);

}
