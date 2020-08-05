/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:01 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:50:07 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_int() function takes a pointed to an integer of size needed by using
** va_arg and writes the number of bytes have been passed into it.
**
** RETURN VALUE
** The function returns 0.
*/

#include "../includes/ft_printf.h"

int	hub_n(va_list ap, t_asb *asb, t_fs *fs)
{
	if (!fs->s)
		*(va_arg(ap, int*)) = asb->i;
	else if (fs->s == 'h' + 128)
		*(va_arg(ap, char*)) = asb->i;
	else if (fs->s == 'h')
		*(va_arg(ap, short*)) = asb->i;
	else if (fs->s == 'l')
		*(va_arg(ap, long*)) = asb->i;
	else if (fs->s == 'l' + 128)
		*(va_arg(ap, long long*)) = asb->i;
	else if (fs->s == 'j' || fs->s == 'z' || fs->s == 't')
		*(va_arg(ap, intmax_t*)) = asb->i;
	return (0);
}
