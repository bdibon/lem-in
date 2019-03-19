/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bsop_01.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:21:37 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:28:31 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_sop			*set_sop(t_colony *colony)
{
	t_sop	*sop;

	if (!(sop = ft_memalloc(sizeof(t_sop))))
		return (NULL);
	if (!(sop->paths = ft_memalloc(sizeof(t_queue*) * colony->nb_valves)))
		return (NULL);
	if (!(sop->ants_partition =
				ft_memalloc(sizeof(unsigned int) * colony->nb_valves)))
		return (NULL);
	sop->valve_tab = colony->valve_tab;
	sop->last_vlv = colony->nb_valves - 1;
	sop->nb_ants = colony->nb_ants;
	sop->first_vlv = 0;
	sop->nbt = UINT_MAX;
	return (sop);
}

t_bsop			*set_bsop(t_colony *colony)
{
	t_bsop	*bsop;

	if (!(bsop = ft_memalloc(sizeof(t_bsop))))
		return (NULL);
	if (!(bsop->paths = ft_memalloc(sizeof(t_queue*) * colony->nb_valves)))
		return (NULL);
	if (!(bsop->ants_partition =
				ft_memalloc(sizeof(unsigned int) * colony->nb_valves)))
		return (NULL);
	bsop->nbt = UINT_MAX;
	return (bsop);
}

t_queue			**path_tab_dup(t_queue **paths, unsigned int size)
{
	t_queue			**paths_cpy;
	unsigned int	i;

	if (!(paths_cpy = ft_memalloc(sizeof(t_queue*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		paths_cpy[i] = paths[i];
		i++;
	}
	return (paths_cpy);
}
