/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_0_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:47:40 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:47:43 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** There are functions being used to manage buffer during floating point numbers
** calculations and retrieve components of a float.
**
** COMMENT
** buff_clean() function sets the structure bf to zero.
** fpn_buff_check() function is used to cut trailing zeroes (diminishing
** decimal exponent of the number) which could be obtained after fpn
** calculations.
** fpn_ceil() rounds up decimal exponent (only!).
** fpn_decompose() is used to separate fpn into sign, exponent and mantissa.
*/

#include "../includes/fpn.h"

static const double		g_log10_2 = 0.30102999566398119801746702250966;

void			fpn_buff_clean(t_bf *bf)
{
	bf->i = 0;
	bf->s = 0;
	bf->d = 0;
}

void			fpn_buff_check(t_bf *bf)
{
	while (bf->i > 0 && bf->b[bf->i - 1] == '0')
		bf->i--;
}

static int16_t	fpn_ceil(double d)
{
	int16_t	x;

	x = d;
	return (x < d ? x + 1 : x);
}

int8_t			fpn_decompose(long double value, t_fpn *x)
{
	__uint128_t	*tmp;

	tmp = (__uint128_t*)&value;
	x->sign = (int8_t)((*tmp >> 79) & 1);
	x->exp = (int16_t)((*tmp >> 64) & 0x7FFF);
	x->mant = (uint64_t)(*tmp);
	if (!x->exp && !x->mant)
		return (0);
	else if (x->exp == 0x7FFF)
		return (1);
	else if (x->exp == 0)
	{
		x->dexp = fpn_ceil((ft_log2(x->mant) + x->exp - 16383 - 64 + 1) *
		g_log10_2 - 0.69);
		x->exp = 1 - 16383 - 64 + 1;
	}
	else
	{
		x->dexp = fpn_ceil((64 + x->exp - 16383 - 64 + 1) * g_log10_2 - 0.69);
		x->exp = x->exp - 16383 - 64 + 1;
	}
	return (0);
}
