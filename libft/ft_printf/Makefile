# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/17 15:12:55 by bodibon      #+#   ##    ##    #+#        #
#    Updated: 2018/02/23 16:15:26 by bodibon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.la

SRCS = $(addsuffix .c,ft_printf parse print_char print_sn print_un print_nosp \
	   num_utility parse_utility print_o print_un_utility print_sn_utility \
	   print_char_utility_01 print_char_utility_02 bonus_flags)

OBJ = $(SRCS:.c=.o)

DIR = ./
IDIR = ./
LDIR = ./libft/

CC = gcc
MAKE = make
AR = libtool
ARFLAGS =

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(OBJ) -o $@

%.o: $(addprefix $(DIR), %.c)
	$(CC) -I $(IDIR) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
