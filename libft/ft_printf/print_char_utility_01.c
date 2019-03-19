/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_char_utility_01.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 17:47:28 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 21:32:38 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			reset_sd(t_conv *conv, int d, size_t len, char *s)
{
	d = (conv->pre > 0 && conv->pre < (intmax_t)len) ?
		conv->mfw - conv->pre : conv->mfw - (int)len;
	d = (s == NULL && conv->pre > -1) ? conv->mfw - conv->pre : d;
	return (d);
}

void		print_wcs_pre(t_conv *conv, int d)
{
	d = (conv->pre == 0 && !(conv->flags & MINUS)) ? conv->mfw : d;
	while (d-- > 0)
	{
		if (conv->flags & ZERO && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & MINUS) && !(conv->flags & ZERO)
				&& ++conv->nbc)
			ft_putchar(' ');
	}
}

void		print_null(t_conv *conv)
{
	char	*str;
	int		n;

	str = ft_strdup("(null)");
	n = (conv->pre > 0 && conv->pre < 7) ? conv->pre : 6;
	write(1, str, n);
	conv->nbc += n;
	free(str);
}

int			check_wcs(wchar_t *ws, t_conv *conv, size_t *len, int locale)
{
	int i;
	int lbyt;

	i = 0;
	lbyt = 0;
	while (ws && ws[i] && ((((lbyt += ft_wcbytelen(ws[i])) <= conv->pre
						|| (locale && ws[i] > 0x7f && ws[i] < 0x100))
					&& conv->pre > 0) || conv->pre == -1))
	{
		if (ws[i] > 0x10ffff || ws[i] < 0
				|| (ws[i] >= 0xd800 && ws[i] <= 0xdbff)
				|| (ws[i] >= 0xdc00 && ws[i] <= 0xdfff)
				|| (ws[i] > 0xff && locale))
		{
			conv->err = 1;
			return (0);
		}
		else if (ws[i] > 0x7f && ws[i] < 0x100 && locale)
			*len = *len - 1;
		i++;
	}
	return (1);
}

int			print_wcs_body(t_conv *conv, wchar_t *ws, int locale, int *lbyt)
{
	int i;

	*lbyt = 0;
	i = 0;
	while (ws && ws[i] && ((((*lbyt += ft_wcbytelen(ws[i])) <= conv->pre
						|| (locale && ws[i] > 0x7f && ws[i] < 0x100))
					&& conv->pre > 0) || conv->pre == -1))
	{
		if (locale && ws[i] > 0x7f && ws[i] < 0x100)
		{
			conv->nbc -= ft_wcbytelen(ws[i]) - 1;
			write(1, &ws[i++], 1);
		}
		else
			ft_putwc(ws[i++]);
	}
	return (i);
}
