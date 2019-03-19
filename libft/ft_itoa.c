/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t	size;
	int		a;
	char	*fresh;
	int		sign;

	size = (n <= 0) ? 1 : 0;
	a = n;
	while (a != 0)
	{
		size++;
		a /= 10;
	}
	if (!(fresh = (char *)malloc(size + 1 * sizeof(*fresh))))
		return (NULL);
	fresh[size] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (size - 1 != 0)
	{
		fresh[size - 1] = (sign * (long)n) % 10 + '0';
		n = n / 10;
		size--;
	}
	fresh[size - 1] = (sign == 1) ? n % 10 + '0' : '-';
	return (fresh);
}
