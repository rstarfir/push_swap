/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_a_partition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:57:15 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:13:12 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		roq_count(t_lst *t, t_n pivot, int size)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		if (t->n < pivot)
			k++;
		t = t->next;
	}
	return (k);
}

static void		a_par_rest(t_data *s, int j)
{
	int		k;

	chunk_push(s, &s->b);
	a_to_b(s->b.top, s->a.top, s->array);
	k = roq_count(s->a.first, s->a.top->pivot, s->a.top->size - j);
	while (k)
		if (s->a.first->n < s->a.top->pivot)
			k -= pb(s);
		else
			j += ra(s);
	while (j)
	{
		j -= rra(s);
		if (s->a.first->n < s->a.top->pivot)
			(void)pb(s);
	}
	a_to_a(s->a.top, s->b.top, s->array);
}

void			a_partition(t_data *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chunk_push(s, &s->b);
	a_to_b(s->b.top, s->a.top, s->array);
	while (i < s->b.top->size)
		if (s->a.first->n < s->a.top->pivot)
			i += pb(s);
		else
			j += ra(s);
	a_to_a(s->a.top, s->b.top, s->array);
	if (s->a.size != s->a.top->size)
	{
		if (s->a.top->size > 4 && j)
			a_par_rest(s, j);
		else
			while (j)
				j -= rra(s);
	}
}
