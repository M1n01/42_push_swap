/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:21:35 by minabe            #+#    #+#             */
/*   Updated: 2023/04/13 20:34:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	stack_bottom_third_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*min;
	t_list	*max;
	long	step;
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
		step = cal_steps(stack2, max);
		rotate_min_steps(stack2, step, 'B', info);
		record_command(stack1, stack2, info, PA);
	}
	pivot = find_min(stack1)->ordinal + 1;
	while (stack_size(stack1) < size)
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
	return ;
}