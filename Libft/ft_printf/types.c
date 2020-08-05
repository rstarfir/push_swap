/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:50 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:50:53 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The functions below check if c is of one of the types.
*/

#include "../includes/ft_printf.h"

bool	is_int(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c ==
	'X' || c == 'D' || c == 'O' || c == 'U' || c == 'p' || c == 'b');
}

bool	is_fpn(char c)
{
	return (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c ==
	'G' || c == 'a' || c == 'A' || c == 'k');
}

bool	is_str(char c)
{
	return (c == 's' || c == 'S');
}

bool	is_char(char c)
{
	return (c == 'c' || c == 'C' || c == '%');
}
