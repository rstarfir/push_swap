/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_string_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:37 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:50:40 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Here are functions used by fill_string() function to fill resulting string
** for an argument.
**
** COMMENT
** All of them are used when filling the resulting string whatever type of
** an argument is.
*/

#include "../includes/ft_printf.h"

void	fill_preffix(int fa[17], bool s, char t, char **dst)
{
	if (fa[3])
		*(*dst)++ = s ? '-' : '+';
	if (fa[4])
		*(*dst)++ = ' ';
	if (fa[5] || fa[6])
		*(*dst)++ = '0';
	if (fa[6])
		*(*dst)++ = t == 'x' || t == 'a' || t == 'p' ? 'x' : 'X';
}

void	fill_exponent(int fa[17], char *src, char **dst)
{
	if (!fa[14])
		return ;
	*(*dst)++ = fa[14];
	*(*dst)++ = *src++;
	if (fa[15])
		*(*dst)++ = '0';
	while (fa[16]-- > 0)
		*(*dst)++ = *(src + fa[16]);
}

void	fill_number(int fa[17], char *src, char **dst)
{
	while (fa[7]-- > 0)
		*(*dst)++ = '0';
	while (fa[8]-- > 0)
		*(*dst)++ = *src++;
	while (fa[9]-- > 0)
		*(*dst)++ = '0';
	if (fa[10])
		*(*dst)++ = '.';
	while (fa[11]-- > 0)
		*(*dst)++ = '0';
	while (fa[12]-- > 0)
		*(*dst)++ = *src++;
	while (fa[13]-- > 0)
		*(*dst)++ = '0';
	fill_exponent(fa, src, dst);
	**dst = '\0';
}

void	fill_pad(int size, char c, char **dst)
{
	while (size-- > 0)
		*(*dst)++ = c;
	**dst = '\0';
}

char	pad_char(t_bf *bf, t_fs *fs)
{
	if (fs->f & ZE)
	{
		if (is_int(fs->t))
			return (fs->p < 0 ? '0' : ' ');
		else if (is_fpn(fs->t))
			return (ft_isdigit(bf->b[0]) || !bf->i ? '0' : ' ');
		else
			return ('0');
	}
	else
		return (' ');
}
