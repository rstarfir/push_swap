/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_fpn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:49:46 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:49:48 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** hub_fpn() function is called by printf_hub() in case of fpn-type.
**
** RETURN VALUE
** The function returns the length of the resulting string or -1 in case of an
** error.
*/

#include "../includes/fpn.h"

static void	fpn_def(t_fs *fs, void (**fpn_)(t_fpn*, t_bf*, t_fs*),
void (**fa_)(int*, t_bf*, t_fs*))
{
	if ((fs->t == 'f' || fs->t == 'F') && (*fpn_ = fpn_p))
		*fa_ = fa_fpnp;
	else if ((fs->t == 'e' || fs->t == 'E') && (*fpn_ = fpn_s))
		*fa_ = fa_fpns;
	else if ((fs->t == 'g' || fs->t == 'G') && (*fpn_ = fpn_g))
		*fa_ = fa_fpng;
	else if ((fs->t == 'a' || fs->t == 'A') && (*fpn_ = fpn_h))
		*fa_ = fa_fpns;
	else if ((*fpn_ = fpn_k))
		*fa_ = fa_fpnk;
}

static int	fpn_fpn(char **str, long double n, t_fs *fs)
{
	t_bf	bf;
	t_fpn	x;
	int		i;
	void	(*fpn_)(t_fpn*, t_bf*, t_fs*);
	void	(*fa_)(int*, t_bf*, t_fs*);

	fs->p < 0 && fs->t != 'a' && fs->t != 'A' ? fs->p = 6 : 0;
	fpn_def(fs, &fpn_, &fa_);
	if (!(bf.b = buff_get(fs)))
		return (-1);
	if (fpn_decompose(n, &x) > 0)
	{
		fpn_ni(&x, &bf, fs);
		i = res_string(str, &bf, fs, fa_fpnni);
	}
	else
	{
		fpn_(&x, &bf, fs);
		i = res_string(str, &bf, fs, fa_);
	}
	free(bf.b);
	return (i);
}

int			hub_fpn(char **str, va_list ap, t_fs *fs)
{
	long double	n;

	n = fs->s == 'L' ? va_arg(ap, long double) : va_arg(ap, double);
	return (fpn_fpn(str, n, fs));
}
