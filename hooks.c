/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:53:09 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/11 22:40:36 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_input(int key, void *param)
{
	t_game *game = (t_game *) param;

	mlx_clear_window(game->mlx, game->mlx_win);

	if (key == UP )
		move_cur(game->map, UP, game->size);
	else if (key == DOWN)
		move_cur(game->map, DOWN, game->size);
	else if (key == LEFT)
		move_cur(game->map, LEFT, game->size);
	else if (key == RIGHT)
		move_cur(game->map, RIGHT, game->size);

	put_window(game->mlx, game->mlx_win, game->map, game->size);
	ft_printf("Key pressd -> %d\n", key);
	return (0);
}
