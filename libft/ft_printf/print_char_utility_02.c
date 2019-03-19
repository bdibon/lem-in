/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_char_utility_02.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 17:37:32 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 21:32:59 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_pre_wc(t_conv *conv, wchar_t wc, int d, int locale)
{
	d = (wc > 0x7f && wc <= 0xff && locale) ? d + 1 : d;
	while (d-- > 0)
	{
		if (conv->flags & ZERO && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & MINUS) && !(conv->flags & ZERO)
				&& ++conv->nbc)
			ft_putchar(' ');
	}
	return (d);
}

void	print_suf_wc(t_conv *conv, wchar_t wc, size_t len)
{
	int d;

	conv->nbc += ft_wcbytelen(wc);
	if ((conv->flags & MINUS) && (d = conv->mfw - len) > 0)
		while (d-- > 0 && ++conv->nbc)
			ft_putchar(' ');
}
