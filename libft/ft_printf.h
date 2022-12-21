/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:57:32 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/11/27 00:09:50 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(char const *fstr, ...);
int	putnbr(int n, int fd, unsigned int flag);
int	puthex(int n, int fd, const char *hexi, unsigned int flag);
int	putptr(void *ptr, int fd);
int	putunbr(unsigned int n, int fd);
int	putstr(char *ptr, int fd, unsigned int flag);
int	putchr(int c, int fd);

# ifdef __linux__
#  define NULL_PTR ")lin("
# else
#  define NULL_PTR "0x0"
# endif

#endif
