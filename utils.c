/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/12 12:33:12 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close(void)
{
	exit(0);
}

t_2d_axis	find_P(char **map, t_2d_axis size, char letter)
{
	int	x;
	int	y;
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

void	move_cur(char **map, int direction, t_2d_axis size)
{
	t_2d_axis	p_pos;

	p_pos = find_P(map, size, 'P');
	ft_printf("In move_cur before(%d,%d): %c\n", p_pos.x, p_pos.y,map[p_pos.y][p_pos.x]);
	change_map(map, p_pos, direction);
	ft_printf("In move_cur after(%d,%d): %c\n", p_pos.x, p_pos.y, map[p_pos.y][p_pos.x]);
}
