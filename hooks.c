/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:53:09 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 00:33:08 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse_input(int key, int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	ft_printf("Mouse click code =%d, x = %d, y = %d\n", key, x, y);
	mlx_clear_window(game->mlx, game->mlx_win);
	put_window(*game);
	return (0);
}

int	ft_key_input(int key, void *param)
{
	static int	n_move;
	t_game		*game;

	game = (t_game *) param;
	mlx_clear_window(game->mlx, game->mlx_win);
	if (key == UP)
		move_cur(game->map, UP, game->size, &n_move);
	else if (key == DOWN)
		move_cur(game->map, DOWN, game->size, &n_move);
	else if (key == LEFT)
		move_cur(game->map, LEFT, game->size, &n_move);
	else if (key == RIGHT)
		move_cur(game->map, RIGHT, game->size, &n_move);
	else if (key == ESC)
		ft_so_long_exit(game);
	put_window(*game);
	ft_printf("Key pressed -> %d\n", key);
	return (0);
}
