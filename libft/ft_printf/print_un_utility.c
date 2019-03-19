/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_un_utility.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 16:06:45 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:57:14 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		isunoct(t_conv *conv)
{
	return ((conv->sp == 'o' || conv->sp == 'O') ? 1 : 0);
}

int		isunhex(t_conv *conv)
{
	return ((conv->sp == 'x' || conv->sp == 'X') ? 1 : 0);
}

int		print_un_spaces(t_conv *conv, int d0, size_t len, uintmax_t un)
{
	int limit;

	limit = 0;
	d0 = (conv->flags & PT && un == 0 && conv->pre < 0) ? d0 - 2 : d0;
	d0 = (conv->flags & PT && un != 0 && conv->mfw > conv->pre
			&& conv->mfw > (int)len) ? d0 - 2 : d0;
	d0 = (conv->mfw > conv->pre && conv->pre > (int)len && conv->mfw > 0) ?
		conv->mfw - ft_max(conv->pre, (int)len) : d0;
	if (conv->pre > 0)
	{
		limit = (conv->pre > (int)len && conv->mfw == 0) ? len : 0;
		limit = ((isunhex(conv) || isunoct(conv)) && conv->flags & SHARP
			&& !(conv->flags & PT)) ? 2 + conv->pre : limit;
	}
	if (!(conv->flags & ZERO || conv->flags & MINUS)
			&& conv->pre < conv->mfw)
	{
		while (d0-- > limit && ++conv->nbc)
			ft_putchar(' ');
		d0 = conv->pre - len;
	}
	return (d0);
}

int		resetund(t_conv *conv, int d0, size_t len, intmax_t un)
{
	d0 = (conv->flags & MINUS && conv->mfw > conv->pre) ?
		conv->mfw - ft_max((int)len, conv->pre) : d0;
	d0 = (conv->flags & SHARP && conv->flags & MINUS && isunoct(conv)) ?
		d0 - 1 : d0;
	d0 = (conv->pre > 0 && conv->pre < conv->mfw
			&& conv->flags & SHARP) ? d0 + 1 : d0;
	d0 = ((un != 0 || conv->flags & PT) && isunhex(conv)
			&& conv->flags & SHARP && conv->flags & MINUS) ? d0 - 2 : d0;
	return (d0);
}

void	print_pre_pt(t_conv *conv, uintmax_t un, size_t len, int tog)
{
	if (!tog && ((conv->flags & PT && un == 0)
				&& (conv->pre >= 0 || (conv->flags & ZERO
						&& conv->mfw > (int)len))))
	{
		ft_putstr("0x");
		conv->nbc += 2;
	}
	else if ((tog && conv->flags & PT && un == 0
			&& !(conv->flags & ZERO && conv->mfw > (int)len))
			&& conv->pre < 0)
	{
		ft_putstr("0x");
		conv->nbc += 2;
	}
}
