/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:40:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:17:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

static void	sep_into_three(t_list *s1, t_list *s2, t_info *info, size_t size)
{
	ssize_t	max;
	ssize_t	pivot1;
	ssize_t	pivot2;
	size_t	push_size;

	max = find_max(s2)->ordinal;
	pivot1 = max + 1 - size * 2 / 3;
	pivot2 = max + 1;
	push_size = 0;
	while (push_size < size * 2 / 3)
	{
		if (pivot1 <= s2->next->ordinal && s2->next->ordinal < pivot2)
		{
			pa_and_split_half(s1, s2, info, (pivot1 + pivot2) / 2);
			push_size++;
		}
		else
			record_command(s1, s2, info, RB);
	}
}

void	middle_sort(t_list *stack1, t_list *stack2, t_info *info, size_t size)
{
	ssize_t	max;
	ssize_t	pivot1;
	ssize_t	pivot2;
	size_t	push_size;
	ssize_t	i;

	max = find_max(stack2)->ordinal;
	pivot1 = max + 1 - size * 2 / 3;
	pivot2 = max + 1;
	sep_into_three(stack1, stack2, info, size);
	i = pivot1;
	while (i < pivot2)
	{
		find_val_and_pb(stack1, stack2, info, i);
		i++;
	}
	push_size = 0;
	while (push_size < size)
	{
		find_max_and_pa(stack1, stack2, info);
		push_size++;
	}
}
