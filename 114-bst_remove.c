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
	bst_t *new = NULL;

	if (!root)
		return (NULL);

	if (!root->parent)
	{
		if (!root->left)
			root->right->parent = root->parent;
		if (!root->right)
			root->left->parent = root->parent;
		if (!root->left || !root->right)
			free(root);
	}
	else
	{
		if (!root->left)
			new = remove_l(root);

		if (!root->right)
			new = remove_r(root);
	}

	if (root->left && root->right)
		new = remove_l_r(root);

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
	free(root);

	return (root->right);
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
	free(root);

	return (root->left);
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
		if (!tmp->right)
		{
			root->n = tmp->n;
			tmp->parent->right = tmp->left;
			free(tmp);
			return (root);
		}

		tmp = tmp->right;
	}

	return (root);
}

