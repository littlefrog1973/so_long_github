/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:14:28 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/11 04:30:50 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_size(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[0][j])
		j++;
	*x = j;
	*y = i;
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_wall(void *mlx, void *mlx_win, t_data wall, t_data wizard, t_data key, t_data door, t_data tile, char **map)
{
	int x;
	int y;
	int i;
	int j;

	i = 0;
	map_size(map, &x, &y);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx, mlx_win, wall.img, j * 32, i * 32);
			}
			if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, wizard.img, j * 32, i * 32);
			}
			if (map[i][j] == '0')
			{
				mlx_put_image_to_window(mlx, mlx_win, tile.img, j * 32, i * 32);
			}
			if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx, mlx_win, key.img, j * 32, i * 32);
			}
			if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx, mlx_win, door.img, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

int mlx_call(char **map)
{
	int	x;
	int y;
	int	wall_x;
	int	wall_y;
	void	*mlx;
	void	*mlx_win;
	t_data	wall;
	t_data	wizard;
	t_data	key;
	t_data	door;
	t_data	tile;
//	int i, j;

	x = 0;
	y = 0;
	map_size(map, &x, &y);
	ft_printf("In mlx_call: map_x = %d, map_y = %d\n", x, y);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x * 32, y * 32, "So_Long");
	wall.img = mlx_xpm_file_to_image(mlx,"./tree_on_tile.xpm", &wall_x, &wall_y);
	wizard.img = mlx_xpm_file_to_image(mlx,"./wizard_on_tile.xpm", &wall_x, &wall_y);
	key.img = mlx_xpm_file_to_image(mlx,"./key_on_tile.xpm", &wall_x, &wall_y);
	door.img = mlx_xpm_file_to_image(mlx,"./door.xpm", &wall_x, &wall_y);
	tile.img = mlx_xpm_file_to_image(mlx,"./tile.xpm", &wall_x, &wall_y);
	ft_printf("In mlx_call: wall_x = %d, wall_y = %d\n", wall_x, wall_y);

	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length, &wall.endian);
	put_wall(mlx, mlx_win, wall, wizard, key, door, tile, map);
//	mlx_put_image_to_window(mlx, mlx_win, wall.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
