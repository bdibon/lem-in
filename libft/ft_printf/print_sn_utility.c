/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_sn_utility.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 15:28:21 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:48:41 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_odd_case(t_conv *conv, intmax_t sn)
{
	if (conv->pre == 0 && sn == 0)
		ft_putchar(' ');
	else
		ft_putchar('0');
}

int		print_sn_spebody(t_conv *conv, intmax_t sn, size_t len, int d)
{
	while (d-- > 0)
	{
		if (d == conv->pre - (int)len && !ispositiv(conv, sn) && conv->mfw != -1
				&& (conv->pre >= conv->mfw || conv->pre >= (int)len))
			ft_putchar('-');
		if (conv->pre >= conv->mfw && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & ZERO || conv->flags & MINUS)
				&& conv->pre < conv->mfw && d > conv->pre - (int)len
				&& ++conv->nbc)
			ft_putchar(' ');
		if (d == 1 && conv->flags & PLUS && !(conv->flags & ZERO))
			ft_putchar('+');
		if (!(conv->flags & MINUS) && conv->flags & ZERO
				&& conv->pre < conv->mfw && d > conv->pre - (int)len
				&& ++conv->nbc)
			print_odd_case(conv, sn);
		if (conv->pre < conv->mfw && d <= conv->pre - (int)len
				&& ++conv->nbc)
			ft_putchar('0');
	}
	return (d);
}

int		print_sn_regbody(t_conv *conv, intmax_t sn, size_t len, int d)
{
	while (d-- > 0)
	{
		if (d == conv->pre - (int)len && !ispositiv(conv, sn) && conv->mfw != -1
				&& (conv->pre >= conv->mfw || conv->pre >= (int)len))
			ft_putchar('-');
		if (conv->pre >= conv->mfw && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & ZERO || conv->flags & MINUS)
				&& conv->pre < conv->mfw && d + 1 > conv->pre - (int)len
				&& ++conv->nbc)
			ft_putchar(' ');
		if (d == conv->pre - (int)len - 1 && conv->flags & PLUS
				&& !(conv->flags & ZERO) && conv->pre > (int)len)
			ft_putchar('+');
		if (!(conv->flags & MINUS) && conv->flags & ZERO
			&& conv->pre < conv->mfw && d + 1 > conv->pre - (int)len
			&& ++conv->nbc)
			print_odd_case(conv, sn);
		if (conv->pre < conv->mfw && d + 1 <= conv->pre - (int)len
				&& ++conv->nbc)
			ft_putchar('0');
	}
	return (d);
}

int		print_sn_body(t_conv *conv, intmax_t sn, size_t len, int d)
{
	if (!ispositiv(conv, sn) && ((conv->flags & ZERO && conv->mfw > 0)
				|| (conv->pre > (int)len)) && d < 0)
		ft_putchar('-');
	if (!ispositiv(conv, sn) && conv->pre >= (int)len)
		d = print_sn_spebody(conv, sn, len, d);
	else
		d = print_sn_regbody(conv, sn, len, d);
	return (d);
}
