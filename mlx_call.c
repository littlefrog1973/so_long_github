/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:14:28 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/11 14:30:54 by sdeeyien         ###   ########.fr       */
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

void	init_image(void *mlx, t_window *game)
{
	t_2d_axis	size;

	(*game).wall.img = mlx_xpm_file_to_image(mlx, TREE, &(size.x), &(size.y));
	(*game).hero.img = mlx_xpm_file_to_image(mlx, WIZARD, &(size.x), &(size.y));
	(*game).key.img = mlx_xpm_file_to_image(mlx, KEY, &(size.x), &(size.y));
	(*game).door.img = mlx_xpm_file_to_image(mlx, DOOR, &(size.x), &(size.y));
	(*game).tile.img = mlx_xpm_file_to_image(mlx, TILE, &(size.x), &(size.y));
	ft_printf("In init_image: size.x = %d, size.y = %d\n", size.x, size.y);
}

void	put_image_to_win(void *mlx, void *win, void *img, t_2d_axis pos)
{
	mlx_put_image_to_window(mlx, win, img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
}

void	put_window(void *mlx, void *win, char **map, t_2d_axis size)
{
	t_window	game;
	t_2d_axis	pos;

	pos.y = 0;
	init_image(mlx, &game);
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x)
		{
			if (map[pos.y][pos.x] == '1')
				put_image_to_win(mlx, win, game.wall.img, pos);
			if (map[pos.y][pos.x] == 'P')
				put_image_to_win(mlx, win, game.hero.img, pos);
			if (map[pos.y][pos.x] == '0')
				put_image_to_win(mlx, win, game.tile.img, pos);
			if (map[pos.y][pos.x] == 'C')
				put_image_to_win(mlx, win, game.key.img, pos);
			if (map[pos.y][pos.x] == 'E')
				put_image_to_win(mlx, win, game.door.img, pos);
			pos.x++;
		}
		pos.y++;
	}
}

int	mlx_call(char **map)
{
	t_2d_axis	sz;
	void		*mlx;
	void		*mlx_win;

	map_size(map, &sz);
	ft_printf("In mlx_call: map_x = %d, map_y = %d\n", sz.x, sz.y);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, sz.x * IMG_SIZE, sz.y * IMG_SIZE, "So_Long");
	put_window(mlx, mlx_win, map, sz);
	mlx_loop(mlx);
	return (0);
}
