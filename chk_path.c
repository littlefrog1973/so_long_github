/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:17:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 17:03:50 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map, const char letter)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count += (map[i][j] == letter);
			j++;
		}
		i++;
	}
	return (count);
}

void	init_2d_axis(t_2d_axis *var)
{
	(*var).x = 0;
	(*var).y = 0;
}

void	flood_fill(char **map, int x, int y, t_2d_axis *items)
//void flood_fill(char **map, int x, int y, int *n_exit, int *n_collect)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'E')
	{
		items->x++;
		map[x][y] = 'X';
	}
	if (map[x][y] == 'C')
	{
		items->y++;
		map[x][y] = 'X';
	}
	if (map[x][y] == '0' || map[x][y] == 'P')
		map[x][y] = 'X';
	flood_fill(map, x - 1, y, items);
	flood_fill(map, x, y + 1, items);
	flood_fill(map, x + 1, y, items);
	flood_fill(map, x, y - 1, items);
	return ;
}

void	pre_flood_fill(char **map, int x, int y, t_2d_axis *items)
//void pre_flood_fill(char **map, int x, int y, int *n_exit, int *n_collect)
{
	char	**map2;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map2 = (char **) ft_calloc((i + 1), sizeof(char *));
	if (!map2)
		err_exit(map, 7);
	i = 0;
	while (map[i])
	{
		map2[i] = ft_strdup(map[i]);
		if (!map2[i])
		{
			err_exit(map, 0);
			err_exit(map2, 7);
		}
		i++;
	}
	flood_fill(map2, x, y, items);
	err_exit(map2, 0);
}

int	chk_path(char **map)
// items.x = n_exit, items.y = n_collect
{
	t_2d_axis	items;
	int			i;
	int			j;

	init_2d_axis(&items);
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break ;
			j++;
		}
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	pre_flood_fill(map, i, j, &items);
	if (items.x == 1 && items.y >= 1)
	{
		return (0);
	}
	return (1);
}
