/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lint.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:03:40 by domurdoc          #+#    #+#             */
/*   Updated: 2020/02/17 22:17:10 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINT_H
# define LINT_H
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define SIZE 600
# define LSIZE 32

# define LHSIZE 16
# define LMAX 0xFFFFFFFF
# define LHALF 0xFFFF
# define HBIT 0x80000000

typedef uint32_t	t_limb;
typedef uint64_t	t_dlimb;
typedef	int8_t		t_sign;
typedef int16_t		t_count;
typedef int16_t		t_size;
typedef int32_t		t_dcount;

typedef struct	s_lint
{
	t_sign		sign;
	t_size		size;
	t_limb		limb[SIZE];
}				t_lint;

void			lint_clear(t_lint *dst);
void			lint_assign(t_lint *dst, t_dlimb src, t_sign sign);
t_size			lint_normsize(t_lint *src);
void			lint_copy(t_lint *dst, t_lint *src);

void			lint_lshift_size(t_lint *dst, t_lint *src, t_size sh);
void			lint_lshift(t_lint *dst, t_lint *src, t_dcount sh);
void			lint_rshift_size(t_lint *dst, t_lint *src, t_size sh);
void			lint_rshift(t_lint *dst, t_lint *src, t_dcount sh);

t_sign			lint_cmp(t_lint *a, t_lint *b);
t_sign			lint_cmp_abs(t_lint *a, t_lint *b);

void			lint_add_1(t_lint *res, t_lint *a, t_limb b);
void			lint_add(t_lint *res, t_lint *a, t_lint *b);

void			lint_sub_1(t_lint *res, t_lint *a, t_limb b);
void			lint_sub(t_lint *res, t_lint *a, t_lint *b);

void			lint_mul_1(t_lint *res, t_lint *a, t_limb b);
void			lint_mul(t_lint *res, t_lint *a, t_lint *b);

t_limb			lint_div_1(t_lint *q, t_lint *a, t_limb b);
t_lint			lint_div(t_lint *q, t_lint a, t_lint b);

size_t			lint_put(t_lint src);
size_t			lint_put_fd(t_lint src, int fd);

size_t			lint_putstr(t_lint src, char *str);
char			*lint_tostr(t_lint src);
char			*lint_tostr2(t_lint src);

t_lint			lint_read(char *str);

t_lint			lint_10pow(t_count exp);
t_lint			lint_2pow(t_dcount exp);

#endif
