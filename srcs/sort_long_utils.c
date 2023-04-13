/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/13 23:04:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

// stack_size(stack1)の下位1/3を残し、残りをstack2に移動する
// この時、中位1/3はpb後にrbを実行する
void	set_stack(t_list *stack1, t_list *stack2, t_info *info)
{
	ssize_t	pivot;
	ssize_t	remain;

	// 300だったら100, 200、 400だったら134, 266、 500だったら167, 333
	// つまりpivotは3で割って切り上げ
	remain = (stack_size(stack1) + 2) / 3;
	pivot = stack_size(stack1) - remain;
	while ((ssize_t)stack_size(stack1) > remain)
	{
		if (!is_bottom(stack1->next, pivot))
		{
			record_command(stack1, stack2, info, PB);
			if (is_top(stack2->next, pivot) && is_bottom(stack1->next, pivot))
				record_command(stack1, stack2, info, RR);
			else if (is_top(stack2->next, pivot))
				record_command(NULL, stack2, info, RB);
		}
		else
			record_command(stack1, NULL, info, RA);
	}
}

t_list	*find_min_more_than_pivot(t_list *stack, ssize_t pivot)
{
	t_list	*min;

	min = find_max(stack);
	while (stack->next->ordinal != -1)
	{
		if (min->ordinal > stack->next->ordinal && stack->next->ordinal >= pivot)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}

t_list	*find_max_less_than_pivot(t_list *stack, ssize_t pivot)
{
	t_list	*max;

	max = stack;
	while (stack->next->ordinal != -1)
	{
		if (max->ordinal < stack->next->ordinal && stack->next->ordinal < pivot)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

void	stack_middle_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	long	step;
	size_t	pivot;

	pivot = (stack_size(stack2) + 1) / 2;
	while (stack_size(stack2) > pivot)
	{
		min = find_min_more_than_pivot(stack2, pivot);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B', info);
			record_command(stack1, stack2, info, PA);
			record_command(stack1, NULL, info, RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B', info);
			record_command(stack1, stack2, info, PA);
		}
	}
	step = cal_steps(stack1, find_min(stack1));
	rotate_min_steps(stack1, step, 'A', info);
}

void	stack_top_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	long	step;

	while ((ssize_t)stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B', info);
			record_command(stack1, stack2, info, PA);
			record_command(stack1, NULL, info, RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B', info);
			record_command(stack1, stack2, info, PA);
		}
	}
	step = cal_steps(stack1, find_min(stack1));
	rotate_min_steps(stack1, step, 'A', info);
}
