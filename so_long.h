/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:57:48 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/17 09:13:58 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# ifdef __linux__
#  include "mlx_linux/mlx.h"
# else
#  include "mlx_opengl/mlx.h"
# endif
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct s_game{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_2d_axis	size;
	t_window	items;
	t_2d_axis	pos_e;
}	t_game;

# define IM_SIZE 32
# define TREE "./tree.xpm"
# define WIZARD "./wizard.xpm"
# define TILE "./tile.xpm"
# define KEY "./key.xpm"
# define DOOR "./door.xpm"
# define MAP "./sample.ber"

# ifdef __linux__
#  define KEY_A 97
#  define KEY_B 98
#  define KEY_C 99
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104
#  define KEY_I 105
#  define KEY_J 106
#  define KEY_K 107
#  define KEY_L 108
#  define KEY_M 109
#  define KEY_N 110
#  define KEY_O 111
#  define KEY_P 112
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_S 115
#  define KEY_T 116
#  define KEY_U 117
#  define KEY_V 118
#  define KEY_W 119
#  define KEY_X 120
#  define KEY_Y 121
#  define KEY_Z 122

#  define KEY_0 48
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57

#  define KEY_BCK_TICK 96
#  define KEY_HYPHEN 45
#  define KEY_EQUAL 61
#  define KEY_SLASH 47
#  define KEY_BCK_SLASH 92
#  define KEY_DOT 46
#  define KEY_SEMI_COLON 59
#  define KEY_QUOTE 39
#  define KEY_SPACE 32
#  define KEY_TAB 65289
#  define ARW_UP 65362
#  define ARW_DOWN 65364
#  define ARW_LEFT 65361
#  define ARW_RIHGT 65363
#  define LEFT_SHIFT 65505
#  define RIGHT_SHIFT 65506
#  define ESC 65307
#  define LEFT_CTRL 65507
#  define RIGHT_CTRL 65508
#  define LEFT_ALT 65513
#  define RIGHT_ALT 65514
#  define DELETE 65535
#  define HOME 65360
#  define END 65367
#  define ENTER 65293
#  define BCK_SPC 65288
# else
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_S 1
#  define KEY_W 13
#  define ESC 53
# endif

# define UP KEY_W
# define DOWN KEY_S
# define LEFT KEY_A
# define RIGHT KEY_D

void		err_exit(char **map, int err_no);
int			count_chr(const char *row, const char letter);
int			chk_rectan(char **map);
int			chk_wall(char **map);
void		chk_map(char **map);
t_list		**read_file(int argc, char *argv[], t_list **map_list_ptr);
char		**parse_map(int argc, char *argv[], t_list **map_list_ptr);
int			chk_path(char **map);
int			mlx_call(char **map);
int			ft_key_input(int key, void *param);
int			ft_mouse_input(int key, int x, int y, void *param);
int			ft_update(void *param);
void		move_cur(t_game *win, int direction, int *n_move, int *n_collect);
void		put_window(t_game win);
int			ft_so_long_exit(t_game *game);
void		err_exit(char **map, int err_no);
void		blank(void *a);
void		chk_map(char **map);
int			count_collect(char **map, const char letter);
t_2d_axis	find_p(char **map, char letter);
void		update_map(t_game *win, t_2d_axis p_pos, int *n_collect,
				int direction);
#endif
