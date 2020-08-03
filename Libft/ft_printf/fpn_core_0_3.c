/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_0_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:21:39 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:54:25 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Here are functions to obtain hexadecimal representation of the fpn.
*/

#include "../includes/fpn.h"

static void	fpn_hex_round(uint8_t vec[17], t_bf *bf, t_fs *fs)
{
	char		*range;
	uint16_t	i;

	i = 0;
	range = fs->t == 'a' ? "0123456789abcdef" : "0123456789ABCDEF";
	if (fs->p >= 0 && bf->i > (fs->p + 1))
	{
		bf->i = fs->p + 1;
		if (vec[bf->i] > 8)
			vec[bf->i - 1]++;
		else if (vec[bf->i] == 8)
			if (vec[bf->i - 1] & 1)
				vec[bf->i - 1]++;
		while (bf->i > 1 && vec[bf->i - 1] > 15)
			vec[--bf->i - 1]++;
		if (bf->i == 1 && vec[bf->i - 1] > 15)
		{
			bf->d++;
			vec[0] = 1;
		}
	}
	while (i++ < bf->i)
		bf->b[i - 1] = range[vec[i - 1]];
}

void		fpn_hexadecimal(uint64_t mant, t_bf *bf, t_fs *fs)
{
	uint8_t	i;
	uint8_t	vec[17];

	if (fs->s != 'L')
	{
		vec[bf->i++] = (mant >> 63);
		mant <<= 1;
	}
	i = 64;
	while (i)
	{
		i -= 4;
		vec[bf->i++] = (mant >> i) & 0xf;
	}
	fpn_hex_round(vec, bf, fs);
}
