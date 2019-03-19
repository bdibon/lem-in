/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 17:03:06 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(*list));
	if (list)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			list->next = NULL;
		}
		else
		{
			list->content = ft_memalloc(content_size);
			list->content = ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
			list->next = NULL;
		}
	}
	return (list);
}
