/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:28:22 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:03:48 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_push(t_data *s, t_stack *x)
{
	t_chunk	*new;

	if (!x->top || x->top->size)
	{
		if (!(new = (t_chunk*)malloc(sizeof(t_chunk))))
			ex_it(s, EXIT_FAILURE);
		new->next = x->top;
		x->top = new;
	}
}

void	chunk_pop(t_stack *x)
{
	t_chunk	*t;

	if ((t = x->top))
	{
		x->top = x->top->next;
		free(t);
	}
}

bool	chunk_a_sorted(t_data *s)
{
	t_lst	*t;
	int		i;

	t = s->a.first->next;
	i = 0;
	while (++i < s->a.top->size)
	{
		if (t->prev->n > t->n)
			return (false);
		t = t->next;
	}
	return (true);
}

bool	chunk_b_sorted(t_data *s)
{
	t_lst	*t;
	int		i;

	t = s->b.first->next;
	i = 0;
	while (++i < s->b.top->size)
	{
		if (t->prev->n < t->n)
			return (false);
		t = t->next;
	}
	return (true);
}
