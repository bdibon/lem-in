/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_05.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:29:10 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 17:11:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void		**list_to_tab(t_dlist *list)
{
	t_dlist_node	*node;
	void			**values;
	size_t			i;

	node = list->head;
	if (!(values = (void**)malloc(sizeof(node->value) * (list->size + 1))))
		return (NULL);
	i = 0;
	while (node)
	{
		values[i++] = node->value;
		node = node->next;
	}
	values[i] = NULL;
	list_destroy(list);
	return (values);
}
