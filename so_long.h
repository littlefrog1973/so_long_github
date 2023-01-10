/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:57:48 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/10 14:21:32 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

void err_exit(char **map, int err_no);
int count_chr(const char *row, const char letter);
int chk_rectan(char **map);
int chk_wall(char **map);
void chk_map(char **map);
t_list **read_file(int argc, char *argv[], t_list **map_list_ptr);
char **parse_map(int argc, char *argv[], t_list **map_list_ptr);
int chk_path(char **map);

typedef	struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;
int mlx_call(char **map);

#endif
