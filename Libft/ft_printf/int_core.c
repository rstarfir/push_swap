/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:34 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:13:14 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** int_get() function converts a number n of size intmax_t to a srting in base
** up to 16 according to the format-srting pointed at by fs and fill the buffer
** *bf.
** casting() function takes a number n of size intmax_t and casts it according
** to type-size c.
**
** COMMENT
** bf->d is taken as an index of the beginning of the buffer.
*/

#include "../includes/int.h"

static uintmax_t	casting(intmax_t n, unsigned char c)
{
	if (!c)
		return ((uint32_t)n);
	else if (c == 'h')
		return ((unsigned short)n);
	else if (c == 'h' + 128)
		return ((unsigned char)n);
	else if (c == 'l')
		return ((unsigned long)n);
	else if (c == 'l' + 128)
		return ((unsigned long long)n);
	else
		return ((uintmax_t)n);
}

void				int_get(intmax_t n, uint8_t base, t_fs *fs, t_bf *bf)
{
	uintmax_t	r;
	char		*range;

	bf->d = 64;
	range = fs->t == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (fs->t == 'd' || fs->t == 'i')
	{
		r = n < 0 ? -n : n;
		bf->s = n < 0 ? 1 : 0;
	}
	else
	{
		r = casting(n, fs->s);
		bf->s = 0;
	}
	while (r)
	{
		bf->b[--bf->d] = range[r % base];
		r /= base;
	}
	bf->i = 64 - bf->d;
}
