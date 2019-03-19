/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:30 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int word;

	i = 0;
	while (str[i])
	{
		word = 0;
		while ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9'))
		{
			if ((str[i] >= 'a' && str[i] <= 'z') && word == 0)
				str[i] = str[i] - ('a' - 'A');
			else if ((str[i] >= 'A' && str[i] <= 'Z') && word == 1)
				str[i] = str[i] + ('a' - 'A');
			word = 1;
			i++;
		}
		i++;
	}
	return (str);
}
