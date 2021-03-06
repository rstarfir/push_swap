/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:52:23 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:52:39 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

t_lint	lint_read(char *str)
{
	t_lint	res;
	t_sign	sign;

	sign = 1;
	lint_clear(&res);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		lint_mul_1(&res, &res, 10);
		lint_add_1(&res, &res, *str++ - '0');
	}
	res.sign = sign;
	return (res);
}
