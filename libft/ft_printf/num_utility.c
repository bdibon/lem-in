/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   num_utility.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 11:46:42 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:24:05 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	u_numlen(t_conv *conv, uintmax_t n)
{
	if (conv->sp == 'O')
		return (ft_budigitlen(8, (unsigned long)n));
	else if (conv->sp == 'U')
		return (ft_budigitlen(10, (unsigned long)n));
	else if (conv->lmod & _HH)
		n = (unsigned char)n;
	else if (conv->lmod & _H)
		n = (unsigned short)n;
	else if (conv->lmod & _L)
		n = (unsigned long)n;
	else if (conv->lmod & _LL)
		n = (unsigned long long)n;
	else if (conv->lmod & _J)
		;
	else if (conv->lmod & _Z)
		n = (size_t)n;
	else
		n = (unsigned)n;
	if (conv->sp == 'o')
		return (ft_budigitlen(8, n));
	if (conv->sp == 'u')
		return (ft_budigitlen(10, n));
	if (conv->sp == 'x' || conv->sp == 'X')
		return (ft_budigitlen(16, n));
	return (0);
}

size_t	s_numlen(t_conv *conv, intmax_t n)
{
	if (conv->sp == 'D' || conv->lmod & _L)
		return (ft_bdigitlen(10, (long)n));
	else if (conv->lmod & _HH)
		n = (char)n;
	else if (conv->lmod & _H)
		n = (short)n;
	else if (conv->lmod & _LL)
		n = (long long)n;
	else if (conv->lmod & _J)
		;
	else if (conv->lmod & _Z)
		n = (intmax_t)n;
	else
		n = (int)n;
	if (conv->sp == 'd' || conv->sp == 'i')
		return (ft_bdigitlen(10, n));
	return (0);
}

int		issigned(t_conv *conv)
{
	if (conv->sp == 'd' || conv->sp == 'i' || conv->sp == 'D')
		return (1);
	return (0);
}

int		isunsigned(t_conv *conv)
{
	if (conv->sp == 'u' || conv->sp == 'U' || conv->sp == 'o' || conv->sp == 'O'
			|| conv->sp == 'x' || conv->sp == 'X')
		return (1);
	return (0);
}

size_t	numlen(t_conv *conv, va_list *ap)
{
	intmax_t	n1;
	uintmax_t	n2;

	if (issigned(conv))
	{
		n1 = va_arg(*ap, intmax_t);
		return (s_numlen(conv, n1));
	}
	if (isunsigned(conv))
	{
		n2 = va_arg(*ap, uintmax_t);
		return (u_numlen(conv, n2));
	}
	return (0);
}
