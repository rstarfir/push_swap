/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:13:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:14:01 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *x)
{
	if (x->size > 1)
	{
		x->first->prev = x->first->next;
		x->first->next = x->first->next->next;
		if (x->first->next)
			x->first->next->prev = x->first;
		x->first->prev->prev = NULL;
		x->first->prev->next = x->first;
		x->first = x->first->prev;
		if (x->size == 2)
			x->last = x->first->next;
	}
}

void	shift_up(t_stack *x)
{
	if (x->size > 1)
	{
		x->first->prev = x->last;
		x->last->next = x->first;
		x->last = x->first;
		x->first = x->first->next;
		x->last->next = NULL;
		x->first->prev = NULL;
	}
}

void	shift_down(t_stack *x)
{
	if (x->size > 1)
	{
		x->last->next = x->first;
		x->first->prev = x->last;
		x->first = x->last;
		x->last = x->last->prev;
		x->first->prev = NULL;
		x->last->next = NULL;
	}
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->size == 1)
	{
		src->first->next = dst->first;
		if (dst->first)
			dst->first->prev = src->first;
		else
			dst->last = src->first;
		dst->first = src->first;
		src->first = NULL;
		src->last = NULL;
	}
	else if (src->size > 1)
	{
		src->first = src->first->next;
		src->first->prev->next = dst->first;
		dst->first = src->first->prev;
		if (dst->first->next)
			dst->first->next->prev = dst->first;
		else
			dst->last = dst->first;
		src->first->prev = NULL;
	}
}
