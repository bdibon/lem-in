# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/31 15:47:43 by bodibon      #+#   ##    ##    #+#        #
#    Updated: 2018/11/19 12:20:36 by bodibon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME_1 = lem-in

SDIR = ./srcs/
IDIR = ./includes/
LDIR = ./libft/
ODIR = ./obj/

SRCS = $(addsuffix .c, alloc_01 alloc_02 bsop_01 bsop_02 bsop_03 \
						colony_walk compute_path_op \
						display_sol_01 display_sol_02 error free_01 free_02 \
						get_room_att main parse_01 parse_02 path_utility \
						set_colony sort_valves valves valves_02 \
						trivial_sol dfs_01 dfs_02)

HEADERS = $(addsuffix .h, lem_in)

OBJ_1 = $(addprefix $(ODIR), $(SRCS:.c=.o))

LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2

all: $(LIB) $(NAME_1)

$(NAME_1): $(OBJ_1)
	$(CC) $(addprefix $(LDIR), $(LIB)) $(CFLAGS) $(OBJ_1) -o $@

$(LIB):
	make -C $(LDIR)

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.c) $(addprefix $(IDIR), $(HEADERS))

	mkdir -p $(ODIR)
	$(CC) -I $(IDIR) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(ODIR)
	make -C $(LDIR) clean

fclean: clean
	rm -f $(NAME_1) $(NAME_2)
	make -C $(LDIR) fclean

re: fclean all
