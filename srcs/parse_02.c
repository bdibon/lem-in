/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/30 16:55:16 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 18:52:13 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			check_line_is_room(const char *line)
{
	char	*offset;

	offset = (char*)line + ft_strlen(line) - 1;
	if (!coord_strrevseek2(line, &offset, ' '))
		return (0);
	offset--;
	if (!coord_strrevseek2(line, &offset, ' '))
		return (0);
	return (1);
}

t_room		*seek_matching_room(char *name, t_colony *colony)
{
	t_dlist_node	*node;

	node = colony->rooms->head;
	while (node)
	{
		if (!ft_strcmp(name, ((t_room*)node->value)->name))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

char		*get_room_name1(char *line, int dash)
{
	char	*name;

	if (!(name = ft_strsub(line, 0, dash)))
		ferror_std("get_room_name1() failed");
	return (name);
}

char		*get_room_name2(char *line, int dash)
{
	char	*name;

	if (!(name = ft_strsub(line, dash + 1, ft_strlen(line) - dash - 1)))
		ferror_std("get_room_name2() failed");
	return (name);
}

void		*process_tube_line(char *line, t_colony *colony)
{
	char				*tmp;
	char				*c;
	t_room				*r1;
	t_room				*r2;

	if (!(c = ft_strchr(line, '-')))
		return (NULL);
	tmp = get_room_name1(line, c - line);
	if (!(r1 = seek_matching_room(tmp, colony)))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	tmp = get_room_name2(line, c - line);
	if (!(r2 = seek_matching_room(tmp, colony)) ||
			!check_tube_duplicate(r1, r2))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	colony->nb_tubes++;
	shift_tube(r1, new_tube(r2));
	return (shift_tube(r2, new_tube(r1)));
}
