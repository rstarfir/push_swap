/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint_output_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:21:08 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 19:14:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lint.h"

static size_t	lint_putstr_(t_lint *src, char *str)
{
	char	c;
	size_t	n;

	if ((*src).size)
	{
		c = lint_div_1(src, src, 10) + '0';
		n = lint_putstr_(src, str);
		*(str + n) = c;
		return (n + 1);
	}
	return (0);
}

size_t			lint_putstr(t_lint src, char *str)
{
	size_t	n;

	if (src.size == 0)
	{
		*str++ = '0';
		*str = '\0';
		return (1);
	}
	if (src.sign < 0)
		*str++ = '-';
	n = lint_putstr_(&src, str);
	*(str + n) = '\0';
	return (src.sign < 0 ? n + 1 : n);
}

char			*lint_tostr(t_lint src)
{
	char	*str;
	t_lint	tmp;
	size_t	n;

	n = src.sign < 0 ? 1 : 0;
	lint_copy(&tmp, &src);
	while (tmp.size)
	{
		lint_div_1(&tmp, &tmp, 10);
		n++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	src.sign < 0 ? str[0] = '-' : 0;
	str[n] = '\0';
	while (src.size)
	{
		str[--n] = lint_div_1(&src, &src, 10) + '0';
	}
	return (str);
}

static char		*lint_tostr2_(t_lint *src, size_t *n)
{
	char	*str;
	char	c;
	size_t	i;

	i = *n;
	if ((*src).size)
	{
		(*n)++;
		c = lint_div_1(src, src, 10) + '0';
		if (!(str = lint_tostr2_(src, n)))
			return (NULL);
		str[(*n) - i - 1] = c;
	}
	else
	{
		if ((str = (char*)malloc(sizeof(char) * (*n + 1))))
			str[*n] = '\0';
		(*src).sign < 0 ? (*n)++ : 0;
	}
	return (str);
}

char			*lint_tostr2(t_lint src)
{
	size_t	n;
	t_size	size;
	char	*str;

	size = src.size;
	n = src.sign < 0 || !size ? 1 : 0;
	if ((str = lint_tostr2_(&src, &n)))
	{
		if (size == 0)
			str[0] = '0';
		else if (src.sign < 0)
			str[0] = '-';
	}
	return (str);
}
