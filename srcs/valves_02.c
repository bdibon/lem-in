/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   valves_02.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 18:45:21 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 18:46:07 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void			filter_valves(t_colony *col)
{
	unsigned int	nb_valves;
	unsigned int	i;
	t_dlist			*vlv_list;
	t_valve			**valve_tab;

	nb_valves = col->nb_valves;
	i = 0;
	vlv_list = list_create();
	valve_tab = col->valve_tab;
	while (i < nb_valves)
	{
		if (valve_tab[i])
			list_push(vlv_list, valve_tab[i]);
		i++;
	}
	free(col->valve_tab);
	col->nb_valves = vlv_list->size;
	col->valve_tab = (t_valve**)list_to_tab(vlv_list);
}
