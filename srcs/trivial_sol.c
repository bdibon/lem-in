/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trivial_sol.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 20:04:18 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 20:43:22 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	trivial_sol(t_colony *col)
{
	write(1, "\n", 1);
	while (col->nb_ants)
	{
		if (col->nb_ants == 1)
			ft_printf("L%u-%s\n", col->nb_ants, col->end->name);
		else
			ft_printf("L%u-%s ", col->nb_ants, col->end->name);
		col->nb_ants--;
	}
	exit(EXIT_SUCCESS);
}
