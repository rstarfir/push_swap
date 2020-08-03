/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:13:13 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_color() function is called by printf_hub() in case of printing color.
**
** RETURN VALUE
** The function returns the length of the color code or -1 in case of an
** error.
*/

#include "../includes/ft_printf.h"

int		hub_color(char **str, t_fs *fs)
{
	if (fs->c == 0)
		*str = ft_strdup("\033[m");
	else if (fs->c == 1)
		*str = ft_strdup("\033[0;90m");
	else if (fs->c == 2)
		*str = ft_strdup("\033[0;31m");
	else if (fs->c == 3)
		*str = ft_strdup("\033[0;32m");
	else if (fs->c == 4)
		*str = ft_strdup("\033[0;33m");
	else if (fs->c == 5)
		*str = ft_strdup("\033[0;34m");
	else if (fs->c == 6)
		*str = ft_strdup("\033[0;35m");
	else if (fs->c == 7)
		*str = ft_strdup("\033[0;36m");
	else if (fs->c == 8)
		*str = ft_strdup("\033[0;37m");
	return (*str ? (int)ft_strlen(*str) : -1);
}
