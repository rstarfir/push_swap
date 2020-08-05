/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:53:42 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:53:46 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

t_limb			lint_div_1(t_lint *q, t_lint *a, t_limb b)
{
	t_dlimb	u_;
	t_limb	r;
	t_count	i;

	i = (*a).size;
	r = 0;
	while (--i >= 0)
	{
		u_ = ((t_dlimb)r << LSIZE | (*a).limb[i]);
		(*q).limb[i] = (t_limb)(u_ / b);
		r = u_ - (*q).limb[i] * b;
	}
	(*q).size = (*a).size;
	(*q).size = lint_normsize(q);
	return (r);
}

static t_count	lint_div_norm(t_lint *a, t_lint *d)
{
	t_count	sh;

	sh = 0;
	while (sh < LSIZE && !(((*d).limb[(*d).size - 1] << sh) & HBIT))
		sh++;
	if (sh)
	{
		lint_lshift(a, a, sh);
		lint_lshift(d, d, sh);
	}
	return (sh);
}

t_count			lint_div_check(t_lint *q, t_lint *a, t_lint *b, t_count *j)
{
	t_sign	cmp;
	t_count	sh;

	cmp = lint_cmp_abs(a, b);
	if (cmp < 0)
		lint_assign(q, 0, 1);
	else if (cmp == 0)
	{
		lint_assign(q, 1, (*a).sign * (*b).sign);
		lint_assign(a, 0, 1);
	}
	else
	{
		sh = lint_div_norm(a, b);
		(*q).sign = (*a).sign * (*b).sign;
		(*q).size = (*a).size - (*b).size;
		*j = (*q).size;
		return (sh);
	}
	return (-1);
}

t_lint			lint_div(t_lint *q, t_lint a, t_lint b)
{
	t_count		j;
	t_count		sh;
	t_lint		btmp;
	t_lint		m1;
	t_dlimb		x_;

	if ((sh = lint_div_check(q, &a, &b, &j)) < 0)
		return (a);
	lint_lshift_size(&btmp, &b, j);
	if (lint_cmp_abs(&a, &btmp) >= 0 && ((*q).limb[(*q).size++] = 1))
		lint_sub(&a, &a, &btmp);
	while (--j >= 0)
	{
		x_ = (((t_dlimb)a.limb[b.size + j] << LSIZE) | a.limb[b.size + j - 1])
			/ b.limb[b.size - 1];
		(*q).limb[j] = x_ < LMAX ? x_ : LMAX;
		lint_lshift_size(&btmp, &b, j);
		lint_mul_1(&m1, &btmp, (*q).limb[j]);
		lint_sub(&a, &a, &m1);
		while (a.sign < 0 && (*q).limb[j]--)
			lint_add(&a, &a, &btmp);
	}
	lint_rshift(&a, &a, sh);
	return (a);
}
