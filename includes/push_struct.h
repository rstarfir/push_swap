/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:45:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/03 16:28:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STRUCT_H
# define PUSH_STRUCT_H

typedef int				t_n;

typedef struct			s_lst
{
	int					n;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			s_chunk
{
	int					size;
	int					ipivot;
	t_n					pivot;
	struct s_chunk		*next;
}						t_chunk;

typedef struct		s_stack
{
	int					size;
	t_lst				*first;
	t_lst				*last;
	t_chunk				*top;//список chunk'ov
}						t_stack;

typedef enum			e_mode
{
	checker,
	checker_v,
	push_swap,
}						t_mode;

typedef struct			s_data
{
	t_mode				mode;//режим запуска
	t_stack				a;
	t_stack				b;
	t_lst				**array;//массив листов
	int					(*op[11])(struct s_data*);
}						t_data;

#endif