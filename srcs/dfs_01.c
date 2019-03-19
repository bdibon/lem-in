/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dfs_01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 18:45:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:09:42 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void			dfs_set_valves(t_colony *colony)
{
	t_valve			**valve_tab;
	t_tube			*edge;
	unsigned int	i;

	if (!(valve_tab = set_valve_tab(colony, colony->start)))
		ferror_std("set_valve_tab() failed");
	colony->valve_tab = valve_tab;
	colony->start->type = START;
	colony->end->type = END;
	edge = colony->start->tubes;
	i = 0;
	while (edge)
	{
		edge->room->type = VLV;
		valve_tab[i++] = valve_create(edge->room);
		edge = edge->next;
	}
}

void			dfs_end_neighbors(t_room *end)
{
	t_tube			*edge;

	edge = end->tubes;
	while (edge)
	{
		edge->room->type |= ENEI;
		edge = edge->next;
	}
}

void			pth_cut(t_queue *path, void *value)
{
	t_queue_node	*node;
	t_queue_node	*tmp;

	node = path->tail;
	while (node)
	{
		if (node->value == value)
			return ;
		tmp = node->prev;
		queue_unshift(path);
		node = tmp;
	}
}

unsigned int	compute_max(t_room *v)
{
	unsigned int	max;
	unsigned int	level;
	t_tube			*adj;

	max = v->tubes->room->level;
	adj = v->tubes->next;
	while (adj)
	{
		level = adj->room->level;
		if (level > max)
			max = level;
		adj = adj->next;
	}
	return (max + 1);
}

void			dfs_all_paths(t_colony *col)
{
	t_valve			**valves;
	t_queue			*p1;
	unsigned int	i;

	valves = col->valve_tab;
	i = 0;
	while (valves[i])
	{
		valves[i]->max = compute_max(valves[i]->room);
		if (!(p1 = queue_create()))
			ferror_std("dfs_all_paths() failed");
		list_push(valves[i]->gbc, p1);
		dfs_valve(valves[i], valves[i]->room, p1);
		i++;
	}
	i = 0;
	while (valves[i])
	{
		gbc_clear_destroy(valves[i]->gbc);
		i++;
	}
}
