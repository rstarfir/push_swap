/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:49:06 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:49:09 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** fs_init() function sets flags, type size and type to zero; width and
** presicion are negative by default.
** fs_read() function initiates scanning the string pointed at by fmt to fill
** format-string structure fs; it also takes ap to get width or precision in
** case of *.
**
** RETURN VALUE
** fs_read() returns true if type is recognized or false otherwise, which means
** an error in the format string.
*/

#include "../includes/ft_printf.h"
#include "../includes/fs.h"

static void	fs_init(t_fs *fs)
{
	fs->f = 0;
	fs->w = -1;
	fs->p = -1;
	fs->s = 0;
	fs->t = 0;
	fs->c = -1;
}

bool		fs_read(const char **fmt, t_fs *fs, va_list ap)
{
	bool	type;

	(*fmt)++;
	type = 0;
	fs_init(fs);
	if (fs_color(fmt, fs))
		return (true);
	while (**fmt && !type)
	{
		if (!fs_flags(fmt, fs) && !fs_width(fmt, fs, ap) && !fs_precision(fmt,
		fs, ap) && !fs_size(fmt, fs) && !(type = fs_type(fmt, fs)))
			break ;
	}
	return (type);
}
