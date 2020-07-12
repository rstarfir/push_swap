/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:11:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/12 16:37:08 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/includes/libft.h"
#include <stdio.h>

typedef struct			s_stack
{
	int					value;
	size_t				index;
	struct s_elem		*next;
	
}						t_stack;

void					push_swap(int argc, char *argv);
void					push(t_stack **a, t_stack **b);
void					swap(t_stack **s);
void					rotate(t_stack **s);
void					revrot(t_stack **s);
t_stack					*indexlstnew(int val, int i);
void					indexlstdel(t_stack **s);
int						stack_popfirst(t_stack **s);
int						stack_poplast(t_stack *s, int *i);
int						stack_push(int val, int i, t_stack **s);
int						stack_pushback(int val, int i, t_stack *s);

#endif