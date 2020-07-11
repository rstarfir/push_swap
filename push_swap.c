/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:26:33 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/11 22:01:11 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	
}

int		main(int argc, char **argv)
{
	char	**arg;
	char	**freearg;

	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		arg = ft_strsplit(argv[1], ' ');
		freearg = arg;
		push_swap(ft_wrdcnt(argv[1], ' '), arg);
		while (*arg)
		{
			free(*arg);
			arg++;
		}
		free(freearg);
	}
	else
	push_swap(argc, &argv[1]);
	return (0);
}
