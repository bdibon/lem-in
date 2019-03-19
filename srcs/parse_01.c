/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/30 19:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 19:00:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			check_room_name(t_room *r, t_colony *colony)
{
	t_dlist_node	*node;
	char			*name;

	name = r->name;
	if (name[0] == '#' || name[0] == 'L')
		return (0);
	if (ft_strchr(name, '-'))
		return (0);
	node = colony->rooms->head;
	while (node)
	{
		if (!ft_strcmp(((t_room*)(node->value))->name, name))
		{
			free(r->pos);
			free(r->name);
			free(r);
			return (0);
		}
		node = node->next;
	}
	return (1);
}

int			check_room_pos(t_room *r, t_colony *colony)
{
	t_dlist_node	*node;
	t_pos			*pos;

	pos = r->pos;
	node = colony->rooms->head;
	while (node)
	{
		if (((t_room*)(node->value))->pos->x == pos->x
				&& ((t_room*)(node->value))->pos->y == pos->y)
		{
			free(r->pos);
			free(r->name);
			free(r);
			return (0);
		}
		node = node->next;
	}
	return (1);
}

char		*coord_strrevseek(const char *line, char *offset, char c)
{
	while (offset != line && *offset != c)
	{
		if (!ft_isdigit(*offset) && !(*offset == '+' || *offset == '-'))
			return (NULL);
		offset--;
	}
	return (offset);
}

int			coord_strrevseek2(const char *line, char **offset, char c)
{
	while (*offset != line && **offset != c)
	{
		if (!ft_isdigit(**offset) && !(**offset == '+' || **offset == '-'))
			return (0);
		if (**offset == '+' || **offset == '-')
		{
			if (*offset != line && **(offset - 1) != c)
				return (0);
		}
		*offset = *offset - 1;
	}
	return (1);
}

int			check_tube_duplicate(t_room *r1, t_room *r2)
{
	t_tube	*tube_node;

	if (r1->tubes == NULL)
		return (1);
	tube_node = r1->tubes;
	while (tube_node)
	{
		if (tube_node->room->name == r2->name)
			return (0);
		tube_node = tube_node->next;
	}
	return (1);
}
