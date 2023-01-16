/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:51:13 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 22:56:21 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	update_map(t_game *win, t_2d_axis p_pos, int *n_collect, int direction)
{
	if (direction == UP && (win->map[p_pos.y - 1][p_pos.x] == 'C'))
		(*n_collect)++;
	if (direction == DOWN && (win->map[p_pos.y + 1][p_pos.x] == 'C'))
		(*n_collect)++;
	if (direction == LEFT && (win->map[p_pos.y][p_pos.x - 1] == 'C'))
		(*n_collect)++;
	if (direction == RIGHT && (win->map[p_pos.y][p_pos.x + 1] == 'C'))
		(*n_collect)++;
	if (win->pos_e.x == p_pos.x && win->pos_e.y == p_pos.y)
		change_map(win->map, p_pos, direction, 'E');
	else
		change_map(win->map, p_pos, direction, '0');
}
