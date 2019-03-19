/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:58 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:36 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[i + len1] = s2[i];
		i++;
	}
	s1[i + len1] = '\0';
	return (s1);
}
