/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:39 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	nbw;

	nbw = 0;
	while (*s)
	{
		if (*s != c)
			nbw++;
		while (*s && *s != c)
			s++;
		s = (*s) ? s + 1 : s;
	}
	return (nbw);
}

static size_t	*get_words_s(char const *s, char c, size_t nbw)
{
	size_t			*words_s;
	size_t			i;
	size_t			j;

	if (!(words_s = (size_t *)malloc(nbw * sizeof(*words_s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				s++;
				j++;
			}
			words_s[i++] = j;
		}
		s = (*s) ? s + 1 : s;
	}
	return (words_s);
}

static	void	fill_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				tab[i][j] = *s;
				j++;
				s++;
			}
			tab[i][j] = '\0';
			i++;
		}
		s = (*s) ? s + 1 : s;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nbw;
	size_t	*words_s;
	size_t	i;

	if (!s)
		return (NULL);
	nbw = count_words(s, c);
	if (!(tab = (char **)malloc((nbw + 1) * sizeof(*tab))))
		return (NULL);
	words_s = get_words_s(s, c, nbw);
	i = 0;
	tab[nbw] = NULL;
	while (i < nbw)
	{
		if (!(tab[i] = (char *)malloc((words_s[i] + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	fill_tab(s, c, tab);
	free(words_s);
	return (tab);
}
