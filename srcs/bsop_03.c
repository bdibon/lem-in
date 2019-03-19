/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bsop_03.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:51:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 17:59:31 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				is_step_possible(t_sop *sop, unsigned int iv, t_queue *path)
{
	unsigned int i;

	i = 0;
	while (i <= sop->last_vlv)
	{
		if (i != iv && pth_cross(sop->paths[i], path))
			return (0);
		i++;
	}
	return (1);
}

static void		cbsop_sub(t_bsop *bsop, t_sop *sop, unsigned int iv)
{
	if (iv == sop->first_vlv)
	{
		sop->paths[iv] = NULL;
		sop->first_vlv++;
		if (iv != sop->last_vlv)
			cbsop(bsop, sop, iv + 1, 0);
	}
	else
	{
		sop->paths[iv] = NULL;
		if (iv != sop->last_vlv)
			cbsop(bsop, sop, iv + 1, 0);
	}
}

void			cbsop(t_bsop *bsop, t_sop *sop, unsigned int iv,
		unsigned int ip)
{
	t_queue		*cur_pth;

	cur_pth = sop->valve_tab[iv]->path_tab[ip];
	if (sop->first_vlv == sop->last_vlv && cur_pth == NULL)
		return ;
	if (cur_pth && is_step_possible(sop, iv, cur_pth))
	{
		sop->paths[iv] = sop->valve_tab[iv]->path_tab[ip];
		is_sop_better(sop, bsop);
		if (iv != sop->last_vlv)
			cbsop(bsop, sop, iv + 1, 0);
		cbsop(bsop, sop, iv, ip + 1);
	}
	else if (cur_pth)
		cbsop(bsop, sop, iv, ip + 1);
	else
		cbsop_sub(bsop, sop, iv);
}

t_bsop			*compute_bsop(t_colony *colony)
{
	t_sop	*sop;
	t_bsop	*bsop;

	sop = set_sop(colony);
	bsop = set_bsop(colony);
	cbsop(bsop, sop, 0, 0);
	free_sop(sop);
	return (bsop);
}
