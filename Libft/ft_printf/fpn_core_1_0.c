/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_1_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:48:20 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:48:22 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** These functions prepare the buffer and call ganarating algorithms
** (fpn_dragon4() or fpn_hexadecimal()).
*/

#include "../includes/fpn.h"

void	fpn_ni(t_fpn *x, t_bf *bf, t_fs *fs)
{
	bf->s = x->sign;
	bf->i = 3;
	if ((x->mant & 0x7FFFFFFFFFFFFFFFULL) == 0)
		ft_islower(fs->t) ? ft_strcpy(bf->b, "inf") : ft_strcpy(bf->b, "INF");
	else
	{
		ft_islower(fs->t) ? ft_strcpy(bf->b, "nan") : ft_strcpy(bf->b, "NAN");
		fs->f &= ~PL;
		fs->f &= ~SP;
		bf->s = 0;
	}
}

void	fpn_p(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	bf->s = x->sign;
	if (x->mant)
		fpn_dragon4(x, bf, fixed_relative, fs->p);
}

void	fpn_s(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	bf->s = x->sign;
	if (x->mant)
		fpn_dragon4(x, bf, fixed_absolute, fs->p + 1);
}

void	fpn_h(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	fpn_hexadecimal(x->mant, bf, fs);
	fpn_buff_check(bf);
	bf->s = x->sign;
	if (x->mant)
		bf->d = x->exp + (fs->s == 'L' ? 60 : 63);
}

void	fpn_g(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	!fs->p ? fs->p = 1 : 0;
	if (x->mant)
		fpn_dragon4(x, bf, fixed_absolute, fs->p);
	fpn_buff_check(bf);
}
