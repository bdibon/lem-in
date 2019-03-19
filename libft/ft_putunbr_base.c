/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putunbr_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 14:49:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 11:41:05 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	basenumlen(uintmax_t n, int base_len)
{
	int	num_len;

	num_len = 1;
	while (n / base_len)
	{
		n = n / base_len;
		num_len++;
	}
	return (num_len);
}

void		ft_putunbr_base(uintmax_t n, char *base)
{
	int		base_len;
	int		num_len;
	char	*num_str;

	base_len = ft_strlen(base);
	num_len = basenumlen(n, base_len);
	if (!(num_str = malloc(sizeof(*num_str) * num_len + 1)))
		return ;
	num_str[num_len] = '\0';
	while (--num_len >= 0)
	{
		num_str[num_len] = base[n % base_len];
		n = n / base_len;
	}
	ft_putstr(num_str);
	free(num_str);
}
