/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 14:29:23 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:48:32 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_colony	*colony;
	t_queue		**ants_travel;
	t_bsop		*bsop;
	t_dlist		*op_list;

	colony = set_colony();
	get_rooms_level(colony);
	dfs_all_paths(colony);
	sort_valves(colony->valve_tab);
	pth_list_to_pth_tab(colony->valve_tab);
	bsop = compute_bsop(colony);
	add_end_to_paths(colony->end, bsop->paths, colony->nb_valves);
	ants_travel = set_ants_travel(bsop->ants_partition, colony->ants,
			colony->nb_valves);
	op_list = compute_op(colony->nb_valves, colony->nb_ants,
			ants_travel, bsop->paths);
	free(bsop->paths);
	free(bsop);
	free_rooms(colony->rooms);
	free_valve_tab(colony->valve_tab);
	free(colony);
	write(1, "\n", 1);
	print_output(op_list);
	return (0);
}
