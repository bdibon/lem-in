/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_03.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:17:21 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 19:21:57 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "queue.h"

t_queue_node	*queue_seek_value2(t_queue *queue, void *value)
{
	t_queue_node *node;

	node = queue->tail;
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->prev;
	}
	return (NULL);
}

t_queue			*queue_dup(t_queue *queue)
{
	t_queue			*cpy;
	t_queue_node	*node;

	if (!(cpy = queue_create()))
		return (NULL);
	node = queue->head;
	while (node)
	{
		enqueue(cpy, node->value);
		node = node->next;
	}
	return (cpy);
}
