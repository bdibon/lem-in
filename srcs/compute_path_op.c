/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compute_path_op.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 17:27:35 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:31:47 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void		compute_path_op_sub1(t_queue_node *cur_ant, t_queue *path,
		t_dlist *turn_op)
{
	char	*str;

	str = op_to_string(cur_ant, path);
	((t_ant*)(cur_ant->value))->loc = path->head;
	list_push(turn_op, str);
}

static void		compute_path_op_sub2(t_queue_node *cur_ant, t_queue *path,
		t_dlist *turn_op)
{
	char	*str;

	str = op_to_string(cur_ant, path);
	list_push(turn_op, str);
}

static void		compute_path_op_sub3(t_queue_node *cur_ant, t_queue *path,
		t_dlist *turn_op)
{
	char	*str;

	str = op_to_string(cur_ant, path);
	((t_ant*)cur_ant->value)->loc = ((t_ant*)cur_ant->value)->loc->next;
	list_push(turn_op, str);
}

void			compute_path_op(unsigned int *nb_ants, t_dlist *turn_op,
		t_queue *ants, t_queue *path)
{
	t_queue_node	*cur_ant;
	t_queue_node	*tmp;

	cur_ant = ants->head;
	while (cur_ant)
	{
		if (((t_ant*)cur_ant->value)->loc == NULL)
		{
			compute_path_op_sub1(cur_ant, path, turn_op);
			break ;
		}
		tmp = ((t_ant*)cur_ant->value)->loc->next;
		if (tmp && tmp->next == NULL)
		{
			compute_path_op_sub2(cur_ant, path, turn_op);
			free(dequeue(ants));
			*nb_ants = *nb_ants - 1;
			cur_ant = ants->head;
			continue ;
		}
		else
			compute_path_op_sub3(cur_ant, path, turn_op);
		cur_ant = (cur_ant) ? cur_ant->next : NULL;
	}
}
