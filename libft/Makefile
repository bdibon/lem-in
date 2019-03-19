# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/08 12:17:38 by bodibon      #+#   ##    ##    #+#        #
#    Updated: 2018/10/10 19:02:11 by bodibon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

SRCS = $(addsuffix .c,ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
	   ft_isdigit ft_isprint ft_itoa ft_memalloc ft_memcpy ft_memchr \
	   ft_memcmp ft_memccpy ft_memdel ft_memmove ft_memset ft_putchar \
	   ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd \
	   ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp \
	   ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri \
	   ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat \
	   ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr \
	   ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper \
	   ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
	   ft_match ft_swap ft_putnbr_base ft_strcapitalize ft_strrev \
	   ft_strexpand get_line ft_wcslen ft_bdigitlen ft_putwc \
	   ft_putwcs ft_wcbytelen ft_wcsbytelen ft_budigitlen \
	   ft_putunbr_base ft_max list_01 list_02 list_03 list_04 list_05 \
	   ft_strisnum ft_atoi2 queue_01 queue_02 queue_03 ft_itoa2)

LIB01 = libft.la
LIB02 = libftprintf.la

DIR = ./
IDIR = ./
DLIB01 = $(DIR)
DLIB02 = ./ft_printf/

OBJ = $(SRCS:.c=.o)
OLIB01 = $(addprefix $(DLIB01), $(LIB01))
OLIB02 = $(addprefix $(DLIB02), $(LIB02))

CC = gcc
AR = libtool

CFLAGS = -Wall -Wextra -Werror
ARFLAGS =

all: $(NAME)

$(NAME): $(OBJ) $(OLIB01) $(OLIB02)
		$(AR) $(ARFLAGS) $(OLIB01) $(OLIB02) -o $@

$(OLIB01): $(OBJ)
		$(AR) $(ARFLAGS) $(OBJ) -o $(addprefix $(DLIB01), $(OLIB01))

$(OLIB02):
		make -C $(DLIB02)

%.o: $(addprefix $(DIR), %.c)
		$(CC) -I $(IDIR) $(CFLAGS) -c $^ -o $@

clean:
		rm -f $(OBJ)
		rm -f $(addprefix $(DLIB01), $(OLIB01))
		make -C $(DLIB02) fclean

fclean: clean
		rm -f $(NAME)

re: fclean all
