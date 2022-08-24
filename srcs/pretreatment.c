/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:05:46 by minabe            #+#    #+#             */
/*   Updated: 2022/08/23 21:20:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

static size_t	lower_bound(int	*array, int value, size_t size);
static void		sort(int *array, size_t size);

void	coordinate_compression(int *array, size_t *coordinate, size_t size)
{
	size_t	i;
	int		*array_cp;

	array_cp = malloc(sizeof(int) * (size));
	if (array_cp == NULL)
		error();
	ft_memcpy(array_cp, array, size);
	sort(array_cp, size);
	i = 0;
	while (i < size)
	{
		coordinate[i] = lower_bound(array_cp, array[i], size);
		i++;
	}
	return ;
}

void	sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				swap(array + i, array + j);
			j++;
		}
		i++;
	}
	return ;
}

static size_t	lower_bound(int	*array, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (value <= array[i])
			return (i);
		i++;
	}
	return (size - 1);
}
