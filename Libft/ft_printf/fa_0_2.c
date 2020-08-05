/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fa_0_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:47:24 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:47:28 by rstarfir         ###   ########.fr       */
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
** fa_str() and fa_char() functions set the buffer as a whole part of the
** number.
*/

#include "../includes/ft_printf.h"

void	fa_str(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[8] = fs->p >= 0 && fs->p < bf->i ? fs->p : bf->i;
	fa_nsp(fa, fs);
}

void	fa_char(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[8] = bf->i;
	fa_nsp(fa, fs);
}
