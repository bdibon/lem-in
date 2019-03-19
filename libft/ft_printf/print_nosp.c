/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_nosp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 18:42:16 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 15:05:07 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nosp(t_conv *conv, size_t len, int d)
{
	while (d-- > 0)
	{
		if (conv->flags & ZERO && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & MINUS) && !(conv->flags & ZERO)
				&& ++conv->nbc)
			ft_putchar(' ');
	}
	if (conv->sp == '%' && ++conv->nbc)
		ft_putchar('%');
	else if (conv->flags & MINUS && ++conv->nbc)
		ft_putchar(conv->sp);
	d = (conv->sp == '%') ? conv->mfw - len : conv->mfw - len - 1;
	if ((conv->flags & MINUS) && d > 0)
		while (d-- > 0 && ++conv->nbc)
			ft_putchar(' ');
}
