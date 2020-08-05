/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:46:33 by rstarfir          #+#    #+#             */
/*   Updated: 2020/08/05 13:05:49 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		init_data(t_data *s)
{
	s->a.first = NULL;
	s->a.last = NULL;
	s->a.top = NULL;
	s->a.size = 0;
	s->b.first = NULL;
	s->b.last = NULL;
	s->b.top = NULL;
	s->b.size = 0;
	s->array = NULL;
}

static void	lst_push(t_data *s, t_n n)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		ex_it(s, EXIT_FAILURE);
	new->n = n;
	new->prev = s->a.last;
	new->next = NULL;
	if (s->a.last)
		s->a.last->next = new;
	if (!s->a.first)
		s->a.first = new;
	s->a.last = new;
}

static void	parsing(t_data *s, char *av)
{
	char	**v;
	int		i;
	t_n		n;

	v = ft_strsplit((const char*)av, ' ');
	i = -1;
	while (v[++i])
	{
		if (!arg_correct(v[i], &n))
			ex_it(s, EXIT_FAILURE);
		lst_push(s, n);
		s->a.size++;
		free(v[i]);
	}
	free(v);
}

void		data_parse(t_data *s, int ac, char **av)
{
	while (--ac)
	{
		if (!*++av)
			continue ;
		parsing(s, *av);
	}
	if (!(s->array = (t_lst**)malloc(sizeof(t_lst*) * s->a.size)))
		ex_it(s, EXIT_FAILURE);
	array_init(s);
	if (!args_correct(s->array, s->a.size))
		ex_it(s, EXIT_FAILURE);
	top_init(s);
	op_init(s);
}
