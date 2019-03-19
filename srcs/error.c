/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/30 14:20:18 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 19:28:30 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void	ferror_std(char *s)
{
	write(STDERR_FILENO, "./lem-in: ", 10);
	perror(s);
	exit(EXIT_FAILURE);
}

void	ferror_ft(char *s)
{
	write(STDERR_FILENO, "./lem-in: ", 10);
	while (s && *s)
	{
		write(STDERR_FILENO, s, 1);
		s++;
	}
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
