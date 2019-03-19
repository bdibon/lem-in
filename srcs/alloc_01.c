/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alloc_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/03 11:27:04 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 13:56:46 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_colony	*new_colony(void)
{
	t_colony	*colony;

	if (!(colony = ft_memalloc(sizeof(t_colony))))
		ferror_std("new_colony() failed");
	if (!(colony->rooms = list_create()))
		ferror_std("new_colony() failed");
	return (colony);
}

t_room		*add_room(t_colony *colony, char *line)
{
	t_room	*room;

	if (colony->nb_rooms == UINT_MAX)
		return (NULL);
	if (!(room = get_room_att(line, colony)))
		return (NULL);
	colony->nb_rooms++;
	list_push(colony->rooms, room);
	return (room);
}

t_room		*new_room(void)
{
	t_room	*room;

	if (!(room = ft_memalloc(sizeof(t_room))))
		return (NULL);
	if (!(room->pos = ft_memalloc(sizeof(t_pos))))
		return (NULL);
	room->level = -1;
	return (room);
}

t_tube		*new_tube(t_room *room)
{
	t_tube	*tube;

	if (!(tube = ft_memalloc(sizeof(t_tube))))
		ferror_std("new_tube() failed");
	tube->room = room;
	return (tube);
}

t_tube		*shift_tube(t_room *room, t_tube *new_tube)
{
	new_tube->next = room->tubes;
	room->tubes = new_tube;
	return (new_tube);
}
