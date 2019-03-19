/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_room_att.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 17:54:19 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:56:04 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void		*get_room_att_sub(char **p, char *line, t_room *r)
{
	size_t		len;
	intmax_t	n;

	len = ft_strlen(line);
	*p = coord_strrevseek(line, line + len - 1, ' ');
	if (*p == NULL || (n = ft_atoi2(*p + 1)) > INT_MAX || n < INT_MIN)
	{
		free(r->pos);
		free(r);
		return (NULL);
	}
	r->pos->y = n;
	*p = coord_strrevseek(line, --*p, ' ');
	if (*p == NULL || (n = ft_atoi2(*p + 1)) > INT_MAX || n < INT_MIN)
	{
		free(r->pos);
		free(r);
		return (NULL);
	}
	r->pos->x = n;
	return (r);
}

t_room			*get_room_att(char *line, t_colony *colony)
{
	char		*p;
	t_room		*r;

	if (!(r = new_room()))
		ferror_std("get_room_att() failed");
	if (!get_room_att_sub(&p, line, r))
		return (NULL);
	if (!(r->name = ft_strnew(p - line)))
		ferror_std("get_room_att() failed");
	ft_strncpy(r->name, line, p - line);
	if (!(check_room_name(r, colony)))
		return (NULL);
	if (!check_room_pos(r, colony))
		return (NULL);
	return (r);
}
