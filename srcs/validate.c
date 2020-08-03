/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 21:39:56 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/01 14:12:56 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	arg_correct(char *av, t_n *n)
{
	errno = 0;
	*n = strtonum((const char*)av);
	if (errno == ERANGE || errno == EINVAL)
		return (false);
	return (true);
}

bool	args_correct(t_lst **array, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (array[i]->n == array[i - 1]->n)
			return (false);
	return (true);
}
