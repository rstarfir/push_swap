/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:16:38 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/01 18:52:30 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** These functions deal with accumulating strings structure t_as that is a list
** used to collect all the strings during processing the format string and
** return the final srting by ft_vasprintf() function.
** They may take a flag f denoting string str that can be freed with free(3),
** size of the string, a pointer to the current list or a structure asb, which
** is the beginning of the chained list.
**
** RETURN VALUE
** t_as*, char*.
**
** COMMENT
** as_push_init() function is used to initialize an empty list and it returns
** the pointer to the passed structure.
** as_push_new() function is used to push a list using malloc(3) and it
** returns a pointer to the new list.
** as_push() function is just a trigger to choose either as_push_init() or
** as_push_new().
** as_return() function passes through all the lists, generates the final
** string using malloc(3) and frees unnecessary memory.
** as_abort() function frees the chained list and its data in case of an error.
*/

#include "../includes/ft_printf.h"

t_as	*as_push_init(t_as **curr, char *str, int size, bool f)
{
	(*curr)->s = str;
	(*curr)->i = size;
	(*curr)->f = f;
	return (*curr);
}

t_as	*as_push_new(t_as **curr, char *str, int size, bool f)
{
	if ((*curr = (t_as*)malloc(sizeof(t_as))))
	{
		(*curr)->s = str;
		(*curr)->i = size;
		(*curr)->f = f;
		(*curr)->next = NULL;
	}
	return (*curr);
}

t_as	*as_push(t_asb *asb, char *str, int size, bool f)
{
	if (!asb->curr)
		return (NULL);
	if (asb->curr->i)
		return (as_push_new(&(asb->curr->next), str, size, f));
	else
		return (as_push_init(&(asb->curr), str, size, f));
}

char	*as_return(t_asb *asb)
{
	char	*str;
	char	*tmp1;
	t_as	*curr;
	t_as	*tmp2;

	if (!(str = (char*)malloc(sizeof(char) * (asb->i + 1))))
	{
		as_abort(asb);
		return (NULL);
	}
	tmp1 = str;
	curr = asb->head;
	while (curr)
	{
		tmp2 = curr;
		ft_memcpy(str, curr->s, curr->i);
		str += curr->i;
		curr = curr->next;
		if (tmp2->f)
			free(tmp2->s);
		free(tmp2);
	}
	*str = '\0';
	return (tmp1);
}

int		as_abort(t_asb *asb)
{
	while (asb->head)
	{
		asb->curr = asb->head;
		asb->head = asb->head->next;
		if (asb->curr->f)
			free(asb->curr->s);
		free(asb->curr);
	}
	return (-1);
}
