/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:10:09 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:10:23 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				op_init(t_data *s)
{
	s->op[SA] = sa;
	s->op[RA] = ra;
	s->op[RRA] = rra;
	s->op[SB] = sb;
	s->op[RB] = rb;
	s->op[RRB] = rrb;
	s->op[SS] = ss;
	s->op[RR] = rr;
	s->op[RRR] = rrr;
	s->op[PA] = pa;
	s->op[PB] = pb;
}

void				top_init(t_data *s)
{
	chunk_push(s, &s->a);
	chunk_push(s, &s->b);
	s->a.top->size = s->a.size;
	s->a.top->ipivot = s->a.top->size / 2;
	s->a.top->pivot = s->array[s->a.top->ipivot]->n;
	s->b.top->size = 0;
}

static void			array_sort(t_lst **array, int size)
{
	int		i;
	int		j;
	int		sorted;
	t_lst	*t;

	i = -1;
	sorted = 0;
	while (++i < size && !sorted)
	{
		j = 0;
		sorted = 1;
		while (++j < size - i)
			if (array[j]->n < array[j - 1]->n)
			{
				t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
				sorted = 0;
			}
	}
}

void				array_init(t_data *s)
{
	t_lst	*t;
	int		i;

	i = -1;
	t = s->a.first;
	while (t)
	{
		s->array[++i] = t;
		t = t->next;
	}
	array_sort(s->array, s->a.size);
}
