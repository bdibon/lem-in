/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:58 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:36 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*fresh;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(fresh = (char *)malloc((len + 1) * sizeof(*fresh))))
		return (NULL);
	while (i < len)
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[len] = '\0';
	return (fresh);
}
