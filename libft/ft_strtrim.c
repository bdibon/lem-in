/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:41 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	size_t	end;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	len = ft_strlen(s);
	if (start == len)
		return (ft_strsub(s, (unsigned int)start, 0));
	end = len - 1;
	while (end != 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	return (ft_strsub(s, (unsigned int)start, end + 1 - start));
}
