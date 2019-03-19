/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_04.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 13:30:26 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:28:46 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

void			node_swap(t_dlist_node *a, t_dlist_node *b)
{
	void	*tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void			list_buble_sort(t_dlist *list, int (*cmp)())
{
	t_dlist_node	*cur;
	size_t			i;
	size_t			j;
	size_t			k;

	j = 0;
	k = list->size - 1;
	while (j < list->size - 1)
	{
		i = 0;
		cur = list->head;
		while (i < k)
		{
			if (cur->next && (*cmp)(cur->value, cur->next->value) > 0)
				node_swap(cur, cur->next);
			cur = cur->next;
			i++;
		}
		k--;
		j++;
	}
}

void			list_split(t_dlist *list, t_dlist *left, t_dlist *right)
{
	int				middle;
	t_dlist_node	*cur;

	middle = list->size / 2;
	cur = list->head;
	while (cur)
	{
		if (middle > 0)
			list_push(left, cur->value);
		else
			list_push(right, cur->value);
		middle--;
		cur = cur->next;
	}
}

static t_dlist	*list_merge(t_dlist *left, t_dlist *right, int (*cmp)())
{
	t_dlist	*result;
	void	*value;

	result = list_create();
	while (left->size > 0 || right->size > 0)
	{
		if (left->size > 0 && right->size > 0)
		{
			if ((*cmp)(left->head->value, right->head->value) > 0)
				value = list_shift(right);
			else
				value = list_shift(left);
		}
		else if (left->size > 0)
			value = list_shift(left);
		else
			value = list_shift(right);
		list_push(result, value);
	}
	return (result);
}

t_dlist			*list_merge_sort(t_dlist *list, int (*cmp)())
{
	t_dlist *result;
	t_dlist *left;
	t_dlist *right;
	t_dlist *sort_left;
	t_dlist *sort_right;

	if (list->size <= 1)
		return (list);
	left = list_create();
	right = list_create();
	list_split(list, left, right);
	sort_left = list_merge_sort(left, cmp);
	sort_right = list_merge_sort(right, cmp);
	if (sort_left != left)
		list_destroy(left);
	if (sort_right != right)
		list_destroy(right);
	result = list_merge(sort_left, sort_right, cmp);
	list_destroy(sort_left);
	list_destroy(sort_right);
	return (result);
}
