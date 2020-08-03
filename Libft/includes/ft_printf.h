/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:45:29 by domurdoc          #+#    #+#             */
/*   Updated: 2020/02/17 22:16:59 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <wchar.h>
# include "libft.h"
# include "lint.h"

/*
** Flags:
** SH, sharp-sign:	0000 0000 0000 0001
** ZE, zero-sign:	0000 0000 0000 0010
** MI, minus-sign:	0000 0000 0000 0100
** SP, space-sign:	0000 0000 0000 1000
** PL, plus-sign:	0000 0000 0001 0000
*/

# define SH 0x1u
# define ZE 0x2u
# define MI 0x4u
# define SP 0x8u
# define PL 0x10u

/*
** Structure for printf format-string:
** f - flags;
** w - width;
** p - precision;
** s - type-size;
** t - type;
** c - color.
*/

typedef struct		s_fs
{
	uint16_t		f;
	int				w;
	int				p;
	unsigned char	s;
	unsigned char	t;
	int8_t			c;
}					t_fs;

/*
** Chained list for accumulating strings:
** s - pointer to a string;
** i - size of the string;
** f - freeable;
** *next - pointer to the next list.
*/

typedef struct		s_as
{
	char			*s;
	int				i;
	bool			f;
	struct s_as		*next;
}					t_as;

/*
** The head of the chained list above:
** curr - pointer to the current list (last one);
** head - the beginning of the lists;
** i - size of all the lists;
*/

typedef struct		s_asb
{
	t_as			*curr;
	t_as			*head;
	int				i;
}					t_asb;

/*
** Structure for buffer:
** b - pointer to the allocated memory;
** s - sign (integers and float);
** d - decimal exponent or the beginning index for integers;
** i - next index (float) and size of the string;
*/

typedef struct		s_bf
{
	char			*b;
	bool			s;
	int16_t			d;
	uint16_t		i;
}					t_bf;

/*
** Getting buffer for integers and floats
*/

char				*buff_get(t_fs *fs);

/*
** Initialization of the format-string structure
*/

bool				fs_read(const char **fmt, t_fs *fs, va_list ap);

/*
** Types recognizing
*/

bool				is_int(char c);
bool				is_fpn(char c);
bool				is_str(char c);
bool				is_char(char c);

/*
** Calculating of the format-array fa[17]
*/

void				fa_clean(int fa[17]);
void				fa_nsp(int fa[17], t_fs *fs);
void				fa_int(int fa[17], t_bf *bf, t_fs *fs);
void				fa_fpnp(int fa[17], t_bf *bf, t_fs *fs);
void				fa_fpns(int fa[17], t_bf *bf, t_fs *fs);
void				fa_fpng(int fa[17], t_bf *bf, t_fs *fs);
void				fa_fpnni(int fa[17], t_bf *bf, t_fs *fs);
void				fa_str(int fa[17], t_bf *bf, t_fs *fs);
void				fa_char(int fa[17], t_bf *bf, t_fs *fs);
void				fa_addr(int fa[17], t_bf *bf, t_fs *fs);
void				fa_lint(int fa[17], t_bf *bf, t_fs *fs);
void				fa_fpnk(int fa[17], t_bf *bf, t_fs *fs);

/*
** Getting resulting string for an argument
*/

int					res_string(char **str, t_bf *bf, t_fs *fs, void (*f)(int*,
					t_bf*, t_fs*));

/*
** Hubs for different types
*/

int					hub_int(char **str, va_list ap, t_fs *fs);
int					hub_fpn(char **str, va_list ap, t_fs *fs);
int					hub_str(char **str, va_list ap, t_fs *fs);
int					hub_char(char **str, va_list ap, t_fs *fs);
int					hub_n(va_list ap, t_asb *asb, t_fs *fs);
int					hub_lint(char **str, va_list ap, t_fs *fs);
int					hub_color(char **str, t_fs *fs);

/*
** Accumulating strings in the structure t_as
*/

t_as				*as_push_init(t_as **curr, char *str, int size, bool f);
t_as				*as_push_new(t_as **curr, char *str, int size, bool f);
t_as				*as_push(t_asb *asb, char *str, int size, bool f);
char				*as_return(t_asb *asb);
int					as_abort(t_asb *asb);

#endif
