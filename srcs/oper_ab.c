/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:08:28 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:08:35 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_data *s)
{
	swap(&s->a);
	swap(&s->b);
	if (s->mode == push_swap)
		ft_putendl("ss");
	else if (s->mode == checker_v)
	{
		ft_printf("ss\t");
		print_b(s, s->b.size - 2, s->b.size - 1);
		print_a(s, 0, 1);
	}
	return (1);
}

int	rr(t_data *s)
{
	shift_up(&s->a);
	shift_up(&s->b);
	if (s->mode == push_swap)
		ft_putendl("rr");
	else if (s->mode == checker_v)
	{
		ft_printf("rr\t");
		print_b(s, -1, 0);
		print_a(s, -1, s->a.size - 1);
	}
	return (1);
}

int	rrr(t_data *s)
{
	shift_down(&s->a);
	shift_down(&s->b);
	if (s->mode == push_swap)
		ft_putendl("rrr");
	else if (s->mode == checker_v)
	{
		ft_printf("rrr\t");
		print_b(s, -1, s->b.size - 1);
		print_a(s, -1, 0);
	}
	return (1);
}
