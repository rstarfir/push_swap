/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:08:57 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:14:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

void	lint_clear(t_lint *dst)
{
	t_count	i;

	i = -1;
	(*dst).sign = 1;
	(*dst).size = 0;
	while (++i < SIZE)
		(*dst).limb[i] = 0;
}

void	lint_assign(t_lint *dst, t_dlimb src, t_sign sign)
{
	(*dst).limb[0] = (t_limb)src;
	(*dst).limb[1] = (t_limb)(src >> LSIZE);
	(*dst).sign = sign < 0 ? -1 : 1;
	(*dst).size = 2;
	(*dst).size = lint_normsize(dst);
}

t_size	lint_normsize(t_lint *src)
{
	t_count	i;

	i = (*src).size;
	while (--i >= 0 && !(*src).limb[i])
		;
	return (i + 1);
}

void	lint_copy(t_lint *dst, t_lint *src)
{
	t_count	i;

	i = -1;
	while (++i < (*src).size)
		(*dst).limb[i] = (*src).limb[i];
	(*dst).size = i;
	(*dst).sign = (*src).sign;
}
