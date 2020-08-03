/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fa_0_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:17:39 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:50 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Here are functions that calculate or take part in calculating format-array
** (fa[17]), which is used by res_string() function to output formatted string:
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
** RETURN VALUE
** None.
**
** COMMENT
** fa_clean() function sets all the elements of the array fa to zero.
** fa_nsp() function calculates number length, string length and size of the
** pad.
*/

#include "../includes/ft_printf.h"

void	fa_clean(int fa[17])
{
	int	i;

	i = -1;
	while (++i < 17)
		fa[i] = 0;
}

void	fa_nsp(int fa[17], t_fs *fs)
{
	fa[0] = fa[3] + fa[4] + fa[5] + fa[6] + fa[7] + fa[8] + fa[9] + fa[10] +
	fa[11] + fa[12] + fa[13] + (fa[14] ? 2 + fa[15] + fa[16] : 0);
	fa[2] = (fa[0] < fs->w) * (fs->w - fa[0]);
	fa[1] = fa[0] + fa[2];
}
