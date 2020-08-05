/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:45:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:59:48 by rstarfir         ###   ########.fr       */
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

typedef struct			s_stack
{
	int					size;
	t_lst				*first;
	t_lst				*last;
	t_chunk				*top;
}						t_stack;

typedef enum			e_mode
{
	checker,
	checker_v,
	push_swap,
}						t_mode;

typedef struct			s_data
{
	t_mode				mode;
	t_stack				a;
	t_stack				b;
	t_lst				**array;
	int					(*op[11])(struct s_data*);
}						t_data;

#endif
