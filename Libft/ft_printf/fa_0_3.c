/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fa_0_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:46:45 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:46:49 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Here are functions that calculate format-array (fa[17]), which is used by
** res_string() function to output formatted string:
** fa[0] - number length;
** fa[1] - srting length;
** fa[2] - pad (' '... or '0'... before or after the number);
** fa[3] - sign;
** fa[4] - space;
** fa[5] - octal preffix;
** fa[6] - hex preffix;
** fa[7] - leading zeroes (whole part);
** fa[8] - sig digits (whole part);
** fa[9] - trailing zeroes (whole part);
** fa[10] - delimiter;
** fa[11] - leading zeroes (fractional part);
** fa[12] - sig digits (fractional part);
** fa[13] - trailing zeroes (fractional part);
** fa[14] - [EePp][+-] (exponent part) - equal to 'e'/'E' or 'p'/'P'
** fa[15] - leading zero (exponent part);
** fa[16] - exponent (exponent part);
**
** They take the array fa itself, the pointer to the buffer structure bf and
** the pointer to the format-string structure fs.
**
** RETURN VALUE
** None.
**
** COMMENT
** These functions are extra.
** fa_lint() function calculates fa-array for large integers (aka BigInt) which
** are implemented in the lint library: for bf->d >= 0 fa[0] is used as a temp
** var for the whole part size.
** fa_fpnk() function calculates fa-array for floating point numbers
** represented in free-format which means "unique" floats (Dragon4 algorithm).
*/

#include "../includes/ft_printf.h"

void	fa_lint(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || (fs->f & PL);
	fa[4] = !fa[3] && (fs->f & SP);
	fa[7] = (bf->i < fs->p) * (fs->p - bf->i);
	fa[8] = bf->i;
	fa_nsp(fa, fs);
}

void	fa_fpnk(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || (fs->f & PL);
	fa[4] = !fa[3] && (fs->f & SP);
	if (bf->d >= 0)
	{
		fa[0] = bf->d + 1;
		fa[8] = (fa[0] > bf->i) ? bf->i : fa[0];
		fa[9] = (fa[0] > bf->i) * (fa[0] - bf->i);
		fa[12] = (fa[0] < bf->i) * (bf->i - fa[0]);
	}
	else
	{
		fa[7] = 1;
		fa[11] = -bf->d - 1;
		fa[12] = bf->i;
	}
	fa[10] = fa[11] || fa[12] || fa[13] || (fs->f & SH);
	fa_nsp(fa, fs);
}
