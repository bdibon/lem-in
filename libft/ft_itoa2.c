/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 18:51:15 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 19:02:00 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa2(unsigned int n)
{
	size_t				size;
	unsigned int		a;
	char				*fresh;

	size = 0;
	a = n;
	while (a != 0)
	{
		size++;
		a /= 10;
	}
	if (!(fresh = (char *)malloc(size + 1 * sizeof(*fresh))))
		return (NULL);
	fresh[size] = '\0';
	while (size - 1)
	{
		fresh[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	fresh[size - 1] = n % 10 + '0';
	return (fresh);
}
