# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/01/16 22:53:03 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -lXext -lX11

LIBDIR = libft

DEPS = so_long.h

SRC = main.c chk_path.c mlx_call.c utils.c hooks.c check_map.c utils2.c

OBJ = $(SRC:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME): $(OBJ)
	cd $(LIBDIR) && make
	$(CC) -o $@ $(OBJ) $(LIBDIR)/$(LIBDIR).a $(MLXFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(DEPS) $(CFLAGS)

clean :
	rm -f *.o
	cd $(LIBDIR) && make clean

fclean : clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re : fclean all

.PHONY : all clean fclean re bonus
