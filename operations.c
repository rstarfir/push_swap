/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:00:52 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/13 15:15:24 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_ilist **a, t_ilist **b)
{
	int		val;
	int		i;

	if (*b)
	{
		i = (*b)->index;
		val = stack_popfirst(b);
	}
	else
		return ;
	if (*a)
		stack_push(val, i, a);
	else
		*a = indexlstnew(val, i);
	
}

void		swap(t_ilist **s)
{
	int		a;
	int		ai;
	int		b;
	int		bi;
	
	if(!(*s) || !(*s)->next)
		return ;
	ai = (*s)->index;
	a = stack_popfirst(s);
	bi = (*s)->index;
	b = stack_popfirst(s);
	stack_push(a, ai, s);
	stack_push(b, bi, s);
}

void		rotate(t_ilist **s)
{
	int		val;
	int		i;

	if (!(*s) || (*s)->next)
		return ;
	i = (*s)->index;
	val = stack_popfirst(s);
	stack_pushback(val, i, s);
}

void		revrot(t_ilist **s)
{
	int		r;
	int		i;

	if (!(*s) || (*s)->next)
		return ;
	r = stack_poplast(*s, &i);
	stack_push(r, i, s);
}