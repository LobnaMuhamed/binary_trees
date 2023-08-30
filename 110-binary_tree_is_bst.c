#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min_value, int max_value);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the tree node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min_value = INT_MIN, max_value = INT_MAX;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (is_bst(tree, min_value, max_value));
}

/**
 * is_bst - Check if Binary Search Tree
 * @tree: Pointer to root
 * @min_value: integer
 * @max_value: integer
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_bst(const binary_tree_t *tree, int min_value, int max_value)
{
/*	int left, right;*/

	if (!tree)
		return (1);


	if (tree->n < min_value || tree->n > max_value)
		return (0);

	return (is_bst(tree->left, min_value, (tree->n - 1)) &&
		is_bst(tree->right, (tree->n + 1), max_value)
		);
}

/**
 * free_all - Free Queue
 * @q: Struct Queue
 */

void free_all(Q_q *q)
{
	Q_d *tmp = q->head;

	while (tmp)
	{
		q->head = tmp->next;
		free(tmp);
		tmp = q->head;
	}

	free(q);
}

/**
 * is_duplicate - Check if value duplicate
 * @head: The head of list node
 * @data: The value to check
 *
 * Return: 1 if duplicate or 0
 */

int is_duplicate(Q_d *head, int data)
{
	if (!head)
		return (0);

	while (head)
	{
		if (head->data->n == data)
			return (1);

		head = head->next;
	}

	return (0);
}

/**
 * push - Push node
 * @q: Struct queue
 * @data: The data of the node
 */

void push(Q_q *q, const binary_tree_t *data)
{
	Q_d *new_node;

	if (q && data)
	{
		new_node = (Q_d *)malloc(sizeof(Q_d));
		if (!new_node)
			exit(1);

		new_node->data = data;
		new_node->next = NULL;

		if (!q->head)
			q->head = new_node;

		if (q->tail)
			q->tail->next = new_node;

		q->tail = new_node;
	}
}

