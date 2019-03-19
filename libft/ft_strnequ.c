/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:38 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		equ;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	equ = 1;
	while (s1[i] && i < n && s1[i] == s2[i])
		i++;
	i = (i == n) ? i - 1 : i;
	if (s1[i] != s2[i])
		equ = 0;
	return (equ);
}
