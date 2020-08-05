/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:07:15 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:55:11 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_data *s)
{
	while (!is_sorted(s))
	{
		while (s->a.top->size)
			if (chunk_a_sorted(s))
				s->a.top->size = 0;
			else if (s->a.top->size == 2)
			{
				(void)sa(s);
				s->a.top->size = 0;
			}
			else
				a_partition(s);
		s->a.top->size = 0;
		if (s->b.top->size != 0)
		{
			if (chunk_b_sorted(s))
				unload_b(s);
			else if (s->b.top->size == 2)
			{
				(void)sb(s);
				unload_b(s);
			}
			else
				b_partition(s);
		}
	}
}
