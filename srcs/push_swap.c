/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:26:33 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:06:32 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_data	s;

	s.mode = push_swap;
	init_data(&s);
	if (ac < 2)
		ex_it(&s, EXIT_SUCCESS);
	data_parse(&s, ac, av);
	sort(&s);
	clean(&s);
	return (0);
}
