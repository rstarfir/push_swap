/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_b_partition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:36:56 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/01 19:38:54 by rstarfir         ###   ########.fr       */
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