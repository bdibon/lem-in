/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_02.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:52:19 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:22:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	free_sop(t_sop *sop)
{
	free(sop->paths);
	free(sop->ants_partition);
	free(sop);
}

void	free_bsop(t_bsop *bsop)
{
	free(bsop->paths);
	free(bsop->ants_partition);
	free(bsop);
}

void	gbc_clear_destroy(t_dlist *gbc)
{
	t_dlist_node	*node;
	t_dlist_node	*tmp;

	node = gbc->head;
	while (node)
	{
		if (node->value)
			queue_destroy(node->value);
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(gbc);
}
