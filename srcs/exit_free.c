/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 21:23:01 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:05:15 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_clean(t_stack *x)
{
	while (x->first)
	{
		x->last = x->first;
		x->first = x->first->next;
		free(x->last);
	}
	while (x->top)
		chunk_pop(x);
}

void		clean(t_data *s)
{
	stack_clean(&s->a);
	stack_clean(&s->b);
	if (s->array)
		free(s->array);
}

void		ex_it(t_data *s, int code)
{
	if (code == EXIT_FAILURE)
		ft_dprintf(STDERR_FILENO, "Error\n");
	clean(s);
	exit(code);
}
