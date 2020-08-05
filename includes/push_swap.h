/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:11:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 12:59:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include "push_struct.h"
# include "../Libft/includes/libft.h"

# define SA		0
# define RA		1
# define RRA	2
# define SB		3
# define RB		4
# define RRB	5
# define SS		6
# define RR		7
# define RRR	8
# define PA		9
# define PB		10

void				ex_it(t_data *s, int code);
void				clean(t_data *s);
void				init_data(t_data *s);
void				array_init(t_data *s);
void				data_parse(t_data *s, int ac, char **av);
void				top_init(t_data *s);

void				op_init(t_data *s);
void				swap(t_stack *x);
void				shift_up(t_stack *x);
void				shift_down(t_stack *x);
void				push(t_stack *dst, t_stack *src);
int					sa(t_data *s);
int					sb(t_data *s);
int					ss(t_data *s);
int					ra(t_data *s);
int					rb(t_data *s);
int					rr(t_data *s);
int					rra(t_data *s);
int					rrb(t_data *s);
int					rrr(t_data *s);
int					pa(t_data *s);
int					pb(t_data *s);

void				quicksort(int *a, int low, int high);
bool				arg_correct(char *av, t_n *n);
bool				args_correct(t_lst **array, int size);
t_n					strtonum(const char *str);
void				sort(t_data *s);
bool				is_sorted(t_data *s);
void				chunk_push(t_data *s, t_stack *x);
void				chunk_pop(t_stack *x);
bool				chunk_a_sorted(t_data *s);
bool				chunk_b_sorted(t_data *s);
void				a_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array);
void				a_to_b(t_chunk *b_dst, t_chunk *a_src, t_lst **array);
void				b_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array);
void				b_to_b(t_chunk *b_dst, t_chunk *b_src, t_lst **array);
void				a_partition(t_data *s);
void				b_partition(t_data *s);
void				unload_b(t_data *s);

void				exec_check(t_data *s);
int					str_read(char *line);
void				print_a(t_data *s, int i, int j);
void				print_b(t_data *s, int i, int j);

#endif
