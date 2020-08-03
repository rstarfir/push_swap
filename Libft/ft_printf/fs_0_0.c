/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_0_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:16 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** These functions get the format for an argument by scanning srting pointed at
** by fmt and filling format-string structure fs.
**
** RETURN VALUE
** True if a parameter is recognized, otherwise false.
*/

#include "../includes/ft_printf.h"

bool	fs_flags(const char **fmt, t_fs *fs)
{
	const char	*tmp;

	tmp = *fmt;
	while (1)
	{
		if (**fmt == '#')
			fs->f |= SH;
		else if (**fmt == '+')
			fs->f |= PL;
		else if (**fmt == '-')
			fs->f |= MI;
		else if (**fmt == ' ')
			fs->f |= SP;
		else if (**fmt == '0')
			fs->f |= ZE;
		else
			break ;
		(*fmt)++;
	}
	return (tmp < *fmt);
}

bool	fs_width(const char **fmt, t_fs *fs, va_list ap)
{
	int			w;
	const char	*tmp;

	tmp = *fmt;
	while (1)
		if (**fmt == '*' && (*fmt)++)
		{
			if ((w = va_arg(ap, int)) < 0)
			{
				fs->f |= MI;
				fs->w = -w;
			}
			else
				fs->w = w;
		}
		else if (ft_isdigit(**fmt))
		{
			fs->w = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		else
			break ;
	return (tmp < *fmt);
}

bool	fs_precision(const char **fmt, t_fs *fs, va_list ap)
{
	const char	*tmp;

	tmp = *fmt;
	if (**fmt == '.' && (*fmt)++)
	{
		fs->p = 0;
		while (1)
			if (**fmt == '*' && (*fmt)++)
				fs->p = va_arg(ap, int);
			else if (ft_isdigit(**fmt))
			{
				fs->p = ft_atoi(*fmt);
				while (ft_isdigit(**fmt))
					(*fmt)++;
			}
			else
				break ;
	}
	return (tmp < *fmt);
}

bool	fs_size(const char **fmt, t_fs *fs)
{
	char	c;

	c = **fmt;
	if ((c == 'l' || c == 'h') && c == *(*fmt + 1))
	{
		fs->s = c + 128;
		*fmt += 2;
		return (true);
	}
	else if (c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L' ||
	c == 'h')
	{
		fs->s = c;
		*fmt += 1;
		return (true);
	}
	return (false);
}

bool	fs_type(const char **fmt, t_fs *fs)
{
	char	c;

	c = **fmt;
	if (is_int(c) || is_fpn(c) || is_str(c) || is_char(c) || c == 'n' ||
	c == 'v' || c == '%')
	{
		*fmt += 1;
		fs->t = c;
		return (true);
	}
	else
		return (false);
}
