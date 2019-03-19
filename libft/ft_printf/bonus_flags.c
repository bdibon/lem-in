/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bonus_flags.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 10:09:23 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 14:36:35 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_imfw(char *fmt, t_conv *conv, int isp)
{
	char *str;
	char *pt;

	str = ft_itoa(conv->mfw);
	if ((pt = ft_strnstr(fmt, str, isp)))
	{
		free(str);
		return (pt - fmt);
	}
	free(str);
	return (0);
}

void	check_stars(char *fmt, va_list *ap, t_conv *conv, int isp)
{
	int		i;
	int		imfw;
	int		digit;

	i = 0;
	imfw = set_imfw(fmt, conv, isp);
	while (isfmt(fmt[i]) && !isconvs(fmt[i]))
	{
		if (!(digit = 0) && fmt[i] == '*' && (i == 0 || fmt[i - 1] != '.'))
		{
			digit = va_arg(*ap, int);
			conv->mfw = (imfw > i) ? conv->mfw : digit;
			conv->flags |= (conv->mfw < 0) ? MINUS : 0;
			conv->mfw = (conv->mfw < 0) ? conv->mfw - 2 * conv->mfw : conv->mfw;
		}
		if (fmt[i] == '*' && (i != 0 && fmt[i - 1] == '.'))
		{
			conv->pre = va_arg(*ap, int);
			conv->pre = (conv->pre < 0) ? -1 : conv->pre;
		}
		i++;
	}
}
