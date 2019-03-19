/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_line.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 14:40:26 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 13:12:39 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#define EOF (-1)
#define BUFF_SIZ 128

static int		my_getc(const int fd)
{
	static char		buf[BUFF_SIZ];
	static char		*bufp = buf;
	static int		n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFF_SIZ);
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}

int				get_line(const int fd, char **line)
{
	char	c;
	char	*s;

	if (fd < 0 || read(fd, NULL, 0) < 0 || line == NULL)
		return (-1);
	s = *line;
	while ((c = my_getc(fd)) != EOF && c != '\n')
		*(s++) = c;
	return ((c == EOF) ? 0 : 1);
}
