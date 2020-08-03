/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:18:06 by domurdoc          #+#    #+#             */
/*   Updated: 2020/02/17 22:16:42 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPN_H
# define FPN_H
# include "ft_printf.h"

typedef	struct	s_fpn
{
	uint8_t		sign;
	int16_t		exp;
	uint64_t	mant;
	int16_t		dexp;
}				t_fpn;

typedef enum	e_dragon_mode
{
	free_uniqe,
	fixed_absolute,
	fixed_relative
}				t_dragon_mode;

int				fpn_dragon4(t_fpn *x, t_bf *bf, t_dragon_mode mode, int p);
void			fpn_dragon4_init(t_fpn *x, t_lint rs[2], t_lint margin[2]);
void			fpn_hexadecimal(uint64_t mant, t_bf *bf, t_fs *fs);
void			fpn_buff_clean(t_bf *bf);
void			fpn_buff_check(t_bf *bf);
int8_t			fpn_decompose(long double value, t_fpn *x);
void			fpn_ni(t_fpn *x, t_bf *bf, t_fs *fs);
void			fpn_p(t_fpn *x, t_bf *bf, t_fs *fs);
void			fpn_s(t_fpn *x, t_bf *bf, t_fs *fs);
void			fpn_h(t_fpn *x, t_bf *bf, t_fs *fs);
void			fpn_g(t_fpn *x, t_bf *bf, t_fs *fs);
void			fpn_k(t_fpn *x, t_bf *bf, t_fs *fs);

#endif
