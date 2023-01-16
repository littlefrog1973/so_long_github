/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:36:51 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/16 15:01:38 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collect(char **map, const char letter)
{
	int	i;
	int	j;
	int count;

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

int	count_chr(const char *row, const char letter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (row[i] != '\0')
	{
		count += (row[i] == letter);
		i++;
	}
	return (count);
}

int	chk_rectan(char **map)
{
	int	i;
	int	diff;
	int	row_length;

	i = 0;
	diff = 0;
	row_length = (int) ft_strlen(map[i]);
	while (map[i])
	{
		if (row_length - (int) ft_strlen(map[i]))
			diff = 1;
		i++;
	}
	return (!diff);
}

int	chk_wall(char **map)
{
	int	closed;
	int	i;
	int	dum;

	i = 0;
	closed = 1;
	dum = 0;
	while (map[i])
	{
		if ((map[i][0] == '1' && map[i][(int) ft_strlen(map[i]) - 1] == '1'))
			dum = 1;
		else
			dum = 0;
		closed = dum * closed;
		i++;
	}
	dum = 0;
	if (count_chr(map[i - 1], '1') == (int) ft_strlen(map[i - 1])
		&& (count_chr(map[0], '1') == (int) ft_strlen(map[0])))
			dum = 1;
	else
			dum = 0;
	closed = closed * dum;
	return (closed);
}

void	chk_map_detail(char **map, int *n_ext, int *n_col, int *n_str)
{
	int	i;
	int	j;

	*n_ext = 0;
	*n_col = 0;
	*n_str = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01CEP", map[i][j]))
				err_exit(map, 1);
			*n_ext += ('E' == map[i][j]);
			*n_col += ('C' == map[i][j]);
			*n_str += ('P' == map[i][j]);
			j++;
		}
		i++;
	}
}

void	chk_map(char **map)
{
	int	no_exit;
	int	no_collect;
	int	no_start;

	if (chk_rectan(map) && chk_wall(map))
	{
		chk_map_detail(map, &no_exit, &no_collect, &no_start);
		if (no_exit == 1 && no_start == 1 && no_collect >= 1)
		{
			if (chk_path(map))
				err_exit(map, 6);
			return ;
		}
		else if (no_exit >= 2 || no_start >= 2)
			err_exit(map, 2);
		else if (no_collect == 0)
			err_exit(map, 5);
		else
			err_exit(map, 3);
	}
	else
		err_exit(map, 4);
}
