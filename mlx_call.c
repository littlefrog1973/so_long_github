/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:14:28 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 00:36:31 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(char **map, t_2d_axis *size)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[0][j])
		j++;
	(*size).x = j;
	(*size).y = i;
}

void	init_images(void *mlx, t_window *game)
{
	t_2d_axis	size;

	(*game).wall.img = mlx_xpm_file_to_image(mlx, TREE, &(size.x), &(size.y));
	(*game).hero.img = mlx_xpm_file_to_image(mlx, WIZARD, &(size.x), &(size.y));
	(*game).key.img = mlx_xpm_file_to_image(mlx, KEY, &(size.x), &(size.y));
	(*game).door.img = mlx_xpm_file_to_image(mlx, DOOR, &(size.x), &(size.y));
	(*game).tile.img = mlx_xpm_file_to_image(mlx, TILE, &(size.x), &(size.y));
}

void	put_image_to_win(void *mlx, void *win, void *img, t_2d_axis pos)
{
	mlx_put_image_to_window(mlx, win, img, pos.x * IM_SIZE, pos.y * IM_SIZE);
}

void	put_window(t_game win)
{
	t_2d_axis	pos;

	pos.y = 0;
	while (pos.y < win.size.y)
	{
		pos.x = 0;
		while (pos.x < win.size.x)
		{
			if (win.map[pos.y][pos.x] == '1')
				put_image_to_win(win.mlx, win.mlx_win, win.items.wall.img, pos);
			if (win.map[pos.y][pos.x] == 'P')
				put_image_to_win(win.mlx, win.mlx_win, win.items.hero.img, pos);
			if (win.map[pos.y][pos.x] == '0')
				put_image_to_win(win.mlx, win.mlx_win, win.items.tile.img, pos);
			if (win.map[pos.y][pos.x] == 'C')
				put_image_to_win(win.mlx, win.mlx_win, win.items.key.img, pos);
			if (win.map[pos.y][pos.x] == 'E')
				put_image_to_win(win.mlx, win.mlx_win, win.items.door.img, pos);
			pos.x++;
		}
		pos.y++;
	}
}

int	mlx_call(char **map)
{
	t_2d_axis	sz;
	t_game		win;

	map_size(map, &sz);
	win.mlx = mlx_init();
	if (!win.mlx)
		err_exit(map, 7);
	win.mlx_win = mlx_new_window(win.mlx, sz.x * IM_SIZE, sz.y * IM_SIZE, "SL");
	if (!win.mlx_win)
	{
		free(win.mlx);
		err_exit(map, 7);
	}
	win.map = map;
	win.size = sz;
	init_images(win.mlx, &(win.items));
	put_window(win);
	mlx_hook(win.mlx_win, 17, 0, *ft_so_long_exit, &win);
	mlx_key_hook(win.mlx_win, *ft_key_input, &win);
	mlx_loop(win.mlx);
	return (0);
}
