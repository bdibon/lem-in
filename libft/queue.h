/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   queue.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:16:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:39:25 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef QUEUE_H
#	define QUEUE_H

#include "libft.h"

typedef struct				s_queue
{
	struct s_queue_node		*head;
	struct s_queue_node		*tail;
	size_t					size;
}							t_queue;

typedef struct				s_queue_node
{
	void					*value;
	size_t					key;
	struct s_queue_node		*next;
	struct s_queue_node		*prev;
}							t_queue_node;

t_queue						*queue_create(void);
t_queue_node				*enqueue(t_queue *queue, void *value);
void						*dequeue(t_queue *queue);
void						queue_clear_destroy(t_queue *queue);
void						queue_destroy(t_queue *queue);
int							queue_size(t_queue *queue);
void						*queue_peek(t_queue *queue);

t_queue_node				*queue_shift(t_queue *queue, void *value);
void						*queue_unshift(t_queue *queue);
t_queue_node				*queue_seek_value(t_queue *queue, void *value);
t_queue_node				*queue_seek_value2(t_queue *queue, void *value);

t_queue						*queue_dup(t_queue *queue);

#	endif
