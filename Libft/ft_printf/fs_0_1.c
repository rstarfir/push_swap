/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_0_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:29:13 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** fs_color() function recognizes a color to print into terminal.
**
** RETURN VALUE
** True if a color recognized, otherwise false.
**
** COMMENT
** Extra.
** Very simple implementation of color output.
** There are 9 possible states for the color:
** 0 - default;
** 1 - black;
** 2 - red;
** 3 - green;
** 4 - yellow;
** 5 - blue;
** 6 - purple;
** 7 - cyan;
** 8 - white.
*/

#include "../includes/ft_printf.h"

bool	fs_color(const char **fmt, t_fs *fs)
{
	const char	*tmp;

	tmp = *fmt;
	if (**fmt == '{' && *(*fmt + 1) >= '0' && *(*fmt + 1) <= '8' &&
	*(*fmt + 2) == '}')
	{
		fs->c = *(*fmt + 1) - '0';
		*fmt += 3;
	}
	return (tmp < *fmt);
}
