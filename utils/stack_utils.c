/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:50:21 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 12:51:29 by minabe           ###   ########.fr       */
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

bool	is_sorted(t_list *stack, int order)
{
	while (stack->next->ordinal != -1)
	{
		if (order == ASC && stack->ordinal > stack->next->ordinal)
			return (false);
		if (order == DESC && stack->ordinal < stack->next->ordinal)
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

ssize_t	count_rev_rotate(t_list *stack, t_list *find)
{
	size_t	step;

	if (find == NULL)
		return (-1);
	step = 0;
	while (stack != find)
	{
		stack = stack->prev;
		step++;
	}
	return (step);
}

long	cal_steps(t_list *stack, t_list *find)
{
	long	rotate;
	long	rev_rotate;

	rotate = count_rotate(stack, find);
	rev_rotate = count_rev_rotate(stack, find);
	// printf("rotate: %ld, rev_rotate: %ld\n", rotate, rev_rotate);
	if (rotate <= rev_rotate)
		return (rotate);
	else
		return (-rev_rotate);
}
