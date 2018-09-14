# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 09:08:03 by szverhov          #+#    #+#              #
#    Updated: 2017/11/06 12:25:29 by szverhov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_atoi.c ft_init_start_end.c\
        ft_check_double_space.c \
        ft_clean_nest.c ft_read_links_inners.c\
        ft_is_it_int.c ft_coords.c \
		ft_make_ant_nest.c \
        ft_read_links_of_ant_nest.c \
        ft_rooms_init_add.c \
        ft_strcmp.c \
        ft_sub_str.c ft_itoa.c\
        main.c ft_start_end_rooms.c ft_inners_make_ant_nest.c ft_moove_ants.c get_next_line.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
