/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:30 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long a;

	a = n;
	if (a < 0)
	{
		a = -a;
		ft_putchar_fd('-', fd);
	}
	if (a >= 0 && a <= 9)
		ft_putchar_fd(a + '0', fd);
	else
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd(a % 10 + '0', fd);
	}
}
