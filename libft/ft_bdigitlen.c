/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bdigitlen.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:00:25 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_bdigitlen(int base, intmax_t n)
{
	unsigned int len;

	len = 1;
	if (base == 10 && n < 0)
	{
		n = (n == INTMAX_MIN) ? INTMAX_MAX : -n;
		len++;
	}
	while ((n = n / base))
		len++;
	return (len);
}
