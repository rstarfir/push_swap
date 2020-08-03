/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:41:01 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/03 16:29:15 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		str_read(char *line)
{
	if (ft_strequ(line, "sa"))
		return (SA);
	else if (ft_strequ(line, "ra"))
		return (RA);
	else if (ft_strequ(line, "rra"))
		return (RRA);
	else if (ft_strequ(line, "sb"))
		return (SB);
	else if (ft_strequ(line, "rb"))
		return (RB);
	else if (ft_strequ(line, "rrb"))
		return (RRB);
	else if (ft_strequ(line, "ss"))
		return (SS);
	else if (ft_strequ(line, "rr"))
		return (RR);
	else if (ft_strequ(line, "rrr"))
		return (RRR);
	else if (ft_strequ(line, "pa"))
		return (PA);
	else if (ft_strequ(line, "pb"))
		return (PB);
	else
		return (-1);
}

void	exec_check(t_data *s)
{
	char	*line;
	int		i;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if ((i = str_read(line)) < 0)
			ex_it(s, EXIT_FAILURE);
		s->op[i](s);
		free(line);
	}
	if (line)
		free(line);
}