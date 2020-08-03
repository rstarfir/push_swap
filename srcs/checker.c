/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:45:49 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/03 13:45:38 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	mode(t_data *s, char **av)
{
	int	v;
	int	counter;

	s->mode = checker;
	counter = 0;
	while (*++av)
		if ((v = ft_strequ(*av, "-v")))
		{
			s->mode = checker_v;
			*av = NULL;
			counter++;
		}
	return (counter);
}

int		main(int ac, char **av)
{
	t_data	s;

	init_data(&s);
	if (ac - mode(&s, av) < 2)
		ex_it(&s, EXIT_SUCCESS);
	data_parse(&s, ac, av);
	exec_check(&s);
	if (is_sorted(&s))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	clean(&s);
	return(0);
}