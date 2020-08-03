/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:58 by domurdoc          #+#    #+#             */
/*   Updated: 2020/02/17 22:17:13 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RES_STRING_H
# define RES_STRING_H
# include "ft_printf.h"

void	fill_preffix(int fa[17], bool s, char t, char **dst);
void	fill_exponent(int fa[17], char *src, char **dst);
void	fill_number(int fa[17], char *src, char **dst);
void	fill_pad(int size, char c, char **dst);
char	pad_char(t_bf *bf, t_fs *fs);

#endif
