/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:20:04 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/12 16:26:36 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*indexlistnew(int val, int i)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->index = i;
	s->value = val;
	s->next = NULL;
	return (s);
}

void	indexlstdel(t_stack **s)
{
	t_stack		*tmp;
	t_stack		*ss;

	if (!*s)
		return ;
	ss = *s;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	ss = NULL;
}