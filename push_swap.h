/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:11:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/13 15:17:44 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/includes/libft.h"
#include <stdio.h>

typedef struct			s_ilist
{
	int					value;
	size_t				index;
	struct s_ilist		*next;
	
}						t_ilist;

typedef struct			s_stack
{
	int				val;
	struct s_stack	*next;
}						t_stack;

void					push_swap(int argc, char *argv);
void					push(t_ilist **a, t_ilist **b);
void					swap(t_ilist **s);
void					rotate(t_ilist **s);
void					revrot(t_ilist **s);
t_ilist					*indexlstnew(int val, int i);
void					indexlstdel(t_ilist **s);
int						indexlist_popfirst(t_ilist **s);
int						indexlist_poplast(t_ilist *s, int *i);
int						indexlist_push(int val, int i, t_ilist **s);
int						indexlist_pushback(int val, int i, t_ilist *s);

#endif