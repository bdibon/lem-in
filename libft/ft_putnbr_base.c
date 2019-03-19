/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:30 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		set_reference(char *stock, int *verif)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (c <= '~')
	{
		stock[i] = c;
		i++;
		c++;
	}
	stock[i] = '\0';
	i = 0;
	while (i < 95)
	{
		verif[i] = 0;
		i++;
	}
}

static int		check_errors(char *base)
{
	char	stock[96];
	int		verif[95];
	int		i;
	int		j;

	set_reference(stock, verif);
	i = -1;
	while (base[++i])
	{
		j = 0;
		while (j < 96)
		{
			if (base[i] == stock[j])
				verif[j]++;
			j++;
		}
	}
	i = 0;
	while (i < 95)
	{
		if (verif[i] > 1 || verif[11] > 0 || verif[13] > 0)
			return (0);
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_size;
	int		a;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (base_size == 0 || base_size == 1 || check_errors(base) == 0)
		return ;
	num = nbr;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 0 && num < base_size)
		ft_putchar(base[num]);
	else
	{
		a = num / base_size;
		ft_putnbr_base(a, base);
		ft_putchar(base[num % base_size]);
	}
}
