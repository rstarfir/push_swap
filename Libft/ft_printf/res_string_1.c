/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_string_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:50:44 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:50:46 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** res_string() function takes a pointer to a function to initialize
** format-array fa, allocates memory for the resulting string str with
** malloc(3), fills it by calling fill_string() and returns the size of the
** string.
** fill_string() function fills the new string allocated by res_string()
** according to the format structure *fs.
**
** COMMENT
** As mentioned in int_core.c bf->b[bf->d] is the first character of an integer
** buffer.
*/

#include "../includes/ft_printf.h"
#include "../includes/res_string.h"

static void	fill_string(char *str, int fa[17], t_fs *fs, t_bf *bf)
{
	char	c;
	char	*buffer;

	buffer = is_int(fs->t) ? &bf->b[bf->d] : bf->b;
	c = pad_char(bf, fs);
	if (fs->f & MI)
	{
		fill_preffix(fa, bf->s, fs->t, &str);
		fill_number(fa, buffer, &str);
		fill_pad(fa[2], ' ', &str);
	}
	else if (c == '0')
	{
		fill_preffix(fa, bf->s, fs->t, &str);
		fill_pad(fa[2], c, &str);
		fill_number(fa, buffer, &str);
	}
	else
	{
		fill_pad(fa[2], c, &str);
		fill_preffix(fa, bf->s, fs->t, &str);
		fill_number(fa, buffer, &str);
	}
}

int			res_string(char **str, t_bf *bf, t_fs *fs, void (*f)(int*, t_bf*,
			t_fs*))
{
	int		fa[17];

	fa_clean(fa);
	f(fa, bf, fs);
	if (fa[1])
	{
		if ((*str = (char*)malloc(sizeof(char) * (fa[1] + 1))))
			fill_string(*str, fa, fs, bf);
		else
			return (-1);
	}
	return (fa[1]);
}
