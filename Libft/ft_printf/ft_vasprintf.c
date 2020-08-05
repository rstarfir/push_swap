/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:49:19 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:49:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** DESCRIPTION
** ft_vasprintf() function is another implementation of standard vasprintf().
**
** RETURN VALUE
** The function returns the number of bytes printed or -1 in case of an error.
**
** COMMENT
** It is called by ft_printf(), ft_dprintf() and ft_printfc() functions.
*/

static bool	check(const char **fmt, char **str, t_asb *asb, int i)
{
	if (!i)
	{
		asb->curr = as_push(asb, (char*)*fmt, 0, 0);
	}
	else if (i > 0)
	{
		asb->i += i;
		asb->curr = as_push(asb, *str, i, 1);
		asb->curr = as_push(asb, (char*)*fmt, 0, 0);
	}
	return (i < 0 || !asb->curr ? false : true);
}

static bool	hub(const char **fmt, char **str, t_asb *asb, va_list ap)
{
	t_fs	fs;
	int		i;

	asb->curr->i = (char*)*fmt - asb->curr->s;
	asb->i += asb->curr->i;
	if ((i = fs_read(fmt, &fs, ap)))
	{
		if (is_int(fs.t))
			i = hub_int(str, ap, &fs);
		else if (is_fpn(fs.t))
			i = hub_fpn(str, ap, &fs);
		else if (is_str(fs.t))
			i = hub_str(str, ap, &fs);
		else if (is_char(fs.t))
			i = hub_char(str, ap, &fs);
		else if (fs.t == 'n')
			i = hub_n(ap, asb, &fs);
		else if (fs.t == 'v')
			i = hub_lint(str, ap, &fs);
		else if (fs.c >= 0)
			i = hub_color(str, &fs);
	}
	return (check(fmt, str, asb, i));
}

int			ft_vasprintf(char **str, const char *fmt, va_list ap)
{
	t_asb	asb;

	asb.i = 0;
	if (!(asb.curr = as_push_new(&(asb.head), (char*)fmt, 0, 0)))
		return (-1);
	while (*fmt)
		if (*fmt == '%')
		{
			if (!hub(&fmt, str, &asb, ap))
				return (as_abort(&asb));
		}
		else
			fmt++;
	asb.curr->i = (char*)fmt - asb.curr->s;
	asb.i += asb.curr->i;
	*str = as_return(&asb);
	return (*str ? asb.i : -1);
}
