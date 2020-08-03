/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_output_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:20:34 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:14:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

static size_t	lint_put_fd_(t_lint *src, int fd)
{
	char		c;
	size_t		n;

	if ((*src).size)
	{
		c = lint_div_1(src, src, 10) + '0';
		n = lint_put_fd_(src, fd);
		write(fd, &c, 1);
		return (n + 1);
	}
	return (0);
}

size_t			lint_put_fd(t_lint src, int fd)
{
	if (src.size == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (src.sign < 0)
		write(fd, "-", 1);
	return (lint_put_fd_(&src, fd));
}

size_t			lint_put(t_lint src)
{
	if (src.size == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (src.sign < 0)
		write(1, "-", 1);
	return (lint_put_fd_(&src, 1));
}
