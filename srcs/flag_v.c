/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:34:34 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/01 19:37:08 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_b(t_data *s, int i, int j)
{
	t_lst	*t;
	int		k;

	t = s->b.last;
	k = -1;
	while (++k < s->b.size)
	{
		if (k == i)
		{
			ft_printf("\033[1;30;47m%lld ", t->n);
			if (k == s->b.size - 1)
				ft_printf("%{0}");
		}
		else if (k == j && i >= 0)
			ft_printf("%lld%{0} ", t->n);
		else if (k == j && i < 0)
			ft_printf("\033[1;37;41m%lld%{0} ", t->n);
		else
			ft_printf("%{6}%lld%{0} ", t->n);
		t = t->prev;
	}
	ft_printf("%{1}| ");
}

void	print_a(t_data *s, int i, int j)
{
	t_lst	*t;
	int		k;

	t = s->a.first;
	k = -1;
	while (++k < s->a.size)
	{
		if (k == i)
		{
			ft_printf("\033[1;30;47m%lld ", t->n);
			if (k == s->a.size - 1)
				ft_printf("%{0}");
		}
		else if (k == j && i >= 0)
			ft_printf("%lld%{0} ", t->n);
		else if (k == j && i < 0)
			ft_printf("\033[1;37;41m%lld%{0} ", t->n);
		else
			ft_printf("%{3}%lld%{0} ", t->n);
		t = t->next;
	}
	ft_printf("%{0}\n");
}
