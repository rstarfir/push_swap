/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:25:33 by rstarfir          #+#    #+#             */
/*   Updated: 2020/07/30 22:10:23 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_mid(int *ptr, int left, int right)
{
	int mid_val = 0;
	int i = left;

	if	(i <= right)
		i++;
	mid_val = ptr[i/2];
	return (mid_val);
}

/*
** сравниваем значения pivot_val c последнем значением
** итерируемся и сравниваем дальше 
** свопаем значения
*/
static int		partition(int *a, int low, int high)
{
	int		pivot;
	int		pivot_val;

	pivot = low;
	pivot_val = a[pivot];
	while(low < high)
	{
		while(a[low] <= pivot_val)
			low++;
		while(a[high] > pivot_val)
			high--;
		if (low < high)
			ft_swap(&a[low], &a[high]);
	}
	ft_swap(&a[pivot], &a[high]);
	return high;
}

/*
** проверяем на пересечение low и high
** разделяем массив на 2 части 
** рекурсивно вызываем сортировку сначала с первой частью и со второй 
*/
void	quicksort(int *a, int low, int high)
{
	int split;
	if (high <= low)
		return;
	split = partition(a, low, high);
	quicksort(a, low, split - 1);
	quicksort(a, split + 1, high);
}