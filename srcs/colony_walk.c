/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony_walk.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:41:09 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 19:09:47 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void				set_room_level(t_room *room, int level)
{
	t_tube		*adj;
	ssize_t		lvl;

	if ((adj = room->tubes) == NULL)
		ferror_ft("no isolated room allowed");
	room->level = level;
	while (adj)
	{
		lvl = adj->room->level;
		if (lvl > 0 && lvl + 1 < room->level
				&& (adj->room->type & VLV && !(room->type & VLV)))
			room->level = lvl + 1;
		adj = adj->next;
	}
}

void				colony_walk(t_colony *colony, t_queue *q)
{
	t_room	*cur;
	t_tube	*adj;

	if (q->size == 0)
		return ;
	cur = dequeue(q);
	if ((adj = cur->tubes) == NULL)
		ferror_ft("no isolated room allowed");
	while (adj)
	{
		if (adj->room->level < 0)
		{
			if (!(adj->room->type & VLV && cur->type & VLV))
			{
				enqueue(q, adj->room);
				set_room_level(adj->room, cur->level + 1);
			}
		}
		adj = adj->next;
	}
	colony_walk(colony, q);
}

void				get_rooms_level(t_colony *colony)
{
	t_queue			*q;

	if (!(q = queue_create()))
		ferror_std("get_rooms_level() failed");
	if (colony->end == NULL || colony->start == NULL)
		ferror_ft("ERROR");
	enqueue(q, colony->end);
	colony->end->level = 0;
	dfs_set_valves(colony);
	dfs_end_neighbors(colony->end);
	colony_walk(colony, q);
	queue_destroy(q);
	if (colony->start->level < 0)
		ferror_ft("there must be at least one path from start to end");
	if (colony->start->level == 1)
		trivial_sol(colony);
}
