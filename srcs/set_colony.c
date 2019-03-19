/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_colony.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 16:00:32 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:37:03 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*process_spe_line(char **line, t_colony *colony)
{
	int				n;

	ft_memset(*line, '\0', BUFF_SIZE);
	while ((n = get_line(STDIN_FILENO, line)) > 0)
	{
		ft_printf("%s\n", *line);
		if (*line[0] != '#')
			break ;
		ft_memset(*line, '\0', BUFF_SIZE);
	}
	if (n < 0)
		ferror_std("process_spe failed()");
	if (ft_strlen(*line) == 0)
		return (NULL);
	if (check_line_is_room(*line))
		return (add_room(colony, *line));
	else
		return (NULL);
}

void		*process_line(char **line, t_colony *colony)
{
	if (ft_strlen(*line) == 0)
		return (NULL);
	if (!ft_strcmp(*line, "##start"))
		return ((colony->start = process_spe_line(line, colony)));
	if (!ft_strcmp(*line, "##end"))
		return ((colony->end = process_spe_line(line, colony)));
	if (*line[0] == '#')
		return (colony);
	if (check_line_is_room(*line))
		return (add_room(colony, *line));
	return (process_tube_line(*line, colony));
}

int			get_ants(char **line)
{
	int			n;
	intmax_t	nb_ants;

	if ((n = get_line(STDIN_FILENO, line)) == 0)
		ferror_ft("ERROR");
	if (n < 0)
		ferror_std("get_ants() failed");
	if (!ft_isdigit(*line[0]) || !ft_strisnum(*line))
		ferror_ft("digits only to input ant number");
	nb_ants = ft_atoi2(*line);
	if (nb_ants > UINT_MAX)
		ferror_ft("ant number greater than UINT_MAX");
	if (nb_ants == 0)
		ferror_ft("ERROR");
	ft_printf("%d\n", nb_ants);
	return (nb_ants);
}

t_colony	*set_colony(void)
{
	char		*line;
	t_colony	*colony;
	int			nb_ants;
	int			n;

	line = ft_strnew(BUFF_SIZE);
	colony = new_colony();
	nb_ants = get_ants(&line);
	while ((n = get_line(STDIN_FILENO, &line)) > 0)
	{
		ft_printf("%s\n", line);
		if (process_line(&line, colony) == NULL)
			break ;
		ft_memset(line, '\0', BUFF_SIZE);
	}
	free(line);
	if (n < 0)
		ferror_std("set_colony failed");
	set_ants(colony, nb_ants);
	return (colony);
}
