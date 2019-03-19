/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:19:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:55:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "queue.h"

t_queue				*queue_create(void)
{
	t_queue *new;

	new = ft_memalloc(sizeof(t_queue));
	return (new);
}

t_queue_node		*enqueue(t_queue *queue, void *value)
{
	t_queue_node	*new;

	if (!(new = ft_memalloc(sizeof(t_queue_node))))
		return (NULL);
	new->value = value;
	new->prev = queue->tail;
	new->next = NULL;
	new->key = (new->prev) ? new->prev->key + 1 : 0;
	if (queue->tail)
		queue->tail->next = new;
	queue->tail = new;
	if (queue->size == 0)
		queue->head = new;
	queue->size++;
	return (new);
}

void				*dequeue(t_queue *queue)
{
	void			*value;
	t_queue_node	*tmp;

	if (queue->size == 0)
		return (NULL);
	value = queue->head->value;
	tmp = queue->head->next;
	if (queue->head == queue->tail)
		queue->tail = NULL;
	free(queue->head);
	queue->size--;
	queue->head = tmp;
	if (tmp)
		queue->head->prev = NULL;
	return (value);
}

void				queue_clear_destroy(t_queue *queue)
{
	t_queue_node	*cur;
	t_queue_node	*tmp;

	cur = queue->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->value);
		free(cur);
		cur = tmp;
	}
	free(queue);
}

int					queue_size(t_queue *queue)
{
	return (queue->size);
}
