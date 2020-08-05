/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:13:54 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:10:34 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_data *s)
{
	swap(&s->a);
	if (s->mode == push_swap)
		ft_putendl("sa");
	else if (s->mode == checker_v)
	{
		ft_printf("sa\t");
		print_b(s, -1, -1);
		print_a(s, 0, 1);
	}
	return (1);
}

int	ra(t_data *s)
{
	shift_up(&s->a);
	if (s->mode == push_swap)
		ft_putendl("ra");
	else if (s->mode == checker_v)
	{
		ft_printf("ra\t");
		print_b(s, -1, -1);
		print_a(s, -1, s->a.size - 1);
	}
	return (1);
}

int	rra(t_data *s)
{
	shift_down(&s->a);
	if (s->mode == push_swap)
		ft_putendl("rra");
	else if (s->mode == checker_v)
	{
		ft_printf("rra\t");
		print_b(s, -1, -1);
		print_a(s, -1, 0);
	}
	return (1);
}

int	pa(t_data *s)
{
	push(&s->a, &s->b);
	if (s->b.size)
	{
		s->a.size++;
		s->b.size--;
	}
	if (s->mode == push_swap)
		ft_putendl("pa");
	else if (s->mode == checker_v)
	{
		ft_printf("pa\t");
		print_b(s, -1, -1);
		print_a(s, -1, -1);
	}
	return (1);
}
