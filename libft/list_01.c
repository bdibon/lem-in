/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_01.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 16:43:57 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 17:29:58 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

t_dlist_node	*node_create(void *value)
{
	t_dlist_node	*node;

	if (!(node = malloc(sizeof(t_dlist_node))))
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlist			*list_create(void)
{
	t_dlist	*new_list;

	if (!(new_list = malloc(sizeof(t_dlist))))
		return (NULL);
	new_list->size = 0;
	new_list->head = NULL;
	new_list->tail = NULL;
	return (new_list);
}
