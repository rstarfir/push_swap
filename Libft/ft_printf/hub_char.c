/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:49:34 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:49:37 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_char() function is called by printf_hub() in case of char-type.
**
** RETURN VALUE
** The function returns the length of the resulting string or -1 in case of an
** error.
*/

#include "../includes/ft_printf.h"
#include "../includes/wc.h"

static int	char_char(char **str, unsigned char c, t_fs *fs)
{
	t_bf	bf;
	int		i;

	if (!(bf.b = (char*)malloc(sizeof(char))))
		return (-1);
	*bf.b = c;
	bf.i = 1;
	i = res_string(str, &bf, fs, fa_char);
	free(bf.b);
	return (i);
}

static int	char_wchar(char **str, wchar_t c, t_fs *fs)
{
	t_bf		bf;
	int			i;
	uint32_t	r;

	if (!(bf.i = wc_get(c, &r)))
		return (-1);
	if (!(bf.b = (char*)malloc(sizeof(char) * bf.i)))
		return (-1);
	*(int*)bf.b = r;
	i = res_string(str, &bf, fs, fa_char);
	free(bf.b);
	return (i);
}

int			hub_char(char **str, va_list ap, t_fs *fs)
{
	if (fs->t == 'C')
		fs->s = 'l';
	if (fs->t == '%')
		return (char_char(str, '%', fs));
	else if (fs->s == 'l')
		return (char_wchar(str, va_arg(ap, wchar_t), fs));
	else
		return (char_char(str, (unsigned char)va_arg(ap, int), fs));
}
