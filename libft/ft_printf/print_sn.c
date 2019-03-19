/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_sn.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 14:42:12 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:49:38 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_only_sn(t_conv *conv, intmax_t sn, size_t len)
{
	if (conv->sp == 'D' || conv->lmod & _L)
		sn = (long)sn;
	if (conv->lmod & _HH && !(conv->sp == 'D'))
		sn = (char)sn;
	if (conv->lmod & _H && !(conv->sp == 'D'))
		sn = (short)sn;
	if (conv->lmod & _LL && !(conv->sp == 'D'))
		sn = (long long)sn;
	if (conv->lmod & _J && !(conv->sp == 'D'))
		sn = (intmax_t)sn;
	if (conv->lmod & _Z && !(conv->sp == 'D'))
		sn = (intmax_t)sn;
	if (conv->lmod == 0 && conv->sp != 'D')
		sn = (int)sn;
	if (sn < 0 && (conv->flags & ZERO
				|| conv->pre >= (int)len))
		sn = -sn;
	if (!(conv->pre == 0 && sn == 0))
		ft_putnbr(sn);
}

int		ispositiv(t_conv *conv, intmax_t sn)
{
	if (conv->sp == 'D' || conv->lmod & _L)
		sn = (long)sn;
	else if (conv->lmod & _HH)
		sn = (char)sn;
	else if (conv->lmod & _H)
		sn = (short)sn;
	else if (conv->lmod & _LL)
		sn = (long long)sn;
	else if (conv->lmod & _J)
		;
	else if (conv->lmod & _Z)
		;
	else
		sn = (int)sn;
	return ((sn >= 0) ? 1 : 0);
}

void	print_pre_sn(t_conv *conv, int *d, intmax_t sn, size_t len)
{
	if (ispositiv(conv, sn) && conv->flags & SPACE
			&& !(conv->flags & PLUS))
	{
		ft_putchar(' ');
		*d = *d - 1;
		conv->nbc++;
	}
	if (conv->flags & PLUS && ispositiv(conv, sn))
	{
		if (conv->flags & ZERO)
			ft_putchar('+');
		*d = *d - 1;
		conv->nbc++;
	}
	if (conv->flags & ZERO && !ispositiv(conv, sn) &&
			!(!ispositiv(conv, sn) && conv->pre >= (int)len))
		ft_putchar('-');
	if (!ispositiv(conv, sn) && conv->mfw != -1 && conv->pre >= conv->mfw)
		*d = *d + 1;
}

int		reset_snd(t_conv *conv, int d, size_t len)
{
	if (conv->flags & MINUS)
	{
		if (conv->pre >= 0)
			d = (conv->mfw > conv->pre) ? conv->mfw - conv->pre : d;
		else
			d = conv->mfw - len;
	}
	d = ((conv->flags & SPACE && !(conv->flags & PLUS))
			|| (conv->flags & PLUS)) ? d - 1 : d;
	if (conv->flags & MINUS && conv->mfw > conv->pre
			&& conv->pre == 0 && conv->mfw > (int)len)
		d = (conv->flags & PLUS) ?
			conv->mfw - (int)len - 1 : conv->mfw - (int)len;
	return (d);
}

void	print_sn(t_conv *conv, va_list *ap, size_t len, int d)
{
	intmax_t	sn;

	sn = va_arg(*ap, intmax_t);
	print_pre_sn(conv, &d, sn, len);
	if (conv->pre == 0 && sn == 0 && conv->mfw > 0)
		d = d + 1;
	d = print_sn_body(conv, sn, len, d);
	if (conv->flags & PLUS && !(conv->flags & ZERO)
				&& ispositiv(conv, sn) && conv->pre <= (int)len)
		ft_putchar('+');
	print_only_sn(conv, sn, len);
	d = reset_snd(conv, d, len);
	d = (conv->flags & MINUS && conv->flags & PLUS
			&& !ispositiv(conv, sn) && conv->mfw > 0) ? d + 1 : d;
	while ((int)len < conv->mfw && d-- > 0 && ++conv->nbc)
		ft_putchar(' ');
	conv->nbc += (!(conv->pre == 0 && sn == 0)) ? len : 0;
}
