/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_0_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:48:07 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:48:10 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Dragon4 algorithm (2).
**
** COMMENT
** The functions below initialize rs and margin.
*/

#include "../includes/fpn.h"

static void	fpn_init_dexp_greater(t_fpn *x, t_lint rs[2], t_lint margin[2])
{
	t_lint	tmp;

	lint_assign(&tmp, x->mant, 1);
	if (x->mant == 0x8000000000000000UL)
	{
		rs[0] = lint_2pow(x->exp + 2);
		lint_assign(&rs[1], 4, 1);
		margin[1] = lint_2pow(x->exp + 1);
	}
	else
	{
		rs[0] = lint_2pow(x->exp + 1);
		lint_assign(&rs[1], 2, 1);
		margin[1] = lint_2pow(x->exp);
	}
	lint_mul(&rs[0], &rs[0], &tmp);
	margin[0] = lint_2pow(x->exp);
}

static void	fpn_init_dexp_less(t_fpn *x, t_lint rs[2], t_lint margin[2])
{
	t_lint	tmp;

	if (x->mant == 0x8000000000000000UL && x->exp > -16445)
	{
		rs[0] = lint_2pow(63 + 2);
		rs[1] = lint_2pow(-x->exp + 2);
		lint_assign(&margin[1], 2, 1);
	}
	else
	{
		lint_assign(&tmp, x->mant, 1);
		lint_lshift(&rs[0], &tmp, 1);
		rs[1] = lint_2pow(-x->exp + 1);
		lint_assign(&margin[1], 1, 1);
	}
	lint_assign(&margin[0], 1, 1);
}

void		fpn_dragon4_init(t_fpn *x, t_lint rs[2], t_lint margin[2])
{
	t_lint		tmp;

	if (x->exp >= 0)
		fpn_init_dexp_greater(x, rs, margin);
	else
		fpn_init_dexp_less(x, rs, margin);
	if (x->dexp >= 0)
	{
		tmp = lint_10pow(x->dexp);
		lint_mul(&rs[1], &rs[1], &tmp);
	}
	else
	{
		tmp = lint_10pow(-x->dexp);
		lint_mul(&rs[0], &rs[0], &tmp);
		lint_mul(&margin[0], &margin[0], &tmp);
		lint_mul(&margin[1], &margin[1], &tmp);
	}
}
