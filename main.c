/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:12:45 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/21 16:45:25 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

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
			while (1)
			{
				ft_lstadd_back(map_list_ptr, ft_lstnew(get_next_line(fd)));
				if (!ft_lstlast(*map_list_ptr)->content)
					break;
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
	ft_printf("In parse_map i=%d\n", i);
	map_array[i] = NULL;
	return (map_array);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_list	**map_list_ptr;
	t_list	*dummy;
	int	i;

	i = 0;
	map_list_ptr = &dummy;
	map = parse_map(argc, argv, map_list_ptr);
	while (map[i])
	{
		ft_printf("parsed map[%d] = %s\n", i, map[i]);
		i++;
	}
	ft_printf("test ft_strlen = %d\n", (int) ft_strlen("abc"));
	return (0);
}
