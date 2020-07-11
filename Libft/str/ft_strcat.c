/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:21:37 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/16 18:55:45 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ss1;

	ss1 = s1;
	while (*s1)
		++s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = 0;
	return (ss1);
}