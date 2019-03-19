/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:57 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:35 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*fresh;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(fresh = (char *)malloc((len + 1) * sizeof(*fresh))))
		return (NULL);
	fresh[len] = '\0';
	while (--len > 0)
		fresh[len] = f(s[len]);
	fresh[len] = f(s[len]);
	return (fresh);
}
