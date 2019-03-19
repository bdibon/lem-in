/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_char.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:03:09 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:39:23 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_conv *conv, va_list *ap, size_t len, int d)
{
	char	*s;
	int		i;

	s = va_arg(*ap, char *);
	if (s == NULL && conv->mfw > 6 && (len = 6))
		d = (conv->pre > 0 && conv->pre < 6) ?
			conv->mfw - conv->pre : conv->mfw - 6;
	while (!(s == NULL && (conv->flags & MINUS || (conv->mfw <= 6
						&& !(conv->flags & ZERO)))) && d-- > 0)
	{
		if (conv->flags & ZERO && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & MINUS) && !(conv->flags & ZERO) && ++conv->nbc)
			ft_putchar(' ');
	}
	i = 0;
	if (s == NULL && conv->pre != 0)
		print_null(conv);
	while (s && s[i] && ((conv->pre > 0 && i < conv->pre) || conv->pre == -1)
				&& ++conv->nbc)
		write(1, &s[i++], 1);
	d = reset_sd(conv, d, len, s);
	if ((conv->flags & MINUS))
		while (d-- > 0 && ++conv->nbc)
			ft_putchar(' ');
}

void	print_wcs(t_conv *conv, va_list *ap, size_t len, int d)
{
	wchar_t	*ws;
	int		i;
	int		lbyt;
	int		locale;

	lbyt = 0;
	locale = (MB_CUR_MAX > 1) ? 0 : 1;
	if ((ws = va_arg(*ap, wchar_t *)) == NULL)
		print_null(conv);
	if (!check_wcs(ws, conv, &len, locale))
		return ;
	d = getws_d(conv, ws, locale);
	print_wcs_pre(conv, d);
	i = print_wcs_body(conv, ws, locale, &lbyt);
	lbyt = (i == 0) ? 0 : lbyt;
	conv->nbc += (lbyt >= conv->pre && conv->pre > 0) ?
		lbyt - ft_wcbytelen(ws[i]) : lbyt;
	lbyt = (lbyt > conv->pre && conv->pre != -1)
		? lbyt - ft_wcbytelen(ws[i]) : lbyt;
	lbyt = (lbyt >= (int)len) ? len : lbyt;
	if ((conv->flags & MINUS) && (d = conv->mfw - lbyt) > 0)
		while (d-- > 0 && ++conv->nbc)
			ft_putchar(' ');
}

void	print_c(t_conv *conv, va_list *ap, size_t len, int d)
{
	char c;

	while (d-- > 0)
	{
		if (conv->flags & ZERO && ++conv->nbc)
			ft_putchar('0');
		if (!(conv->flags & MINUS) && !(conv->flags & ZERO)
				&& ++conv->nbc)
			ft_putchar(' ');
	}
	c = (unsigned char)va_arg(*ap, unsigned int);
	write(1, &c, 1);
	conv->nbc++;
	if ((conv->flags & MINUS) && (d = conv->mfw - len) > 0)
		while (d-- > 0 && ++conv->nbc)
			ft_putchar(' ');
}

void	print_wc(t_conv *conv, va_list *ap, size_t len, int d)
{
	wchar_t wc;
	int		locale;

	locale = (MB_CUR_MAX > 1) ? 0 : 1;
	wc = va_arg(*ap, unsigned int);
	d = print_pre_wc(conv, wc, d, locale);
	if (wc > 0x10ffff || wc < 0 || (wc >= 0xd800 && wc <= 0xdbff)
			|| (wc >= 0xdc00 && wc <= 0xdfff) || (wc > 0x7f && locale))
	{
		if (wc > 0x10ffff || wc < 0 || (wc >= 0xd800 && wc <= 0xdbff)
				|| (wc >= 0xdc00 && wc <= 0xdfff) || (locale && wc > 0xff))
			conv->err = 1;
		else
		{
			write(1, &wc, 1);
			conv->nbc++;
			if (wc <= 0xff && (conv->flags & MINUS) && (d = conv->mfw - len) > 0
					&& ++d)
				while (d-- > 0 && ++conv->nbc)
					ft_putchar(' ');
		}
		return ;
	}
	ft_putwc(wc);
	print_suf_wc(conv, wc, len);
}
