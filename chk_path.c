/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:17:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/06 17:35:14 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **map, int x, int y, int *n_exit, int *n_collect)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'E')
	{
		(*n_exit)++;
		map[x][y] = 'X';
	}
	if (map[x][y] == 'C')
	{
		(*n_collect)++;
		map[x][y] = 'X';
	}
	if (map[x][y] == '0' || map[x][y] == 'P')
		map[x][y] = 'X';
	flood_fill(map, x - 1, y, n_exit, n_collect);
	flood_fill(map, x, y + 1, n_exit, n_collect);
	flood_fill(map, x + 1, y, n_exit, n_collect);
	flood_fill(map, x, y - 1, n_exit, n_collect);
	return ;
}

void pre_flood_fill(char **map, int x, int y, int *n_exit, int *n_collect)
{
	char	**map2;
	int	i;

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
	flood_fill(map2, x, y, n_exit, n_collect);
	ft_printf("n_exit = %d, n_collect = %d\n", *n_exit, *n_collect);
	err_exit(map2, 0);
}

int chk_path(char **map)
{
	int	no_exit;
	int	no_collect;
	int	i;
	int	j;

	no_exit = 0;
	no_collect = 0;
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break;
			j++;
		}
		if (map[i][j] == 'P')
			break;
		i++;
	}
	ft_printf("In chk_path: Px = %d, Py = %d\n", i, j);
	pre_flood_fill(map, i, j, &no_exit, &no_collect);
	if (no_exit == 1 && no_collect >= 1)
		return (0);
	return (1);
}
