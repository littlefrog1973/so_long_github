/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:57:48 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/11 13:35:16 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

void err_exit(char **map, int err_no);
int count_chr(const char *row, const char letter);
int chk_rectan(char **map);
int chk_wall(char **map);
void chk_map(char **map);
t_list **read_file(int argc, char *argv[], t_list **map_list_ptr);
char **parse_map(int argc, char *argv[], t_list **map_list_ptr);
int chk_path(char **map);

typedef	struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct s_2d_axis{
	int	x;
	int	y;
}	t_2d_axis;

typedef struct s_window{
	t_data	wall;
	t_data	hero;
	t_data	tile;
	t_data	key;
	t_data	door;
}	t_window;

#define IMG_SIZE 32
#define TREE "./tree.xpm"
#define WIZARD "./wizard.xpm"
#define TILE "./tile.xpm"
#define KEY "./key.xpm"
#define DOOR "./door.xpm"

int mlx_call(char **map);

#endif
