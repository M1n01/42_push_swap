/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:50:21 by minabe            #+#    #+#             */
/*   Updated: 2023/04/03 12:52:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

size_t	stack_size(t_list *stack)
{
	size_t	len;

	len = 0;
	while (stack->next->ordinal != -1)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

bool	is_sorted(t_list *stack)
{
	while (stack->next->ordinal != -1)
	{
		if (stack->ordinal > stack->next->ordinal)
			return (false);
		stack = stack->next;
	}
	return (true);
}

ssize_t	count_rotate(t_list *stack, t_list *find)
{
	size_t	step;

	if (find == NULL)
		return (-1);
	step = 0;
	while (stack->next != find)
	{
		stack = stack->next;
		step++;
	}
	return (step);
}

t_list	*search_ordinal(t_list *stack, ssize_t value)
{
	while (stack->next->ordinal != -1)
	{
		if (stack->ordinal == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

long	cal_steps(t_list *stack, t_list *find)
{
	long	rotate;
	long	rev_rotate;
	long	min_step;

	min_step = LONG_MAX;
	rotate = count_rotate(stack, find);
	rev_rotate = (stack_size(stack) - rotate);
	if (rotate <= rev_rotate && rotate <= ABS(min_step))
		min_step = rotate;
	else if (rev_rotate <= rotate && rev_rotate <= ABS(min_step))
		min_step = -rev_rotate;
	return (min_step);
}

long	cal_min_steps_to_pivot(t_list *stack, ssize_t pivot)
{
	long	min_step;
	ssize_t	i;
	t_list	*find;

	// pivot以下の値が先頭に来るまでに最短で何手か計算する
	i = 0;
	while (i < pivot)
	{
		if (min_step == 0)
			break ;
		find = search_ordinal(stack, i);
		if (find == NULL)
		{
			i++;
			continue ;
		}
		min_step = cal_steps(stack, find);
		i++;
	}
	return (min_step);
}
