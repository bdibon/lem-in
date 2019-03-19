/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_valves.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:33:55 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:59:21 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		cmp_paths(t_queue *path_1, t_queue *path_2)
{
	return (path_1->size - path_2->size);
}

void	sort_valve_paths(t_dlist **paths)
{
	t_dlist	*tmp;

	tmp = *paths;
	*paths = list_merge_sort(*paths, &cmp_paths);
	if (tmp != *paths)
		list_destroy(tmp);
}

void	sort_valves(t_valve **valve_tab)
{
	unsigned int	i;

	i = 0;
	while (valve_tab[i])
		sort_valve_paths(&valve_tab[i++]->paths);
}
