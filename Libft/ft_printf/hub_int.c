/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:36 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:13:14 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_int() function is called by printf_hub() in case of int-type.
**
** RETURN VALUE
** The function returns the length of the resulting string or -1 in case of an
** error.
*/

#include "../includes/int.h"

static int	int_base(char c)
{
	if (c == 'o')
		return (8);
	else if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'b')
		return (2);
	else
		return (10);
}

static int	int_int(char **str, intmax_t n, t_fs *fs)
{
	t_bf	bf;
	int		i;

	if (!(bf.b = buff_get(fs)))
		return (-1);
	int_get(n, int_base(fs->t), fs, &bf);
	i = res_string(str, &bf, fs, fa_int);
	free(bf.b);
	return (i);
}

static void	int_pre(t_fs *fs)
{
	if (fs->t == 'D' || fs->t == 'O' || fs->t == 'U')
	{
		fs->s = 'l';
		fs->t += 32;
	}
	else if (fs->t == 'p')
	{
		fs->s = 'l';
		fs->f |= SH;
	}
	else if (fs->s == 'L')
		fs->s = 'l' + 128;
	else if (fs->s == 'z' || fs->s == 't')
		fs->s = 'j';
}

int			hub_int(char **str, va_list ap, t_fs *fs)
{
	int_pre(fs);
	if (!fs->s)
		return (int_int(str, va_arg(ap, int), fs));
	else if (fs->s == 'h' + 128)
		return (int_int(str, (char)va_arg(ap, int), fs));
	else if (fs->s == 'h')
		return (int_int(str, (short)va_arg(ap, int), fs));
	else if (fs->s == 'l')
		return (int_int(str, va_arg(ap, long int), fs));
	else if (fs->s == 'l' + 128)
		return (int_int(str, va_arg(ap, long long int), fs));
	else
		return (int_int(str, va_arg(ap, intmax_t), fs));
}
