/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:23:10 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/01 19:46:14 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool		is_sorted(t_data *s)
{
	t_lst	*t;

	if ((t = s->a.first))
		while ((t = t->next))
			if (t->prev->n > t->n)
				return (false);
	return (!s->b.size);
}

t_n			strtonum(const char *str)
{
	__int128_t	f;
	__int128_t	r;
	int			sign;

	f = 0;
	r = (__int128_t)INT_MAX + 2;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	if (!ft_isdigit(*str))
		errno = EINVAL;
	while (ft_isdigit(*str) && f < r)
		f = (f << 3) + (f << 1) + *str++ + (~0x30 + 1);
	if (f >= r || (f == r - 1 && sign > 0))
		errno = ERANGE;
	while (ft_isdigit(*str))
		str++;
	if (!ft_isdigit(*str) && *str)
		errno = EINVAL;
	return (f * sign);
}