/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcsbytelen.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:06:12 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:57:02 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcsbytelen(const wchar_t *ws)
{
	size_t len;

	len = 0;
	while (ws && *ws)
	{
		len += ft_wcbytelen(*ws);
		ws++;
	}
	return (len);
}
