/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:21:47 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:14:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

void	lint_lshift_size(t_lint *res, t_lint *src, t_size sh)
{
	t_count	i;

	if (!(*src).size)
		return ;
	i = (*src).size;
	while (--i >= 0)
		(*res).limb[i + sh] = (*src).limb[i];
	while (++i < sh)
		(*res).limb[i] = 0;
	(*res).size = (*src).size + sh;
	(*res).sign = (*src).sign;
}

void	lint_lshift(t_lint *res, t_lint *src, t_dcount sh)
{
	t_limb	left_prev;
	t_count	small;
	t_count	i;
	t_count	j;

	left_prev = 0;
	small = sh % LSIZE;
	if (!small)
	{
		lint_lshift_size(res, src, sh / LSIZE);
		return ;
	}
	i = (*src).size;
	(*res).size = i + sh / LSIZE + (small ? 1 : 0);
	j = (*res).size;
	while (--i >= 0)
	{
		(*res).limb[--j] = (*src).limb[i] >> (LSIZE - small) | left_prev;
		left_prev = (*src).limb[i] << small;
	}
	(*res).limb[--j] = left_prev;
	while (--j >= 0)
		(*res).limb[j] = 0;
	(*res).size = lint_normsize(res);
	(*res).sign = (*src).sign;
}

void	lint_rshift_size(t_lint *res, t_lint *src, t_size sh)
{
	t_count	i;

	if (!(*src).size)
		return ;
	i = -1;
	while (++i < (*src).size - sh)
		(*res).limb[i] = (*src).limb[i + sh];
	(*res).size = (*src).size - sh;
	(*res).sign = (*src).sign;
}

void	lint_rshift(t_lint *res, t_lint *src, t_dcount sh)
{
	t_limb	right_prev;
	t_count	small;
	t_count	i;
	t_count	j;

	small = sh % LSIZE;
	if (!small)
	{
		lint_rshift_size(res, src, sh / LSIZE);
		return ;
	}
	i = -1;
	j = i + sh / LSIZE + (small ? 1 : 0);
	right_prev = (*src).limb[j] >> small;
	while (++j < (*src).size)
	{
		(*res).limb[++i] = (*src).limb[j] << (LSIZE - small) | right_prev;
		right_prev = (*src).limb[j] >> small;
	}
	(*res).limb[++i] = right_prev;
	(*res).size = i + 1;
	(*res).size = lint_normsize(res);
	(*res).sign = (*src).sign;
}
