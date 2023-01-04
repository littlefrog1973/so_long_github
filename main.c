/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:12:45 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/04 15:39:01 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

void err_exit(char **map, t_list **map_list_ptr, int err_no)
{
	ft_lstclear(map_list_ptr, free);
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
	exit(1);
}

int count_chr(const char *row, const char letter)
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

int chk_rectan(char **map)
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

int chk_wall(char **map)
{
	int	is_closed;
	int	i;

	i = 0;
	is_closed = 1;
	while (map[i])
	{
		is_closed &= (map[i][0] == '1' && map[i][(int) ft_strlen(map[i]) - 1] == '1');
		i++;
	}
	is_closed &= count_chr(map[i - 1], '1') && (int) ft_strlen(map[i - 1]);
	is_closed &= count_chr(map[0], '1') && (int) ft_strlen(map[0]);
	return (is_closed);
}

void chk_map(char **map, t_list **map_list_ptr)
{
	int	i;
	int	j;
	int	no_exit;
	int	no_collect;
	int	no_start;

	no_exit = 0;
	no_collect = 0;
	no_start = 0;
	i = 0;
	if (chk_rectan(map) && chk_wall(map))
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (!ft_strchr("01CEP", map[i][j]))
					err_exit(map, map_list_ptr, 1);
				no_exit += ('E' == map[i][j]);
				no_collect += ('C' == map[i][j]);
				no_start += ('P' == map[i][j]);
				j++;
			}
			i++;
		}
		if (no_exit == 1 && no_start == 1 && no_collect >= 1)
			return ;
		else if (no_exit >= 2 || no_start >= 2)
			err_exit(map, map_list_ptr, 2);
		else if (no_collect == 0)
			err_exit(map, map_list_ptr, 5);
		else
			err_exit(map, map_list_ptr, 3);
	}
	else
		err_exit(map, map_list_ptr, 4);
}

t_list **read_file(int argc, char *argv[], t_list **map_list_ptr)
{
	int	fd;
	t_list	*map_list;

	if (argc == 2 && !ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			map_list = ft_lstnew(get_next_line(fd));
			*map_list_ptr = map_list;
			while (ft_lstlast(*map_list_ptr)->content)
			{
				ft_lstadd_back(map_list_ptr, ft_lstnew(get_next_line(fd)));
			}
/*			if (map_list->content == NULL)
				exit (1);
			while (1)
			{
				ft_lstadd_back(map_list_ptr, ft_lstnew(get_next_line(fd)));
				if (!ft_lstlast(*map_list_ptr)->content)
					break;
			}
*/
			if (!map_list->content)
			{
				free(map_list);
				exit (1);
			}
			fd = close(fd);
			return (map_list_ptr);
		}
		else
			exit(1);
	}
	else
		exit(1);
}

char **parse_map(int argc, char *argv[], t_list **map_list_ptr)
{
	t_list	*map_runner;
	char	**map_array;
	int	i;

	map_list_ptr = read_file(argc, argv, map_list_ptr);
	map_array = (char **) malloc(ft_lstsize(*map_list_ptr) * sizeof(char *));
	if (!map_array)
	{
		ft_lstclear(map_list_ptr, free);
		exit(1);
	}
	map_runner = *map_list_ptr;
	i = 0;
	while (map_runner->content)
	{
		map_array[i] = map_runner->content;
		map_array[i][ft_strlen(map_array[i]) - 1] = '\0';
		map_runner = map_runner->next;
		i++;
	}
	map_array[i] = NULL;
	return (map_array);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_list	*map_list_ptr;
	int	i;

	i = 0;
	map = parse_map(argc, argv, &map_list_ptr);
	chk_map(map, &map_list_ptr);

	while (map[i])
	{
		ft_printf("parsed map[%d] = %s\n", i, map[i]);
		i++;
	}
	err_exit(map, &map_list_ptr, 0);
	return (0);
}
