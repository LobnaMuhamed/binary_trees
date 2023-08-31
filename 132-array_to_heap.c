#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: pointer to the root node of the created Binary Heap,
 *	or NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *tree = NULL;

	if (!array || size <= 0)
		return (NULL);

	tree = heap_insert(&tree, array[0]);
	if (!tree)
		return (NULL);

	for (i = 1; i < size; i++)
		heap_insert(&tree, array[i]);

	return (tree);
}

