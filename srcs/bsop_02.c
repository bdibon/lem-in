/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bsop_02.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:04:22 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 14:04:22 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

unsigned int	ant_optimal_path(t_queue **paths,
		unsigned int *ants_partition, unsigned int nb_valves)
{
	unsigned int	i;
	unsigned int	min;
	unsigned int	tmp;
	unsigned int	index;

	i = 0;
	while (paths[i] == NULL && i < nb_valves)
		i++;
	min = path_value(paths[i], ants_partition[0]);
	index = i;
	i = i + 1;
	while (i < nb_valves)
	{
		if (paths[i] && (tmp = path_value(paths[i], ants_partition[i])) < min)
		{
			min = tmp;
			index = i;
		}
		i++;
	}
	return (index);
}

unsigned int	sop_compute_values(unsigned int *ants_partition,
		unsigned int nb_ants, unsigned int nb_valves, t_queue **paths)
{
	unsigned int	max;
	unsigned int	tmp;
	unsigned int	i;

	while (nb_ants)
	{
		ants_partition[ant_optimal_path(paths, ants_partition,
				nb_valves)] += 1;
		nb_ants--;
	}
	i = 0;
	while (paths[i] == NULL && i < nb_valves)
		i++;
	max = path_value(paths[i], ants_partition[i]);
	i++;
	while (i < nb_valves)
	{
		if (paths[i] && max < (tmp = path_value(paths[i], ants_partition[i])))
			max = tmp;
		i++;
	}
	return (max);
}

t_sop			*sop_values(t_sop *sop)
{
	unsigned int	nb_ants;
	unsigned int	nb_valves;

	nb_ants = sop->nb_ants;
	nb_valves = sop->last_vlv + 1;
	sop->nbt = sop_compute_values(sop->ants_partition, nb_ants, nb_valves,
			sop->paths);
	return (sop);
}

void			ants_partition_cpy(unsigned int *ap_dest, unsigned int *ap_src,
		unsigned int nb_valves)
{
	unsigned int	i;

	i = 0;
	while (i < nb_valves)
	{
		ap_dest[i] = ap_src[i];
		i++;
	}
}

int				is_sop_better(t_sop *sop, t_bsop *bsop)
{
	unsigned int	nb_valves;
	unsigned int	i;

	nb_valves = sop->last_vlv + 1;
	i = 0;
	while (i < nb_valves)
		sop->ants_partition[i++] = 0;
	sop_values(sop);
	if (sop->nbt < bsop->nbt)
	{
		ants_partition_cpy(bsop->ants_partition, sop->ants_partition,
				nb_valves);
		path_cpy(bsop->paths, sop->paths, nb_valves);
		bsop->nbt = sop->nbt;
		return (1);
	}
	return (0);
}
