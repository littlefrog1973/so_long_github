/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:57:48 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/01/06 14:05:34 by sdeeyien         ###   ########.fr       */
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

#endif
