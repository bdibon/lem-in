/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_01.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:52:07 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 16:25:49 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		free_rooms(t_dlist *rooms)
{
	t_dlist_node	*node;
	t_room			*room;
	t_tube			*tube;
	t_tube			*tmp;

	node = rooms->head;
	while (node)
	{
		if (node->prev)
			free(node->prev);
		room = node->value;
		tube = room->tubes;
		while (tube)
		{
			tmp = tube->next;
			free(tube);
			tube = tmp;
		}
		free(room->name);
		free(room->pos);
		free(room);
		node = node->next;
	}
	free(rooms->tail);
	free(rooms);
}

void		free_valve_tab(t_valve **valve_tab)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (valve_tab[i])
	{
		j = 0;
		while (valve_tab[i]->path_tab[j])
			queue_destroy(valve_tab[i]->path_tab[j++]);
		free(valve_tab[i]->path_tab);
		free(valve_tab[i]);
		i++;
	}
	free(valve_tab);
}

void		free_colony(t_colony *colony)
{
	list_destroy(colony->ants);
	free_rooms(colony->rooms);
	free_valve_tab(colony->valve_tab);
	free(colony);
}
