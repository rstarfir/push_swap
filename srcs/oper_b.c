/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:15:53 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/01 13:16:25 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sb(t_data *s)
{
	swap(&s->b);
	if (s->mode == push_swap)
		ft_putendl("sb");
	else if (s->mode == checker_v)
	{
		ft_printf("sb\t");
		print_b(s, s->b.size - 2, s->b.size - 1);
		print_a(s, -1, -1);
	}
	return (1);
}

int	rb(t_data *s)
{
	shift_up(&s->b);
	if (s->mode == push_swap)
		ft_putendl("rb");
	else if (s->mode == checker_v)
	{
		ft_printf("rb\t");
		print_b(s, -1, 0);
		print_a(s, -1, -1);
	}
	return (1);
}

int	rrb(t_data *s)
{
	shift_down(&s->b);
	if (s->mode == push_swap)
		ft_putendl("rrb");
	else if (s->mode == checker_v)
	{
		ft_printf("rrb\t");
		print_b(s, -1, s->b.size - 1);
		print_a(s, -1, -1);
	}
	return (1);
}

int	pb(t_data *s)
{
	push(&s->b, &s->a);
	if (s->a.size)
	{
		s->b.size++;
		s->a.size--;
	}
	if (s->mode == push_swap)
		ft_putendl("pb");
	else if (s->mode == checker_v)
	{
		ft_printf("pb\t");
		print_b(s, -1, -1);
		print_a(s, -1, -1);
	}
	return (1);
}
