/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fa_0_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:47:15 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:47:19 by rstarfir         ###   ########.fr       */
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
** fa_int() - integers: hexadecimal, octal, decimal, binary (extra) and also
** pointer address.
** fa_fpnp() - floating point number - positional notation:
** 1) for bf->d >= 0 fa[0] is used as a temp var for the whole part size;
** 2) for bf->d < 0 fa[0] is used as a tmp var for leading zeroes (fractional).
** fa_fpns() - floating point number - scientific notation.
** fa_fpng() - floating point number - positional or scientific notation
** without trailing zeroes depending on decimal exponent of the number and
** precision.
** fa_fpnni() function is used to print nan/inf (float).
*/

#include "../includes/ft_printf.h"

void	fa_int(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || ((fs->f & PL) && (fs->t == 'd' || fs->t == 'i'));
	fa[4] = !fa[3] && (fs->f & SP) && (fs->t == 'd' || fs->t == 'i');
	fa[6] = (((fs->f & SH) && (fs->t == 'x' || fs->t == 'X') && bf->i) ||
	fs->t == 'p') << 1;
	fa[7] = fs->p < 0 ? 0 : (bf->i < fs->p) * (fs->p - bf->i);
	fa[5] = !fa[7] && (fs->f & SH) && (fs->t == 'o');
	fa[8] = bf->i;
	fa[9] = !fa[5] && !fa[7] && !fa[8] && fs->p;
	fa_nsp(fa, fs);
}

void	fa_fpnp(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || (fs->f & PL);
	fa[4] = !fa[3] && (fs->f & SP);
	if (bf->d >= 0)
	{
		fa[0] = bf->d + 1;
		fa[8] = (fa[0] > bf->i) ? bf->i : fa[0];
		fa[9] = (fa[0] > bf->i) * (fa[0] - bf->i);
		fa[12] = (fa[0] < bf->i) * (bf->i - fa[0]);
		fa[13] = fs->p - fa[12];
	}
	else
	{
		fa[0] = -bf->d - 1;
		fa[7] = 1;
		fa[11] = fa[0] < fs->p ? fa[0] : fs->p;
		fa[12] = (fa[11] < fs->p) * bf->i;
		fa[13] = (fa[11] + fa[12] < fs->p) * (fs->p - fa[11] - fa[12]);
	}
	fa[10] = fa[11] || fa[12] || fa[13] || (fs->f & SH);
	fa_nsp(fa, fs);
}

void	fa_fpns(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || (fs->f & PL);
	fa[4] = !fa[3] && (fs->f & SP);
	fa[6] = (fs->t == 'a' || fs->t == 'A') << 1;
	fa[8] = bf->i ? 1 : 0;
	fa[9] = !fa[8];
	fa[12] = (bf->i > 1) * (bf->i - 1);
	fa[13] = (fs->p > fa[12]) * (fs->p - fa[12]);
	fa[10] = fa[11] || fa[12] || fa[13] || (fs->f & SH);
	if (fs->t == 'a' || fs->t == 'A')
		fa[14] = fs->t + 15;
	else
		fa[14] = ft_islower(fs->t) ? 'e' : 'E';
	bf->b[bf->i++] = bf->d < 0 ? '-' : '+';
	bf->d < 0 ? bf->d = -bf->d : 0;
	fa[16] = 1;
	bf->b[bf->i++] = bf->d % 10 + '0';
	while (bf->d /= 10)
	{
		fa[16]++;
		bf->b[bf->i++] = bf->d % 10 + '0';
	}
	fa[15] = !(fs->t == 'a' || fs->t == 'A') * (fa[16] < 2);
	fa_nsp(fa, fs);
}

void	fa_fpnni(int fa[17], t_bf *bf, t_fs *fs)
{
	fa[3] = bf->s || (fs->f & PL);
	fa[4] = !fa[3] && (fs->f & SP);
	fa[8] = bf->i;
	fa_nsp(fa, fs);
}

void	fa_fpng(int fa[17], t_bf *bf, t_fs *fs)
{
	if (fs->p > bf->d && bf->d >= -4)
		fa_fpnp(fa, bf, fs);
	else
		fa_fpns(fa, bf, fs);
	fa[13] = (fs->f & SH) * (fs->p - bf->i);
	fa[10] = fa[11] || fa[12] || fa[13] || (fs->f & SH);
	fa_nsp(fa, fs);
}
