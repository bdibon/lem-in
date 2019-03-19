/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dfs_02.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 17:42:58 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:22:36 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void			dfs_valve_sub(t_valve *v, t_room *r, t_room *cur_r,
		t_queue *pth)
{
	t_queue	*new_pth;

	if (pth->tail->value == r)
	{
		enqueue(pth, cur_r);
		dfs_valve(v, cur_r, pth);
	}
	else
	{
		if (!(((t_room*)pth->tail->value)->type & ENEI))
		{
			pth_cut(pth, r);
			enqueue(pth, cur_r);
			dfs_valve(v, cur_r, pth);
		}
		else
		{
			new_pth = pth_dup(pth, r);
			list_push(v->gbc, new_pth);
			enqueue(new_pth, cur_r);
			dfs_valve(v, cur_r, new_pth);
		}
	}
}

static int			dfs_check_pdup(t_queue *path, t_room *cur_r, t_room *r)
{
	t_queue_node	*qnode;

	if ((qnode = queue_seek_value(path, cur_r)))
		qnode = qnode->next;
	else
		return (0);
	if (qnode && qnode->value == r)
		return (0);
	return (1);
}

static t_queue		*dfs_dup(t_queue *pth, t_room *r, t_room *cur_r,
		t_dlist *gbc)
{
	if (((t_room*)pth->tail->value)->type & ENEI && !(cur_r->type & VLV
				|| cur_r->type & START) && dfs_check_pdup(pth, cur_r, r))
	{
		pth = pth_dup(pth, r);
		list_push(gbc, pth);
	}
	return (pth);
}

static void			dfs_del(t_dlist *gbc, t_queue *pth)
{
	list_pop(gbc);
	queue_destroy(pth);
}

void				dfs_valve(t_valve *v, t_room *r, t_queue *pth)
{
	t_room	*cur_r;
	t_tube	*edge;

	if (pth->size == 0)
		enqueue(pth, r);
	if (r->type & ENEI)
	{
		list_push(v->paths, list_pop(v->gbc));
		return ;
	}
	if (pth->size > v->max)
		return ;
	edge = r->tubes;
	while (edge)
	{
		cur_r = edge->room;
		pth = dfs_dup(pth, r, cur_r, v->gbc);
		if (!(cur_r->type & START || cur_r->type & VLV ||
					queue_seek_value2(pth, edge->room)))
			dfs_valve_sub(v, r, cur_r, pth);
		edge = edge->next;
	}
	if (!(((t_room*)pth->tail->value)->type & ENEI) && r == v->room)
		dfs_del(v->gbc, pth);
}
