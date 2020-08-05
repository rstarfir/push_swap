/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:52:43 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:52:49 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

static int	lint_add_check(t_lint *res, t_lint *a, t_lint *b)
{
	if ((*a).sign * (*b).sign < 0)
	{
		(*b).sign = (*a).sign;
		lint_sub(res, a, b);
		if (res != b)
			(*b).sign *= -1;
		return (-1);
	}
	else
	{
		(*res).sign = (*a).sign;
		return (0);
	}
}

static void	lint_add_bs(t_lint *res, t_lint *bigger, t_lint *smaller)
{
	t_limb	tmp;
	t_limb	carry;
	t_count	i;

	i = -1;
	carry = 0;
	(*res).size = (*bigger).size;
	while (++i < (*smaller).size)
	{
		tmp = (*bigger).limb[i] + (*smaller).limb[i] + carry;
		carry = (((*bigger).limb[i] & (*smaller).limb[i]) | (((*bigger).limb[i]\
						| (*smaller).limb[i]) & (~tmp))) >> (LSIZE - 1);
		(*res).limb[i] = tmp;
	}
	while (i < (*bigger).size)
	{
		tmp = (*bigger).limb[i] + carry;
		carry = (tmp < carry);
		(*res).limb[i++] = tmp;
	}
	carry ? (*res).limb[(*res).size++] = carry : 0;
}

void		lint_add(t_lint *res, t_lint *a, t_lint *b)
{
	if (lint_add_check(res, a, b))
		return ;
	if ((*a).size > (*b).size)
		lint_add_bs(res, a, b);
	else
		lint_add_bs(res, b, a);
}

static int	lint_add_1_check(t_lint *res, t_lint *a, t_limb b)
{
	if ((*a).sign < 0)
	{
		(*a).sign = 1;
		lint_sub_1(res, a, b);
		(*res).sign *= -1;
		if (res != a)
			(*a).sign = -1;
		return (-1);
	}
	else
	{
		(*res).sign = 1;
		return (0);
	}
}

void		lint_add_1(t_lint *res, t_lint *a, t_limb b)
{
	t_count	i;

	if (lint_add_1_check(res, a, b))
		return ;
	i = -1;
	(*res).size = (*a).size;
	while (++i < (*a).size)
	{
		(*res).limb[i] = (*a).limb[i] + b;
		b = ((*res).limb[i] < b);
	}
	b ? (*res).limb[(*res).size++] = b : 0;
}
