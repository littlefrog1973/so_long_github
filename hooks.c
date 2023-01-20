/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:53:09 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/20 08:37:10 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p_e_pos(t_2d_axis pos_e, char **map)
{
	t_2d_axis	pos_p;

	pos_p = find_p(map, 'P');
	if (pos_p.x == pos_e.x && pos_p.y == pos_e.y)
		return (1);
	else
		return (0);
}

int	ft_key_input(int key, void *param)
{
	static int	n_collect;
	t_game		*game;
	static int	map_collect;
	t_2d_axis	pos_exit;

	game = (t_game *) param;
	pos_exit = find_p(game->map, 'E');
	if (!map_collect)
		map_collect = count_collect(game->map, 'C');
	mlx_clear_window(game->mlx, game->mlx_win);
	if (key == UP)
		move_cur(game, UP, &(game->n_move), &n_collect);
	else if (key == DOWN)
		move_cur(game, DOWN, &(game->n_move), &n_collect);
	else if (key == LEFT)
		move_cur(game, LEFT, &(game->n_move), &n_collect);
	else if (key == RIGHT)
		move_cur(game, RIGHT, &(game->n_move), &n_collect);
	else if (key == ESC)
		ft_so_long_exit(game);
	if (n_collect == map_collect && check_p_e_pos(pos_exit, game->map))
		ft_so_long_end_game(game);
	put_window(*game);
	return (0);
}

int	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	put_window(*game);
	return (0);
}
