/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/12 15:11:02 by minabe           ###   ########.fr       */
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
			command(stack1, stack2, PB);
			info->ans = upgrade_ans(info, PB);
			if (is_top(stack2->next, pivot) && is_bottom(stack1->next, pivot))
			{
				command(stack1, stack2, RR);
				info->ans = upgrade_ans(info, RR);
			}
			else if (is_top(stack2->next, pivot))
			{
				command(NULL, stack2, RB);
				info->ans = upgrade_ans(info, RB);
			}
		}
		else
		{
			command(stack1, NULL, RA);
			info->ans = upgrade_ans(info, RA);
		}
	}
}

t_list	*find_pivot_min(t_list *stack, ssize_t pivot)
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

t_list	*find_pivot_max(t_list *stack, ssize_t pivot)
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

void	stack_top_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	size_t	rotate;
	t_list	*max;
	long	step;

	rotate = 0;
	while ((ssize_t)stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B', info);
			command(stack1, stack2, PA);
			info->ans = upgrade_ans(info, PA);
			command(stack1, stack2, RA);
			info->ans = upgrade_ans(info, RA);
			rotate++;
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B', info);
			command(stack1, stack2, PA);
			info->ans = upgrade_ans(info, PA);
		}
	}
	while (rotate-- > 0)
	{
		command(stack1, NULL, RRA);
		info->ans = upgrade_ans(info, RRA);
	}
}

void	stack_middle_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	long	step;
	size_t	pivot;
	size_t	rotate;

	rotate = 0;
	pivot = (stack_size(stack2) + 1) / 2;
	while (stack_size(stack2) > pivot)
	{
		min = find_pivot_min(stack2, pivot);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B', info);
			command(stack1, stack2, PA);
			info->ans = upgrade_ans(info, PA);
			command(stack1, stack2, RA);
			info->ans = upgrade_ans(info, RA);
			rotate++;
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B', info);
			command(stack1, stack2, PA);
			info->ans = upgrade_ans(info, PA);
		}
	}
	while (rotate-- > 0)
	{
		command(stack1, NULL, RRA);
		info->ans = upgrade_ans(info, RRA);
	}
}

void	stack_bottom_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	long	step;
	size_t	remain;

	while (stack_size(stack1) > 0)
	{
		min = find_min(stack1);
		max = find_max(stack1);
		if (ABS(cal_steps(stack1, min)) <= ABS(cal_steps(stack1, max)))
		{
			step = cal_steps(stack1, min);
			rotate_min_steps(stack1, step, 'A', info);
			command(stack1, stack2, PB);
			info->ans = upgrade_ans(info, PB);
		}
		else
		{
			step = cal_steps(stack1, max);
			rotate_min_steps(stack1, step, 'A', info);
			command(stack1, stack2, PB);
			info->ans = upgrade_ans(info, PB);
			command(stack1, stack2, RB);
			info->ans = upgrade_ans(info, RB);
		}
	}
	remain = (stack_size(stack2) + 2) / 3;
	while (stack_size(stack1) < remain)
	{
		max = find_max(stack2);
		step = cal_steps(stack2, max);
		rotate_min_steps(stack2, step, 'B', info);
		command(stack1, stack2, PA);
		info->ans = upgrade_ans(info, PA);
	}
	return ;
}

void	command(t_list *stack1, t_list *stack2, int command)
{
	if (command == SA || command == SS)
		swap(stack1);
	if (command == SB || command == SS)
		swap(stack2);
	if (command == PA)
		push(stack2, stack1);
	if (command == PB)
		push(stack1, stack2);
	if (command == RA || command == RR)
		rotate(stack1);
	if (command == RB || command == RR)
		rotate(stack2);
	if (command == RRA || command == RRR)
		rev_rotate(stack1);
	if (command == RRB || command == RRR)
		rev_rotate(stack2);
	// print_command(command);
}
