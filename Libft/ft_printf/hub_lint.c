/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_lint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:49:55 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:49:58 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_lint() function is called by printf_hub() in case of lint-type.
**
** RETURN VALUE
** The function returns the length of the resulting string or -1 in case of an
** error.
*/

#include "../includes/ft_printf.h"

static void	lint_get(t_lint *n, t_bf *bf)
{
	t_lint		tmp;
	uint16_t	i;

	i = 0;
	lint_copy(&tmp, n);
	while (tmp.size)
	{
		lint_div_1(&tmp, &tmp, 10);
		i++;
	}
	if (!(bf->b = (char*)malloc(sizeof(char) * (i + 1))))
		return ;
	bf->i = i;
	bf->s = (*n).sign < 0;
	while ((*n).size)
		bf->b[--i] = lint_div_1(n, n, 10) + '0';
}

static int	lint_lint(char **str, t_lint *n, t_fs *fs)
{
	t_bf	bf;
	int		i;

	lint_get(n, &bf);
	if (!bf.b)
		return (-1);
	i = res_string(str, &bf, fs, fa_lint);
	free(bf.b);
	return (i);
}

int			hub_lint(char **str, va_list ap, t_fs *fs)
{
	t_lint	n;

	n = va_arg(ap, t_lint);
	return (lint_lint(str, &n, fs));
}
