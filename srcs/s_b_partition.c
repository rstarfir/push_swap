/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_b_partition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:09:15 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:12:42 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	unload_b(t_data *s)
{
	while (s->b.top->size)
	{
		pa(s);
		s->b.top->size--;
	}
	chunk_pop(&s->b);
}

void	b_partition(t_data *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	b_to_a(s->a.top, s->b.top, s->array);
	while (i < s->a.top->size)
		if (s->b.first->n >= s->b.top->pivot)
			i += pa(s);
		else
			j += rb(s);
	if (s->b.top->next)
		while (j)
			j -= rrb(s);
	b_to_b(s->b.top, s->b.top, s->array);
}
