/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_02.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 16:43:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 17:29:23 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

void	list_destroy(t_dlist *list)
{
	t_dlist_node	*cur;

	cur = list->head;
	while (cur)
	{
		if (cur->prev)
			free(cur->prev);
		cur = cur->next;
	}
	free(list->tail);
	free(list);
}

void	list_clear(t_dlist *list)
{
	t_dlist_node	*cur;

	cur = list->head;
	while (cur)
	{
		free(cur->value);
		cur = cur->next;
	}
}

void	list_clear_destroy(t_dlist *list)
{
	t_dlist_node	*cur;

	cur = list->head;
	while (cur)
	{
		free(cur->value);
		if (cur->prev)
			free(cur->prev);
		cur = cur->next;
	}
	free(list->tail);
}

void	*list_remove(t_dlist *list, t_dlist_node *node)
{
	void	*result;

	if (list->size-- && list->head == node && list->tail == node)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (list->head == node)
	{
		node->next->prev = NULL;
		list->head = node->next;
	}
	else if (list->tail == node)
	{
		node->prev->next = NULL;
		list->tail = node->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	result = node->value;
	free(node);
	return (result);
}
