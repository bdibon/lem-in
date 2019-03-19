/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:40 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;
	size_t i;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (i < len && *(haystack + i) == *(needle + i))
			i++;
		if (i == len)
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
