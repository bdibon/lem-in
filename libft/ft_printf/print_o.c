/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_o.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 09:46:52 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 21:34:12 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		getws_d(t_conv *conv, wchar_t *ws, int locale)
{
	size_t	i;
	int		lbyt;

	i = 0;
	lbyt = 0;
	while (ws && ws[i] && ((((lbyt += ft_wcbytelen(ws[i])) <= conv->pre
						|| (locale && ws[i] > 0x7f && ws[i] < 0x100))
					&& conv->pre > 0) || conv->pre == -1))
		i++;
	if (conv->pre > -1 && lbyt > conv->pre)
		lbyt -= ft_wcbytelen(ws[i - 1]);
	return (conv->mfw - lbyt);
}

int		setd(t_conv *conv, size_t len)
{
	if (conv->mfw && (conv->sp == 'S'
					|| (conv->sp == 's' && conv->lmod == 'l')))
		return (0);
	if (isconvs(conv->sp) && conv->pre < 0)
		return (conv->mfw - len);
	if (isconvs(conv->sp) && !isnumconv(conv->sp))
	{
		if (conv->pre >= (int)len)
			return (conv->mfw - len);
		else if (conv->sp == 'c' && conv->pre >= 0)
			return (conv->mfw - conv->pre - 1);
		else
			return (conv->mfw - conv->pre);
	}
	if (!isconvs(conv->sp))
		return (conv->mfw - 1);
	return ((conv->pre < conv->mfw) ? conv->mfw - len : conv->pre - len);
}

void	print_pt(t_conv *conv)
{
	conv->sp = 'x';
	conv->lmod = _L;
	conv->flags |= SHARP;
	conv->flags |= PT;
}

void	print_o(t_conv *conv, va_list *ap)
{
	size_t	len;
	int		d;

	if (conv->sp == 'p')
		print_pt(conv);
	len = (conv->sp == '%') ? 1 : get_paraml(conv, ap);
	d = setd(conv, len);
	if (!(conv->lmod & _L) && conv->sp == 's')
		print_s(conv, ap, len, d);
	if (((conv->lmod & _L) && conv->sp == 's') || conv->sp == 'S')
		print_wcs(conv, ap, len, d);
	if (conv->sp == 'c' && !(conv->lmod & _L))
		print_c(conv, ap, len, d);
	if (conv->sp == 'C' || (conv->sp == 'c' && conv->lmod & _L))
		print_wc(conv, ap, len, d);
	if (issigned(conv))
		print_sn(conv, ap, len, d);
	if (isunsigned(conv) || conv->sp == 'p')
		print_un(conv, ap, len, d);
	if (!isconvs(conv->sp))
		print_nosp(conv, len, d);
}
