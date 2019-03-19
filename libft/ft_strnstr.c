/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:38 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t lnee;
	size_t i;

	lnee = ft_strlen(needle);
	if (lnee == 0)
		return ((char *)haystack);
	while (len != 0 && *haystack)
	{
		i = 0;
		while (i < len && i < lnee && *(haystack + i) == *(needle + i))
			i++;
		if (i == lnee)
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
