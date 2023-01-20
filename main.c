/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:12:45 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/20 09:18:52 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	blank(void *a)
{
	a = a + 0;
}

t_list	**read_file(char *argv[], t_list **map_list_ptr)
{
	int		fd;
	t_list	*map_list;

	if (!ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			map_list = ft_lstnew(get_next_line(fd));
			*map_list_ptr = map_list;
			while (ft_lstlast(*map_list_ptr)->content)
				ft_lstadd_back(map_list_ptr, ft_lstnew(get_next_line(fd)));
			if (!map_list->content)
			{
				free(map_list);
				err_exit_main(3);
			}
			fd = close(fd);
			return (map_list_ptr);
		}
		else
			perror("Error\n");
	}
	exit(1);
}

char	**parse_map(char *argv[], t_list **map_list_ptr)
{
	t_list	*map_runner;
	char	**map_array;
	int		i;

	map_list_ptr = read_file(argv, map_list_ptr);
	map_array = (char **) malloc(ft_lstsize(*map_list_ptr) * sizeof(char *));
	if (!map_array)
	{
		ft_lstclear(map_list_ptr, free);
		err_exit_main(1);
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
	ft_lstclear(map_list_ptr, blank);
	return (map_array);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_list	*map_list_ptr;

	if (argc != 2)
		err_exit_main(1);
	if (ft_strlen(argv[1]) < 4)
		err_exit_main(2);
	map = parse_map(argv, &map_list_ptr);
	chk_map(map);
	mlx_call(map);
	err_exit(map, 0);
	return (0);
}
