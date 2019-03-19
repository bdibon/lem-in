/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:23:33 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 16:14:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "queue.h"

t_queue_node	*queue_shift(t_queue *queue, void *value)
{
	t_queue_node *new;

	new = ft_memalloc(sizeof(t_queue_node));
	new->value = value;
	new->next = queue->head;
	new->prev = NULL;
	new->key = 0;
	if (queue->head)
		queue->head->prev = new;
	queue->head = new;
	if (queue->size == 0)
		queue->tail = new;
	queue->size++;
	return (new);
}

void			*queue_unshift(t_queue *queue)
{
	void			*value;
	t_queue_node	*tmp;

	if (queue->size == 0)
		return (NULL);
	value = queue->tail->value;
	tmp = queue->tail->prev;
	free(queue->tail);
	queue->size--;
	queue->tail = tmp;
	queue->tail->next = NULL;
	return (value);
}

void			*queue_peek(t_queue *queue)
{
	return (queue->head->value);
}

void			queue_destroy(t_queue *queue)
{
	t_queue_node	*cur;
	t_queue_node	*tmp;

	cur = queue->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(queue);
}

t_queue_node	*queue_seek_value(t_queue *queue, void *value)
{
	t_queue_node *node;

	node = queue->head;
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
