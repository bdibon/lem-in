/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_un.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 16:04:55 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:56:07 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_only_un(t_conv *conv, uintmax_t un)
{
	if (conv->sp == 'O')
		ft_putunbr_base((unsigned long)un, "01234567");
	else if (conv->sp == 'U' && !(conv->pre == 0 && un == 0))
		ft_putunbr_base((unsigned long)un, "0123456789");
	else if (conv->lmod & _HH)
		un = (unsigned char)un;
	else if (conv->lmod & _H)
		un = (unsigned short)un;
	else if (conv->lmod & _L)
		un = (unsigned long)un;
	else if (conv->lmod & _LL)
		un = (unsigned long long)un;
	else if (conv->lmod & _Z)
		un = (size_t)un;
	else if (!(conv->lmod & _J))
		un = (unsigned)un;
	if (conv->sp == 'o')
		ft_putunbr_base(un, "01234567");
	if (conv->sp == 'u' && !(conv->pre == 0 && un == 0))
		ft_putunbr_base(un, "0123456789");
	if (conv->sp == 'x')
		ft_putunbr_base(un, "0123456789abcdef");
	if (conv->sp == 'X')
		ft_putunbr_base(un, "0123456789ABCDEF");
}

void	print_pre_hex1(t_conv *conv, uintmax_t un, int *d, size_t len)
{
	if (un != 0 && !(!(conv->flags & ZERO || conv->flags & MINUS)
				&& conv->pre < conv->mfw) && conv->flags & SHARP)
	{
		if (conv->sp == 'x')
		{
			ft_putstr("0x");
			conv->nbc = conv->nbc + 2;
		}
		if (conv->sp == 'X')
		{
			ft_putstr("0X");
			conv->nbc = conv->nbc + 2;
		}
	}
	*d = (conv->flags & SHARP && isunoct(conv)) ? *d - 1 : *d;
	*d = (conv->flags & SHARP && isunoct(conv) && un == 0 && conv->pre > 0)
		? *d + ft_max(0, conv->pre - 1) : *d;
	*d = (conv->flags & SHARP && isunhex(conv) && un != 0
		&& !(conv->flags & PT) && conv->pre < (int)len) ? *d - 2 : *d;
}

void	print_pre_hex2(t_conv *conv, uintmax_t un)
{
	if ((un != 0 && (!(conv->flags & ZERO || conv->flags & MINUS)
				&& conv->pre < conv->mfw) && conv->flags & SHARP))
	{
		if (conv->sp == 'x')
		{
			ft_putstr("0x");
			conv->nbc = conv->nbc + 2;
		}
		if (conv->sp == 'X')
		{
			ft_putstr("0X");
			conv->nbc = conv->nbc + 2;
		}
	}
}

void	print_pre_un(t_conv *conv, int *d, size_t len, uintmax_t un)
{
	int		d0;
	char	c;

	d0 = *d;
	d0 = print_un_spaces(conv, d0, len, un);
	print_pre_hex2(conv, un);
	print_pre_pt(conv, un, len, 0);
	c = (un == 0 && conv->pre < 0 && !(conv->flags & ZERO)) ? ' ' : '0';
	if (conv->flags & SHARP && isunoct(conv)
			&& (un != 0 || conv->mfw >= (int)len + 1 || conv->pre >= (int)len))
		if ((un != 0 || conv->mfw != 0 || conv->pre >= 0)
				&& (un != 0 || conv->pre < 1) && ++conv->nbc)
			ft_putchar(c);
	while (d0-- > 0)
		if ((conv->pre >= conv->mfw) || (!(conv->flags & MINUS) &&
					conv->flags & ZERO && conv->pre < conv->mfw &&
					d0 + 1 > conv->pre - (int)len)
				|| (conv->pre < conv->mfw && d0 + 1 <= conv->pre - (int)len))
		{
			c = (un == 0 && conv->pre == 0 &&
					(isunoct(conv) || isunhex(conv))) ? ' ' : '0';
			ft_putchar(c);
			conv->nbc++;
		}
	*d = resetund(conv, d0, len, un);
}

void	print_un(t_conv *conv, va_list *ap, size_t len, int d)
{
	uintmax_t un;

	un = va_arg(*ap, uintmax_t);
	print_pre_hex1(conv, un, &d, len);
	print_pre_un(conv, &d, len, un);
	if (!(un == 0 && (isunoct(conv) || isunhex(conv)) && conv->pre == 0
				&& conv->mfw == 0 && !(conv->flags & SHARP)))
	{
		if ((un == 0 && (isunoct(conv) || isunhex(conv)) && conv->pre == 0)
				&& !((conv->flags & SHARP) && isunoct(conv)))
		{
			if (conv->mfw > 0 && (conv->nbc += len))
				ft_putchar(' ');
		}
		else
		{
			print_pre_pt(conv, un, len, 1);
			print_only_un(conv, un);
			conv->nbc += ((conv->sp == 'u' || conv->sp == 'U')
					&& conv->pre == 0 && un == 0) ? 0 : len;
		}
	}
	while ((int)len < conv->mfw && d-- > 0 && ++conv->nbc)
		ft_putchar(' ');
}
