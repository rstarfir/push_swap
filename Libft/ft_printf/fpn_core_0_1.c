/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_0_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:47:48 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:47:51 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Dragon4 algorithm (1).
**
** COMMENT
** fpn_correcting() function adjusts the decimal exponent by 1 if needed.
** fpn_rounding() is used to to round the result according to IEEE754.
** fpn_free() and fpn_fixed() are used for generating string in "free" and
** "fixed" format correspondingly.
** fpn_dragon4() is just a hub.
**
** x - fpn separated on sign, mantissa, exponent;
** rs[0] and rs[1] are the numerator and denominator correspondingly.
** margin[0] and margin[1] are the lower and the upper margin correspondingly.
*/

#include "../includes/fpn.h"

static void	fpn_correcting(t_fpn *x, t_lint rs[2], t_lint margin[2])
{
	if (lint_cmp_abs(&rs[0], &rs[1]) >= 0)
		x->dexp++;
	else
	{
		lint_mul_1(&margin[0], &margin[0], 10);
		lint_mul_1(&margin[1], &margin[1], 10);
		lint_mul_1(&rs[0], &rs[0], 10);
	}
}

static void	fpn_rounding(int cmp[2], t_lint rs[2], t_bf *bf)
{
	int	round_up;

	round_up = cmp[1];
	if (cmp[0] == cmp[1])
	{
		lint_mul_1(&rs[0], &rs[0], 2);
		if (!(round_up = lint_cmp_abs(&rs[0], &rs[1])))
			round_up = (bf->b[bf->i - 1] - '0') & 1;
	}
	if (round_up > 0)
	{
		bf->b[bf->i - 1]++;
		while (bf->i > 1 && bf->b[bf->i - 1] > '9')
		{
			bf->b[--bf->i - 1]++;
		}
		if (bf->i == 1 && bf->b[bf->i - 1] > '9')
		{
			bf->d++;
			bf->b[0] = '1';
		}
	}
	bf->b[bf->i] = '\0';
}

static void	fpn_free(t_fpn *x, t_lint rs[2], t_lint margin[2], t_bf *bf)
{
	int		cmp[2];
	t_lint	tmp;

	while (1)
	{
		x->dexp--;
		rs[0] = lint_div(&tmp, rs[0], rs[1]);
		bf->b[bf->i++] = tmp.limb[0] + '0';
		lint_mul_1(&margin[0], &margin[0], 10);
		lint_mul_1(&margin[1], &margin[1], 10);
		lint_add(&tmp, &rs[0], &margin[1]);
		cmp[0] = lint_cmp_abs(&rs[0], &margin[0]) < 0;
		cmp[1] = lint_cmp_abs(&tmp, &rs[1]) > 0;
		if (cmp[0] || cmp[1])
			break ;
		lint_mul_1(&rs[0], &rs[0], 10);
	}
	fpn_rounding(cmp, rs, bf);
}

static void	fpn_fixed(t_fpn *x, t_lint rs[2], t_bf *bf, int dexp_last)
{
	int		cmp[2];
	t_lint	tmp;

	cmp[0] = 0;
	cmp[1] = 0;
	while (1)
	{
		x->dexp--;
		rs[0] = lint_div(&tmp, rs[0], rs[1]);
		bf->b[bf->i++] = tmp.limb[0] + '0';
		if (!rs[0].size || x->dexp <= dexp_last)
			break ;
		lint_mul_1(&rs[0], &rs[0], 10);
	}
	fpn_rounding(cmp, rs, bf);
}

int			fpn_dragon4(t_fpn *x, t_bf *bf, t_dragon_mode mode, int p)
{
	t_lint	rs[2];
	t_lint	margin[2];
	int64_t	dexp_last;

	if (!x->mant)
		return (-1);
	dexp_last = 0;
	fpn_dragon4_init(x, rs, margin);
	fpn_correcting(x, rs, margin);
	bf->d = x->dexp - 1;
	bf->s = x->sign;
	if (mode == free_uniqe)
		fpn_free(x, rs, margin, bf);
	else
	{
		if (mode == fixed_absolute)
			dexp_last = x->dexp - p;
		else if (mode == fixed_relative)
			dexp_last = -p;
		fpn_fixed(x, rs, bf, dexp_last);
	}
	return (0);
}
