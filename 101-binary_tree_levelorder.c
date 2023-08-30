#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree
 *	using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Q_q *q = (Q_q *)malloc(sizeof(Q_q *));
	Q_d *tmp;

	if (!q)
		return;
	q->head = NULL;
	q->tail = NULL;

	if (!tree || !func)
		return;

	func(tree->n);
	push(q, tree->left);
	push(q, tree->right);

	do {
		tmp = pop(q);
		if (tmp)
		{
			func(tmp->data->n);
			push(q, tmp->data->left);
			push(q, tmp->data->right);
			free(tmp);
		}
	} while (tmp);

	if (q)
		free(q);
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
		new_node = (Q_d *)malloc(sizeof(Q_d *));
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

/**
 * pop - Pop node
 * @q: Struct queue
 *
 * Return: The node
 */

Q_d *pop(Q_q *q)
{
	Q_d *tmp = NULL;

	if (q && q->head)
	{
		tmp = q->head;
		q->head = q->head->next;
	}

	return (tmp);
}

