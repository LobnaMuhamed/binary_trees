#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

bst_t *remove_l(bst_t *root);
bst_t *remove_r(bst_t *root);
bst_t *remove_l_r(bst_t *root);

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree
 *	after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new = NULL, *node = root, *result = NULL;

	if (!root)
		return (NULL);

	while (node && node->n != value)
	{
		if (node->n < value)
			node = node->right;
		else
			node = node->left;
	}

	if (node)
	{
		if (!node->parent)
		{
			if (!node->left && node->right)
			{
				node->right->parent = node->parent;
				result = node->right;
				free(node);
				return (result);
			}

			if (!node->right && node->left)
			{
				node->left->parent = node->parent;
				result = node->left;
				free(node);
				return (result);
			}

			if (!node->right && !node->left)
			{
				free(node);
				return (NULL);
			}
		}
		if (node->left && node->right)
		{
			new = remove_l_r(node);
			if (new->parent)
				new = root;
		}
		else
		{
			new = root;
			if (!node->left)
				free(remove_l(node));
			else if (!node->right)
				free(remove_r(node));
		}
	}

	return (new);
}

/**
 * remove_l - Remove node has right and left is NULL
 * @root: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Pointer to the new node
 */

bst_t *remove_l(bst_t *root)
{
	if (root->parent->left == root)
		root->parent->left = root->right;
	else
		root->parent->right = root->right;
	if (root->right)
		root->right->parent = root->parent;

	return (root);
}

/**
 * remove_r - Remove node has left and right is NULL
 * @root: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Pointer to the new node
 */

bst_t *remove_r(bst_t *root)
{
	if (root->parent->left == root)
		root->parent->left = root->left;
	else
		root->parent->right = root->left;

	if (root->left)
		root->left->parent = root->parent;

	return (root);
}

/**
 * remove_l_r - Remove node has left and right
 * @root: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Pointer to the new node
 */

bst_t *remove_l_r(bst_t *root)
{
	bst_t *tmp = root->right;

	while (tmp)
	{
		if (!tmp->left)
		{
			root->n = tmp->n;
			if (tmp->parent == root)
				tmp->parent->right = tmp->right;
			else
				tmp->parent->left = tmp->right;
			free(tmp);
			return (root);
		}

		tmp = tmp->left;
	}

	return (tmp);
}

