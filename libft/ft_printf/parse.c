/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 11:48:37 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 17:42:00 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			isnumconv(char sp)
{
	return ((sp == 'd' || sp == 'D' || sp == 'i' || sp == 'o' || sp == 'O'
				|| sp == 'u' || sp == 'U' || sp == 'x'
				|| sp == 'X') ? 1 : 0);
}

int			setflags(const char *fmt, t_conv *conv)
{
	int isp;

	isp = 0;
	while (isfmt(fmt[isp]) && !isconvs(fmt[isp]))
	{
		if (fmt[isp] == ' ')
			conv->flags |= SPACE;
		if (fmt[isp] == '#')
			conv->flags |= SHARP;
		if (fmt[isp] == '+')
			conv->flags |= PLUS;
		if (fmt[isp] == '-')
			conv->flags |= MINUS;
		if (fmt[isp] == '.')
			conv->flags |= DOT;
		if (fmt[isp] == '0' && (isp == 0 || (!ft_isdigit(fmt[isp - 1])
					&& fmt[isp - 1] != '.')))
			conv->flags |= ZERO;
		isp++;
	}
	if (conv->flags & MINUS && conv->flags & ZERO)
		conv->flags &= ~ZERO;
	if (conv->flags & PLUS && conv->flags & SPACE)
		conv->flags &= ~SPACE;
	return (isp);
}

t_conv		*setconv(char **fmt, size_t nbc, va_list *ap)
{
	t_conv	*conv;
	int		isp;

	if (!(conv = malloc(sizeof(*conv))))
		return (NULL);
	conv->flags = 0;
	isp = setflags(*fmt, conv);
	conv->sp = fmt[0][isp];
	conv->lmod = getlmod(*fmt, isp);
	conv->nbc = nbc;
	conv->pre = getpre(*fmt, isp);
	conv->mfw = getmfw(*fmt, isp, conv->pre);
	check_stars(*fmt, ap, conv, isp);
	if (isnumconv(conv->sp) && conv->pre > -1)
		conv->flags &= ~ZERO;
	*fmt = *fmt + isp;
	conv->err = 0;
	return (conv);
}

size_t		get_paraml(t_conv *conv, va_list *ap)
{
	va_list		ap2;

	va_copy(ap2, *ap);
	if (conv->sp == 's' && !(conv->lmod & _L))
		return (ft_strlen(va_arg(ap2, char *)));
	if (conv->sp == 'S' || (conv->sp == 's' && conv->lmod & _L))
		return (ft_wcsbytelen(va_arg(ap2, wchar_t *)));
	if (conv->sp == 'c' && !(conv->lmod & _L))
		return (1);
	if (conv->sp == 'C' || (conv->sp == 'c' && conv->lmod & _L))
		return (ft_wcbytelen(va_arg(ap2, wchar_t)));
	if (isunsigned(conv) || issigned(conv))
		return (numlen(conv, &ap2));
	return (0);
}

char		*parse_fmt(char *fmt, va_list *ap, int *nbc)
{
	t_conv	*conv;
	int		flags;

	if (fmt[0] == '\0')
		return (fmt);
	conv = setconv(&fmt, *nbc, ap);
	print_o(conv, ap);
	*nbc = (conv->err == 1 || *nbc == -1) ? -1 : conv->nbc;
	flags = conv->flags;
	free(conv);
	return (((flags & MINUS && !isconvs(*fmt))
				|| isconvs(*fmt) || *fmt == '%') ? fmt + 1 : fmt);
}
