/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sol_02.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 14:06:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:28:27 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	add_end_to_paths(t_room *end, t_queue **paths, unsigned int nb_valves)
{
	unsigned int	i;

	i = 0;
	while (i < nb_valves)
	{
		if (paths[i])
			enqueue(paths[i], end);
		i++;
	}
}

void	print_output(t_dlist *op_list)
{
	t_dlist_node	*turn;
	t_dlist_node	*op;
	t_dlist_node	*tmp;

	turn = op_list->head;
	while (turn)
	{
		op = ((t_dlist*)(turn->value))->head;
		while (op)
		{
			if (op == ((t_dlist*)turn->value)->tail)
				ft_printf("%s\n", (char*)op->value);
			else
				ft_printf("%s ", (char*)op->value);
			free(op->value);
			tmp = op->next;
			free(op);
			op = tmp;
		}
		free(turn->value);
		tmp = turn->next;
		free(turn);
		turn = tmp;
	}
	free(op_list);
}
