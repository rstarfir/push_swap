/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_core_1_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:48:26 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:48:29 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The function prepares the buffer and calls ganarating algorithm -
** fpn_dragon4().
**
** COMMENT
** Extra.
*/

#include "../includes/fpn.h"

void	fpn_k(t_fpn *x, t_bf *bf, t_fs *fs)
{
	fpn_buff_clean(bf);
	bf->s = x->sign;
	if (x->mant)
		fpn_dragon4(x, bf, free_uniqe, fs->p);
}
