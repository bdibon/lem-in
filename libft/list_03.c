/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_03.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 16:43:46 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 17:29:22 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void			list_push(t_dlist *list, void *value)
{
	t_dlist_node	*node;

	if (!(node = node_create(value)))
		return ;
	if (list->tail == NULL)
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->size++;
}

void			*list_pop(t_dlist *list)
{
	t_dlist_node	*node;

	node = list->tail;
	return (node ? list_remove(list, node) : NULL);
}

void			list_unshift(t_dlist *list, void *value)
{
	t_dlist_node	*node;

	if (!(node = node_create(value)))
		return ;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

void			*list_shift(t_dlist *list)
{
	t_dlist_node	*node;

	node = list->head;
	return (node ? list_remove(list, node) : NULL);
}
