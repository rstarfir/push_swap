/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:53:28 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:53:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

t_sign	lint_cmp_es(t_lint *a, t_lint *b)
{
	t_count	i;

	i = (*a).size;
	while (--i >= 0 && (*a).limb[i] == (*b).limb[i])
		;
	if (i < 0)
		return (0);
	else
		return ((*a).limb[i] < (*b).limb[i] ? -1 : 1);
}

t_sign	lint_cmp(t_lint *a, t_lint *b)
{
	t_size	ss_a;
	t_size	ss_b;

	ss_a = (*a).sign * (*a).size;
	ss_b = (*b).sign * (*b).size;
	if (ss_a > ss_b)
		return (1);
	else if (ss_a < ss_b)
		return (-1);
	else
		return (ss_a < 0 ? -lint_cmp_es(a, b) : lint_cmp_es(a, b));
}

t_sign	lint_cmp_abs(t_lint *a, t_lint *b)
{
	if ((*a).size > (*b).size)
		return (1);
	else if ((*a).size < (*b).size)
		return (-1);
	else
		return (lint_cmp_es(a, b));
}
