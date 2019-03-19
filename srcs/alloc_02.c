/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alloc_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/03 11:27:12 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 19:03:10 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_dlist		*set_ants(t_colony *colony, unsigned int nb_ants)
{
	t_ant			*ant;

	if (!(colony->ants = list_create()))
		ferror_std("set_ants() failed");
	ant = NULL;
	while (nb_ants)
	{
		if (!(ant = ft_memalloc(sizeof(t_ant))))
			ferror_std("set_ants() failed");
		ant->id = ++colony->nb_ants;
		ant->loc = NULL;
		list_push(colony->ants, ant);
		nb_ants--;
	}
	return (colony->ants);
}

t_tube		*push_tube(t_tube *path, t_tube *step)
{
	t_tube	*cur;

	if (path == NULL)
		return (path = step);
	cur = path;
	while (cur->next)
		cur = cur->next;
	cur->next = step;
	return (path);
}
