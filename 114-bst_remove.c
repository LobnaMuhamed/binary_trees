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
	bst_t *new = NULL, *node = NULL, *result = NULL;

	if (!root)
		return (NULL);

	if (root->n == value)
		node = root;
	else
	{
		if (root->n < value)
			node = root->right;
		else
			node = root->left;

		while (node && node->n != value)
		{
			if (node->n < value)
				node = node->right;
			else
				node = node->left;
		}
	}

	if (!node->parent)
	{
		if (!node->left)
		{
			node->right->parent = node->parent;
			result = node->right;
			free(node);
			return (result);
		}
		else if (!node->right)
		{
			node->left->parent = node->parent;
			result = node->left;
			free(node);
			return (result);
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
		if (!node->left)
			new = remove_l(node);
		else if (!node->right)
			new = remove_r(node);
		if (new->parent)
			new = root;
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
	bst_t *result;

	if (root->parent)
	{
		if (root->parent->left == root)
			root->parent->left = root->right;
		else
			root->parent->right = root->right;
	}

	if (root->right)
		root->right->parent = root->parent;

	result = root->right;
	free(root);

	return (result);
}

/**
 * remove_r - Remove node has left and right is NULL
 * @root: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Pointer to the new node
 */

bst_t *remove_r(bst_t *root)
{
	bst_t *result;

	if (root->parent)
	{
		if (root->parent->left == root)
			root->parent->left = root->left;
		else
			root->parent->right = root->left;
	}

	if (root->left)
		root->left->parent = root->parent;

	result = root->left;
	free(root);
	return (result);
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

