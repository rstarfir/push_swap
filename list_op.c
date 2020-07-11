/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:22:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/11 21:40:29 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_stack		*indexlistnew(int val, int i)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->index = i;
	s->value = val;
	s->next = NULL;
	return (s);
}

int			stack_pop()
{

}

int 		stack_push(int val, int i, t_stack **s)
{
	t_stack		*new;

	new = indexlistnew(val, i);
	new->next = *s;
	*s = new;
}

int 		stack_pushback(int val, int i, t_stack *s)
{
	t_stack		*new;

	new = indexlistnew(val, i);
	while (s->next)
		s = s->next;
	s->next = new;
}
