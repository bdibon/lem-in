/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 11:55:10 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:24:34 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef LEM_IN_H
#	define LEM_IN_H

#include "../libft/libft.h"
#include <limits.h>

#define BUFF_SIZE 512

#define RND 0
#define START (1 << 0)
#define VLV (1 << 1)
#define ENEI (1 << 2)
#define END (1 << 3)

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

struct s_room;

typedef struct		s_tube
{
	struct s_room	*room;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	t_pos			*pos;
	ssize_t			level;
	char			type;
	t_tube			*tubes;
}					t_room;

typedef struct		s_ant
{
	unsigned int	id;
	t_queue_node	*loc;
}					t_ant;

typedef struct		s_valve
{
	unsigned int	max;
	t_room			*room;
	t_dlist			*paths;
	t_dlist			*gbc;
	t_queue			**path_tab;
}					t_valve;

typedef struct		s_colony
{
	unsigned int	nb_ants;
	unsigned int	nb_rooms;
	unsigned int	nb_tubes;
	unsigned int	nb_valves;
	t_dlist			*ants;
	t_room			*start;
	t_room			*end;
	t_dlist			*rooms;
	t_valve			**valve_tab;
}					t_colony;

t_colony			*set_colony(void);
void				*process_line(char **line, t_colony *colony);
t_room				*process_spe_line(char **line, t_colony *colony);
int					get_ants(char **line);

t_colony			*new_colony(void);
t_room				*new_room(void);
t_room				*add_room(t_colony *colony, char *line);
t_tube				*new_tube(t_room *room);
t_tube				*shift_tube(t_room *room, t_tube *new_tube);

t_dlist				*set_ants(t_colony *colony, unsigned int nb_ants);
t_tube				*push_tube(t_tube *path, t_tube *step);

t_room				*get_room_att(char *line, t_colony *colony);

int					check_room_name(t_room *r, t_colony *colony);
int					check_room_pos(t_room *r, t_colony *colony);
char				*coord_strrevseek(const char *line, char *offset, char c);
int					coord_strrevseek2(const char *line, char **offset, char c);
int					check_tube_duplicate(t_room *r1, t_room *r2);

void				*process_tube_line(char *line, t_colony *colony);
int					check_line_is_room(const char *line);
t_room				*seek_matching_room(char *name, t_colony *colony);
char				*get_room_name1(char *line, int dash);
char				*get_room_name2(char *line, int dash);

void				get_rooms_level(t_colony *colony);
void				set_room_level(t_room *room, int level);
void				colony_walk(t_colony *colony, t_queue *q);

void				dfs_set_valves(t_colony *colony);
void				dfs_end_neighbors(t_room *end);
void				pth_cut(t_queue *path, void *value);
unsigned int		compute_max(t_room *v);
void				dfs_all_paths(t_colony *col);

void				dfs_valve(t_valve *v, t_room *r, t_queue *pth);

void				trivial_sol(t_colony *col);

t_valve				*valve_create(t_room *room);
void				valve_push(t_valve *valve_tab[], t_valve *new_valve);
int					is_valve(t_colony *colony, t_room *r);
t_valve				**set_valve_tab(t_colony *colony, t_room *start);
void				pth_list_to_pth_tab(t_valve **valve_tab);

t_queue				*pth_dup(t_queue *pth, void *value);
t_room				*pth_cross(t_queue *path_1, t_queue *path_2);
void				path_cpy(t_queue **p_dest, t_queue **p_src,
		unsigned int nb_valves);
unsigned int		path_value(t_queue *path, unsigned int nb_ants);

void				filter_valves(t_colony *col);

void				compute_all_paths(t_colony *col);
void				compute_valve_paths(t_colony *col, t_queue *pth,
		t_valve *vlv);

void				sort_valves(t_valve *valve_tab[]);
void				sort_valve_paths(t_dlist **paths);

void				free_colony(t_colony *colony);
void				free_ants(t_ant **ants);
void				free_valve_tab(t_valve **valve_tab);
void				free_rooms(t_dlist *rooms);

void				ferror_std(char *s);
void				ferror_ft(char *s);

typedef struct		s_sop
{
	t_queue			**paths;
	unsigned int	*ants_partition;
	unsigned int	nbt;
	t_valve			**valve_tab;
	unsigned int	last_vlv;
	unsigned int	nb_ants;
	unsigned int	first_vlv;
}					t_sop;

typedef struct		s_bsop
{
	t_queue			**paths;
	unsigned int	*ants_partition;
	unsigned int	nbt;
}					t_bsop;

t_sop				*set_sop(t_colony *colony);
t_bsop				*set_bsop(t_colony *colony);
t_queue				**path_tab_dup(t_queue **paths, unsigned int size);

int					is_sop_better(t_sop *sop, t_bsop *bsop);
t_sop				*sop_values(t_sop *sop);
unsigned int		ant_optimal_path(t_queue **paths,
		unsigned int *ants_partition, unsigned int nb_valves);
unsigned int		sop_compute_values(unsigned int *ants_partition,
		unsigned int nb_ants, unsigned int nb_valves, t_queue **paths);
void				ants_partition_cpy(unsigned int *ap_dest,
		unsigned int *ap_src, unsigned int nb_valves);

t_bsop				*compute_bsop(t_colony *colony);
void				cbsop(t_bsop *bsop, t_sop *sop, unsigned int iv,
		unsigned int ip);
int					is_step_possible(t_sop *sop,
		unsigned int iv, t_queue *path);

void				free_sop(t_sop *sop);
void				free_bsop(t_bsop *bsop);
void				gbc_clear_destroy(t_dlist *gbc);

t_dlist				*compute_op(unsigned int nb_valves, unsigned int nb_ants,
		t_queue **ants_travel, t_queue **paths);
void				free_ants_travel(t_queue **ants_travel,
		unsigned int nb_valves);
void				compute_path_op(unsigned int *nb_ants, t_dlist *turn_op,
		t_queue *ants, t_queue *path);
char				*op_to_string(t_queue_node *ant, t_queue *path);
t_queue				**set_ants_travel(unsigned int *ants_partition,
		t_dlist *ants, unsigned int nb_valves);

void				print_output(t_dlist *op_list);
void				add_end_to_paths(t_room *end, t_queue **paths,
		unsigned int nb_valves);

#	endif
