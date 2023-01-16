/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 16:50:22 by sdeeyien         ###   ########.fr       */
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
	free(game->mlx);
	exit (0);
}

t_2d_axis	find_p(char **map, char letter)
{
	int			x;
	int			y;
	t_2d_axis	p_pos;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
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

void	change_map(char **map, t_2d_axis p_pos, int direction, char letter)
{
	if (direction == UP && map[p_pos.y - 1][p_pos.x] != '1')
	{
		p_pos.y -= 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y + 1][p_pos.x] = letter;
	}
	if (direction == DOWN && map[p_pos.y + 1][p_pos.x] != '1')
	{
		p_pos.y += 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y - 1][p_pos.x] = letter;
	}
	if (direction == LEFT && map[p_pos.y][p_pos.x - 1] != '1')
	{
		p_pos.x -= 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y][p_pos.x + 1] = letter;
	}
	if (direction == RIGHT && map[p_pos.y][p_pos.x + 1] != '1')
	{
		p_pos.x += 1;
		map[p_pos.y][p_pos.x] = 'P';
		map[p_pos.y][p_pos.x - 1] = letter;
	}
}

void	move_cur(t_game *win, int direction, int *n_move, int *n_collect)
{
	t_2d_axis	p_pos;

	p_pos = find_p(win->map, 'P');
	if (direction == UP && win->map[p_pos.y - 1][p_pos.x] != '1')
	{
		if (win->map[p_pos.y - 1][p_pos.x] == 'C')
			(*n_collect)++;
		if (win->pos_e.x == p_pos.x && win->pos_e.y == p_pos.y)
			change_map(win->map, p_pos, direction, 'E');
		else
			change_map(win->map, p_pos, direction, '0');
		(*n_move)++;
	}
	if (direction == DOWN && win->map[p_pos.y + 1][p_pos.x] != '1')
	{
		if (win->map[p_pos.y + 1][p_pos.x] == 'C')
			(*n_collect)++;
		if (win->pos_e.x == p_pos.x && win->pos_e.y == p_pos.y)
			change_map(win->map, p_pos, direction, 'E');
		else
			change_map(win->map, p_pos, direction, '0');
		(*n_move)++;
	}
	if (direction == LEFT && win->map[p_pos.y][p_pos.x - 1] != '1')
	{
		if (win->map[p_pos.y][p_pos.x - 1] == 'C')
			(*n_collect)++;
		if (win->pos_e.x == p_pos.x && win->pos_e.y == p_pos.y)
			change_map(win->map, p_pos, direction, 'E');
		else
			change_map(win->map, p_pos, direction, '0');
		(*n_move)++;
	}
	if (direction == RIGHT && win->map[p_pos.y][p_pos.x + 1] != '1')
	{
		if (win->map[p_pos.y][p_pos.x + 1] == 'C')
			(*n_collect)++;
		if (win->pos_e.x == p_pos.x && win->pos_e.y == p_pos.y)
			change_map(win->map, p_pos, direction, 'E');
		else
			change_map(win->map, p_pos, direction, '0');
		(*n_move)++;
	}
	ft_printf("Number of movement = %d\n", *n_move);
	ft_printf("n_collect = %d\n", *n_collect);
}
