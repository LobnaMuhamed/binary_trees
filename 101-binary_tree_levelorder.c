#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree
 *	using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Q_q *q = (Q_q *)malloc(sizeof(Q_q *));
	binary_tree_t *tmp;

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
		func(tmp->n);
		push(q, tmp->left);
		push(q, tmp->right);
		if (tmp)
			free(tmp);
	} while (tmp);

	free(q);
}

/**
 * push - Push node
 * @q: Struct queue
 * @data: The data of the node
 */

void push(Q_d *q, binary_tree_t *data)
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

Q_d *pop(Q_d *q)
{
	Q_d *tmp = NULL;

	tmp = q->head;
	q->head = q->head->next;

	return (tmp);
}

