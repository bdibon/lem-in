/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   valves.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:49:26 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 15:57:48 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_valve		**set_valve_tab(t_colony *colony, t_room *start)
{
	t_valve			**valve_tab;
	t_tube			*tube_node;
	unsigned int	nb_valves;

	tube_node = start->tubes;
	nb_valves = 0;
	while (tube_node)
	{
		nb_valves++;
		tube_node = tube_node->next;
	}
	colony->nb_valves = nb_valves;
	if (!(valve_tab = ft_memalloc(sizeof(t_valve*) * (nb_valves + 1))))
		return (NULL);
	valve_tab[nb_valves] = NULL;
	return (valve_tab);
}

t_valve		*valve_create(t_room *room)
{
	t_valve		*v;

	if (!(v = ft_memalloc(sizeof(t_valve))))
		ferror_std("valve_create() failed");
	v->room = room;
	if (!(v->paths = list_create()))
		ferror_std("valve_create() failed");
	if (!(v->gbc = list_create()))
		ferror_std("valve_create() failed");
	return (v);
}

void		valve_push(t_valve *valve_tab[], t_valve *new_valve)
{
	unsigned int	i;

	i = 0;
	while (valve_tab[i])
		i++;
	valve_tab[i] = new_valve;
}

int			is_valve(t_colony *colony, t_room *r)
{
	unsigned int	i;
	t_valve			**valve_tab;

	i = 0;
	valve_tab = colony->valve_tab;
	while (valve_tab[i])
	{
		if (r == valve_tab[i]->room)
			return (1);
		i++;
	}
	return (0);
}

void		pth_list_to_pth_tab(t_valve **valve_tab)
{
	unsigned int	i;

	i = 0;
	while (valve_tab[i])
	{
		valve_tab[i]->path_tab = (t_queue**)list_to_tab(valve_tab[i]->paths);
		i++;
	}
}
