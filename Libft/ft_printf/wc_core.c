/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:56 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:50:59 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** wc_get() function transforms code point c of type wchar_t into UTF-8
** representation saving it in an unsigned integer *r of 32 bytes size and the
** function returns a positive number of bytes needed for encoding (that saved
** in *r) or zero in case of c exceeding Unicode.
**
** wcs_size() function parses an input string pointed at by src and returns the
** number of bytes needed to convert wchar string into char one or -1 in case
** of an *src exceeding Unicode.
**
** wcs_get() function converts wchar string pointed at by src into char one
** pointed at by *dst with memory allocation (malloc(3)) and returns the length
** of the result string or -1 in case of an error.
**
** COMMENT
** 1) The functions work with little-endian systems.
** 2) *dst is not a NULL terminated string (it is not needed for printf
** algorithm implemented).
*/

#include "../includes/ft_printf.h"

uint8_t		wc_get(wchar_t c, uint32_t *r)
{
	*r = 0;
	if (c < 0x7F)
	{
		*r = c;
		return (1);
	}
	else if (c < 0x7FF)
	{
		*r |= 0x80C0 | ((c & 0x3F) << 8) | ((c >> 6) & 0x3F);
		return (2);
	}
	else if (c < 0xFFFF)
	{
		*r |= 0x8080E0 | ((c & 0x3F) << 16) | (((c >> 6) & 0x3F) << 8) |
		((c >> 12) & 0x3F);
		return (3);
	}
	else if (c < 0x10FFFF)
	{
		*r |= 0x808080F0 | ((c & 0x3F) << 24) | (((c >> 6) & 0x3F) << 16) |
		(((c >> 12) & 0x3F) << 8) | ((c >> 18) & 0x3F);
		return (4);
	}
	else
		return (0);
}

static int	wcs_size(wchar_t *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		if (*src < 0x7F)
			i++;
		else if (*src < 0x7FF)
			i += 2;
		else if (*src < 0xFFFF)
			i += 3;
		else if (*src < 0x10FFFF)
			i += 4;
		else
			return (-1);
		src++;
	}
	return (i);
}

int			wcs_get(wchar_t *src, char **dst)
{
	uint8_t		n;
	int			i;
	uint32_t	r;
	char		*dst_2;

	if ((i = wcs_size(src)) < 0)
		return (-1);
	if (!(*dst = (char*)malloc(sizeof(char) * i)))
		return (-1);
	dst_2 = *dst;
	while (*src)
	{
		n = wc_get(*src++, &r);
		*((int*)dst_2) = r;
		dst_2 += n;
	}
	return (i);
}
