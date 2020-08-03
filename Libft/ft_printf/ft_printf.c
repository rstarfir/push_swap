/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:23 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** ft_printf() and ft_dprintf() functions are a try to reemplement the standard
** functions printf() and dprintf().
**
** RETURN VALUE
** The functions return a number of bytes (within signed int) printed or -1 in
** case of an error.
**
** COMMENT
** There is also a couple of extra functions implemented here, including:
** 1) binary output for integers - flag 'b';
** 2) output of integers of arbitrary precision (lint library) - flag 'v';
** 3) output of unique floating point numbers (Dragon4 algorithm) - flag 'k';
** 4) color code output - %{n}, n = 0...8 (0 - default, 1 - black, 2 - red,
** 3 - green, 4 - yellow, 5 - blue, 6 - purple, 7 - cyan, 8 - white).
**
** ft_printf() and ft_dprintf() functions calls ft_vasprintf() which is another
** implementation of standard vasprintf().
*/

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	char	*str;

	va_start(ap, fmt);
	if ((i = ft_vasprintf(&str, fmt, ap)) >= 0)
	{
		i = write(1, str, i);
		free(str);
	}
	va_end(ap);
	return (i);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		i;
	char	*str;

	va_start(ap, fmt);
	if ((i = ft_vasprintf(&str, fmt, ap)) >= 0)
	{
		i = write(fd, str, i);
		free(str);
	}
	va_end(ap);
	return (i);
}
