#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree = NULL;

	if (!array || size <= 0)
		return (NULL);

	tree = avl_insert(&tree, array[0]);
	if (!tree)
		return (NULL);

	for (i = 1; i < size; i++)
		avl_insert(&tree, array[i]);

	return (tree);
}

