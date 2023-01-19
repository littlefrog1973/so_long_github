# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:25:01 by sdeeyien          #+#    #+#              #
#    Updated: 2023/01/19 14:23:15 by sdeeyien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11
	MLXDIR = mlx_linux
	LIBMLX = libmlx_Linux
else
	MLXFLAGS = -Lmlx_opengl -lmlx -framework OpenGL -framework AppKit
	MLXDIR = mlx_opengl
	LIBMLX = libmlx
endif
LIBDIR = libft

DEPS = so_long.h

SRC = main.c chk_path.c mlx_call.c utils.c hooks.c check_map.c utils2.c

OBJ = $(SRC:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME): $(OBJ)
	cd $(LIBDIR) && make
	cd $(MLXDIR) && make
	$(CC) -o $@ $(OBJ) $(LIBDIR)/$(LIBDIR).a $(MLXDIR)/$(LIBMLX).a $(MLXFLAGS)

bonus : $(OBJ)
	cd $(LIBDIR) && make
	cd $(MLXDIR) && make
	$(CC) -o $(NAME) $(OBJ) $(LIBDIR)/$(LIBDIR).a $(MLXDIR)/$(LIBMLX).a $(MLXFLAGS)


%.o: %.c $(DEPS)
	$(CC) -c $< $(DEPS) $(CFLAGS)

clean :
	rm -f *.o
#	cd $(LIBDIR) && make clean
#	cd $(MLXDIR) && make clean
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean

fclean : clean
	rm -f $(NAME)
#	cd $(LIBDIR) && make fclean
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
