/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 20:26:57 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:37:24 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_flags[ARG_MAX + 1] = {' ', '#', '+', '-', '.', '0', '*', 'C', 'D',
	'O', 'S', 'U', 'X', 'c', 'd', 'i', 'o', 'p', 's', 'u', 'x', 'h', 'l', 'j',
	'z', '\0'};

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		nbc;

	va_start(ap, fmt);
	nbc = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
			fmt = parse_fmt((char *)++fmt, &ap, &nbc);
		if (*fmt == '%' && *(fmt + 1) == '%')
		{
			if (nbc != -1)
				ft_putchar('%');
			nbc = (nbc == -1) ? -1 : nbc + 1;
			fmt = fmt + 2;
		}
		if (nbc == -1)
			return (nbc);
		if (*fmt && *fmt != '%' && ++nbc)
			ft_putchar(*fmt++);
	}
	va_end(ap);
	return (nbc);
}
