/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:00:52 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/12 16:36:54 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack **a, t_stack **b)
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

void		swap(t_stack **s)
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

void		rotate(t_stack **s)
{
	int		val;
	int		i;

	if (!(*s) || (*s)->next)
		return ;
	i = (*s)->index;
	val = stack_popfirst(s);
	stack_pushback(val, i, s);
}

void		revrot(t_stack **s)
{
	int		r;
	int		i;

	if (!(*s) || (*s)->next)
		return ;
	r = stack_poplast(*s, &i);
	stack_push(r, i, s);
}