/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 06:36:02 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(char **map, int err_no)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	if (err_no == 0)
		return ;
	if (err_no == 1)
		ft_printf("Error\nMap is composed of wrong letter.\n");
	if (err_no == 2)
		ft_printf("Error\nMap has multiple entrance or exit.\n");
	if (err_no == 3)
		ft_printf("Error\nMap is missing of entrance or exit.\n");
	if (err_no == 4)
		ft_printf("Error\nMap is not rectangular. or closed.\n");
	if (err_no == 5)
		ft_printf("Error\nMap has no collectible.\n");
	if (err_no == 6)
		ft_printf("Error\nMap has no valid path.\n");
	if (err_no == 7)
		ft_printf("Error\nOut of memory\n");
	exit(1);
}

int	ft_so_long_exit(t_game *game)
{
	if (game->map)
		err_exit(game->map, 0);
	if (game->items.door.img)
		mlx_destroy_image(game->mlx, game->items.door.img);
	if (game->items.hero.img)
		mlx_destroy_image(game->mlx, game->items.hero.img);
	if (game->items.tile.img)
		mlx_destroy_image(game->mlx, game->items.tile.img);
	if (game->items.wall.img)
		mlx_destroy_image(game->mlx, game->items.wall.img);
	if (game->items.key.img)
		mlx_destroy_image(game->mlx, game->items.key.img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	exit (0);
}

t_2d_axis	find_p(char **map, t_2d_axis size, char letter)
{
	int			x;
	int			y;
	t_2d_axis	p_pos;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[y][x] == letter)
				break ;
			x++;
		}
		if (map[y][x] == letter)
			break ;
		y++;
	}
	p_pos.x = x;
	p_pos.y = y;
	return (p_pos);
}

void	change_map(char **map, t_2d_axis p_pos, int direction)
{
	if (direction == UP && map[p_pos.y - 1][p_pos.x] != '1')
	{
		p_pos.y -= 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y + 1][p_pos.x] = '0';
	}
	if (direction == DOWN && map[p_pos.y + 1][p_pos.x] != '1')
	{
		p_pos.y += 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y - 1][p_pos.x] = '0';
	}
	if (direction == LEFT && map[p_pos.y][p_pos.x - 1] != '1')
	{
		p_pos.x -= 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y][p_pos.x + 1] = '0';
	}
	if (direction == RIGHT && map[p_pos.y][p_pos.x + 1] != '1')
	{
		p_pos.x += 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y][p_pos.x - 1] = '0';
	}
}

void	move_cur(char **map, int direction, t_2d_axis size, int *n_move)
{
	t_2d_axis	p_pos;

	p_pos = find_p(map, size, 'P');
	if (direction == UP && map[p_pos.y - 1][p_pos.x] != '1')
	{
		change_map(map, p_pos, direction);
		(*n_move)++;
	}
	if (direction == DOWN && map[p_pos.y + 1][p_pos.x] != '1')
	{
		change_map(map, p_pos, direction);
		(*n_move)++;
	}
	if (direction == LEFT && map[p_pos.y][p_pos.x - 1] != '1')
	{
		change_map(map, p_pos, direction);
		(*n_move)++;
	}
	if (direction == RIGHT && map[p_pos.y][p_pos.x + 1] != '1')
	{
		change_map(map, p_pos, direction);
		(*n_move)++;
	}
	ft_printf("Number of movement = %d\n", *n_move);
}
