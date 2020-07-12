/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:22:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/12 16:24:01 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int			stack_popfirst(t_stack **s)
{
	t_stack		*tmp;
	int			val;

	if (!(*s)->next)
	{
		val = (*s)->value;
		indextlistdel(s);
	}
	else
	{
		tmp = *s;
		val = (*s)->value;
		*s = (*s)->next;
		free(tmp);
	}
	return(val);
}

int			stack_poplast(t_stack *s, int *i)
{
	t_stack *tmp;
	int		val;

	while (s->next)
	{
		tmp = s;
		s = s->next;
	}
	val = s->value;
	*i = s->index;
	free(s);
	tmp->next = NULL;
	return (val);
}

int			stack_push(int val, int i, t_stack **s)
{
	t_stack		*new;

	new = indexlistnew(val, i);
	new->next = *s;
	*s = new;
}

int			stack_pushback(int val, int i, t_stack *s)
{
	t_stack		*new;

	new = indexlistnew(val, i);
	while (s->next)
		s = s->next;
	s->next = new;
}
