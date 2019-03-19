/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 16:42:00 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:32:07 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef LIST_H
#	define LIST_H

#include <stdlib.h>

typedef struct			s_dlist_node
{
	void				*value;
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
}						t_dlist_node;

typedef struct			s_dlist
{
	size_t				size;
	t_dlist_node		*head;
	t_dlist_node		*tail;
}						t_dlist;

t_dlist_node			*node_create(void *value);

t_dlist					*list_create(void);
void					list_destroy(t_dlist *list);
void					list_clear(t_dlist *list);
void					list_clear_destroy(t_dlist *list);
void					*list_remove(t_dlist *list, t_dlist_node *node);

void					list_push(t_dlist *list, void *value);
void					*list_pop(t_dlist *list);

void					list_unshift(t_dlist *list, void *value);
void					*list_shift(t_dlist *list);

void					node_swap(t_dlist_node *a, t_dlist_node *b);
void					list_buble_sort(t_dlist *list, int (*cmp)());
void					list_split(t_dlist *list, t_dlist *left,
		t_dlist *right);
t_dlist					*list_merge_sort(t_dlist *list, int (*cmp)());

void					**list_to_tab(t_dlist *list);

#	endif
