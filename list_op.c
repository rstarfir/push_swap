/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:22:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/13 15:11:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int			indexlist_popfirst(t_ilist **s)
{
	t_ilist		*tmp;
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

int			indexlist_poplast(t_ilist *s, int *i)
{
	t_ilist *tmp;
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

int			indexlist_push(int val, int i, t_ilist **s)
{
	t_ilist		*new;

	new = indexlistnew(val, i);
	new->next = *s;
	*s = new;
}

int			indexlist_pushback(int val, int i, t_ilist *s)
{
	t_ilist		*new;

	new = indexlistnew(val, i);
	while (s->next)
		s = s->next;
	s->next = new;
}
