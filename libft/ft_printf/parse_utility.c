/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_utility.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 11:52:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:54:55 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		isfmt(char c)
{
	int i;

	i = 0;
	if (ft_isdigit(c))
		return (1);
	if (!c)
		return (0);
	while (g_flags[i] && c != g_flags[i])
		i++;
	return (g_flags[i] == '\0' ? 0 : 1);
}

int		isconvs(char c)
{
	int i;

	i = CONVS_FI;
	while (i < LENM_FI)
		if (c == g_flags[i++])
			return (1);
	return (0);
}

int		getlmod(const char *fmt, int isp)
{
	int lmod;

	lmod = 0;
	if (ft_strnstr(fmt, "z", isp))
		lmod |= _Z;
	if (lmod == 0 && ft_strnstr(fmt, "j", isp))
		lmod |= _J;
	if (lmod == 0 && ft_strnstr(fmt, "ll", isp))
		lmod |= _LL;
	if (lmod == 0 && ft_strnstr(fmt, "l", isp))
		lmod |= _L;
	if (lmod == 0 && ft_strnstr(fmt, "hh", isp))
		lmod |= _HH;
	if (lmod == 0 && ft_strnstr(fmt, "h", isp))
		lmod |= _H;
	return (lmod);
}

int		getpre(const char *fmt, int isp)
{
	size_t	i;
	char	*pt;

	if ((pt = ft_strnstr(fmt, ".", isp)) == NULL)
		return (-1);
	i = pt - fmt;
	return (ft_isdigit(fmt[i + 1]) ? ft_atoi(&fmt[i + 1]) : 0);
}

int		getmfw(const char *fmt, int isp, int pre)
{
	int i;
	int p;
	int mfw;

	p = 1;
	mfw = 0;
	if (pre < 0)
	{
		i = isp - 1;
		while (fmt[i] != '%' && i >= 0 && !ft_isdigit(fmt[i]))
			i--;
		while (i >= 0 && ft_isdigit(fmt[i]))
		{
			mfw += (fmt[i--] - '0') * p;
			p *= 10;
		}
		return ((mfw == 0) ? 0 : mfw);
	}
	i = (ft_strnstr(fmt, ".", isp) - 1) - fmt;
	while (i >= 0 && ft_isdigit(fmt[i]))
	{
		mfw += (fmt[i--] - '0') * p;
		p *= 10;
	}
	return ((mfw == 0) ? 0 : mfw);
}
