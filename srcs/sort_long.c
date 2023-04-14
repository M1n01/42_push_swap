/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/14 11:48:53 by minabe           ###   ########.fr       */
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

void	stack_bottom_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	size_t	size;
	ssize_t	pivot;

	size = (stack_size(stack1));
	// minとmaxを残し、残りをstack2に移動する
	// このとき、1/2以下はpush後にrotateする
	while (stack_size(stack1) > 2)
	{
		min = find_min(stack1);
		max = find_max(stack1);
		if (stack1->next == min || stack1->next == max)
			record_command(stack1, NULL, info, RA);
		else
		{
			record_command(stack1, stack2, info, PB);
			if (stack2->next->ordinal < (max->ordinal + min->ordinal) / 2)
				record_command(NULL, stack2, info, RB);
		}
	}
	if (stack1->next != max)
		record_command(stack1, NULL, info, SA);
	// bottomを2分割した
	// まずbottomのbottomをソートする
	while (stack_size(stack1) < size / 2)
	{
		max = find_max(stack2);
		rotate_min_steps(stack2, cal_steps(stack2, max), 'B', info);
		record_command(stack1, stack2, info, PA);
	}
	pivot = find_min(stack1)->ordinal + 1;
	while (stack_size(stack1) < size)
	{
		min = find_min_more_than_pivot(stack2, pivot);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			rotate_min_steps(stack2, cal_steps(stack2, min), 'B', info);
			record_command(stack1, stack2, info, PA);
			record_command(stack1, NULL, info, RA);
		}
		else
		{
			rotate_min_steps(stack2, cal_steps(stack2, max), 'B', info);
			record_command(stack1, stack2, info, PA);
		}
	}
	rotate_min_steps(stack1, cal_steps(stack1, find_min(stack1)), 'A', info);
}

void	stack_middle_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	size_t	pivot;

	pivot = (stack_size(stack2) + 1) / 2;
	while (stack_size(stack2) > pivot)
	{
		min = find_min_more_than_pivot(stack2, pivot);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			rotate_min_steps(stack2, cal_steps(stack2, min), 'B', info);
			record_command(stack1, stack2, info, PA);
			record_command(stack1, NULL, info, RA);
		}
		else
		{
			rotate_min_steps(stack2, cal_steps(stack2, max), 'B', info);
			record_command(stack1, stack2, info, PA);
		}
	}
	rotate_min_steps(stack1, cal_steps(stack1, find_min(stack1)), 'A', info);
}

void	stack_top_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;

	while ((ssize_t)stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			rotate_min_steps(stack2, cal_steps(stack2, min), 'B', info);
			record_command(stack1, stack2, info, PA);
			record_command(stack1, NULL, info, RA);
		}
		else
		{
			rotate_min_steps(stack2, cal_steps(stack2, max), 'B', info);
			record_command(stack1, stack2, info, PA);
		}
	}
	rotate_min_steps(stack1, cal_steps(stack1, find_min(stack1)), 'A', info);
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	t_info	*info;

	info = init_info_long_ver();
	// printLists(stack1, stack2);
	set_stack(stack1, stack2, info);
	// printLists(stack1, stack2);
	stack_bottom_third_sort(stack1, stack2, info);
	stack_middle_third_sort(stack1, stack2, info);
	stack_top_third_sort(stack1, stack2, info);
	ans_optimize(info);
	print_ans(info);
	free_info(info);
	// printLists(stack1, stack2);
	return ;
}
