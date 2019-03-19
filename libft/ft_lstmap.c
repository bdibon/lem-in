/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 12:11:53 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 12:13:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *n_lst;
	t_list *begin;

	n_lst = (t_list *)malloc(sizeof(*n_lst));
	begin = n_lst;
	if (n_lst)
		while (lst)
		{
			n_lst->content = ft_memalloc(f(lst)->content_size);
			n_lst->content = ft_memcpy(n_lst->content, f(lst)->content,
					f(lst)->content_size);
			n_lst->content_size = f(lst)->content_size;
			if (lst->next)
				n_lst->next = (t_list *)malloc(sizeof(*(n_lst->next)));
			else
				n_lst->next = NULL;
			n_lst = n_lst->next;
			lst = lst->next;
		}
	return (begin);
}
