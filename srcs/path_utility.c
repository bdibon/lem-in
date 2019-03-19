/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_utility.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:48:37 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:56:54 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*pth_cross(t_queue *path_1, t_queue *path_2)
{
	t_queue_node *n1;
	t_queue_node *n2;

	if (path_1 == NULL || path_2 == NULL)
		return (NULL);
	n1 = path_1->head;
	while (n1)
	{
		n2 = path_2->head;
		while (n2)
		{
			if (n1->value == n2->value)
				return (n1->value);
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	return (NULL);
}

t_queue			*pth_dup(t_queue *pth, void *value)
{
	t_queue_node	*node;
	t_queue			*cpy;

	if (!(cpy = queue_create()))
		ferror_std("pth_dup() failed");
	node = pth->head;
	while (node)
	{
		enqueue(cpy, node->value);
		if (node->value == value)
			break ;
		node = node->next;
	}
	return (cpy);
}

void			path_cpy(t_queue **p_dest, t_queue **p_src,
		unsigned int nb_valves)
{
	unsigned int	i;

	i = 0;
	while (i < nb_valves)
	{
		p_dest[i] = p_src[i];
		i++;
	}
}

unsigned int	path_value(t_queue *path, unsigned int nb_ants)
{
	return (path->size + (nb_ants - 1));
}
