/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sol_01.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:11:24 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:29:35 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	**set_ants_travel(unsigned int *ants_partition, t_dlist *ants,
		unsigned int nb_valves)
{
	t_queue			**ants_travel;
	unsigned int	i;
	unsigned int	j;

	if (!(ants_travel = ft_memalloc(sizeof(t_queue*) * nb_valves)))
		return (NULL);
	i = 0;
	while (i < nb_valves)
	{
		if (ants_partition[i] > 0)
			ants_travel[i] = queue_create();
		j = 0;
		while (j < ants_partition[i])
		{
			enqueue(ants_travel[i], list_shift(ants));
			j++;
		}
		i++;
	}
	list_destroy(ants);
	free(ants_partition);
	return (ants_travel);
}

char	*op_to_string(t_queue_node *ant, t_queue *path)
{
	char	*room_name;
	char	*str;
	char	*tmp;
	size_t	len;

	if (((t_ant*)(ant->value))->loc == NULL)
		room_name = ((t_room*)path->head->value)->name;
	else
		room_name = ((t_room*)(((t_ant*)(ant->value))->loc->next->value))->name;
	len = 2 + ft_strlen(room_name)
		+ ft_budigitlen(10, ((t_ant*)ant->value)->id);
	if (!(str = ft_strnew(len)))
		ferror_std("op_to_string() failed");
	ft_strcat(str, "L");
	if (!(tmp = ft_itoa2(((t_ant*)ant->value)->id)))
		ferror_std("op_to_string() failed");
	ft_strcat(str, tmp);
	free(tmp);
	ft_strcat(str, "-");
	ft_strcat(str, room_name);
	return (str);
}

void	free_ants_travel(t_queue **ants_travel, unsigned int nb_valves)
{
	unsigned int	i;

	i = 0;
	while (i < nb_valves)
	{
		if (ants_travel[i])
			queue_destroy(ants_travel[i]);
		i++;
	}
	free(ants_travel);
}

t_dlist	*compute_op(unsigned int nb_valves, unsigned int nb_ants,
		t_queue **ants_travel, t_queue **paths)
{
	t_dlist			*op_list;
	t_dlist			*turn;
	unsigned int	i;

	if (!(op_list = list_create()))
		return (NULL);
	while (nb_ants > 0)
	{
		if (!(turn = list_create()))
			return (NULL);
		list_push(op_list, turn);
		i = 0;
		while (i < nb_valves)
		{
			if (ants_travel[i] && ants_travel[i]->size > 0)
				compute_path_op(&nb_ants, turn, ants_travel[i],
						paths[i]);
			i++;
		}
	}
	free_ants_travel(ants_travel, nb_valves);
	return (op_list);
}
