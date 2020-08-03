/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:22:00 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:14:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

static void	lint_sub_pswap(t_lint **a, t_lint **b)
{
	t_lint	*c;

	c = *a;
	*a = *b;
	*b = c;
}

static int	lint_sub_check(t_lint *res, t_lint **a, t_lint **b)
{
	t_sign	cmp;

	if ((**a).sign * (**b).sign < 0)
	{
		(**b).sign = (**a).sign;
		lint_add(res, *a, *b);
		if (res != *b)
			(**b).sign *= -1;
		return (-1);
	}
	else
	{
		cmp = lint_cmp_abs(*a, *b);
		(*res).sign = cmp * (**a).sign >= 0 ? 1 : -1;
		if (cmp < 0)
			lint_sub_pswap(a, b);
		return (0);
	}
}

void		lint_sub(t_lint *res, t_lint *a, t_lint *b)
{
	t_limb	borrow;
	t_limb	tmp;
	t_count	i;

	if (lint_sub_check(res, &a, &b))
		return ;
	i = -1;
	borrow = 0;
	while (++i < (*a).size)
	{
		tmp = (*a).limb[i] - (*b).limb[i] - borrow;
		borrow = ((~(*a).limb[i] & (*b).limb[i]) | ((~(*a).limb[i] |
						(*b).limb[i]) & tmp)) >> (LSIZE - 1);
		(*res).limb[i] = tmp;
	}
	(*res).size = i;
	(*res).size = lint_normsize(res);
}

static int	lint_sub_1_check(t_lint *res, t_lint *a, t_limb b)
{
	if ((*a).sign < 0)
	{
		(*a).sign = 1;
		lint_add_1(res, a, b);
		(*res).sign = -1;
		(*a).sign = -1;
		return (-1);
	}
	else if ((*a).size == 1 && (*a).limb[0] < b)
	{
		(*res).sign = -1;
		(*res).size = 1;
		(*res).limb[0] = b - (*res).limb[0];
		return (1);
	}
	(*res).sign = 1;
	return (0);
}

void		lint_sub_1(t_lint *res, t_lint *a, t_limb b)
{
	t_limb	tmp;
	t_count	i;

	if (lint_sub_1_check(res, a, b))
		return ;
	i = -1;
	while (++i < (*a).size)
	{
		tmp = (*a).limb[i];
		(*res).limb[i] = tmp - b;
		b = (tmp < b);
	}
	(*res).size = i;
	(*res).size = lint_normsize(res);
}
