/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 13:17:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

// stack_size(stack1)の下位1/3を残し、残りをstack2に移動する
// この時、中位1/3はpb後にrbを実行する
void	set_stack(t_list *stack1, t_list *stack2)
{
	ssize_t	pivot;
	ssize_t	remain;

	// 300だったら100, 200、 400だったら134, 266、 500だったら167, 333
	// つまりpivotは3で割って切り上げ
	remain = (stack_size(stack1) + 2) / 3;
	pivot = stack_size(stack1) - remain;
	while ((ssize_t)stack_size(stack1) > remain)
	{
		if (stack1->next->ordinal < pivot)
		{
			push(stack1, stack2);
			print_command(PB);
			if (stack2->next->ordinal > (pivot - 1) / 2)
			{
				rotate(stack2);
				print_command(RB);
			}
		}
		else
		{
			rotate(stack1);
			print_command(RA);
		}
	}
}

void	stack_top_third_sort(t_list *stack1, t_list *stack2)
{
	ssize_t	pivot;
	t_list	*min;
	long	step;

	pivot = (stack_size(stack2) + 1) / 2;
	while ((ssize_t)stack_size(stack2) >= pivot)
	{
		if (stack2->next->ordinal > stack2->next->next->ordinal)
			opt_swap(stack1, stack2, SB);
		min = find_min(stack2);
		step = cal_steps(stack2, min);
		rotate_min_steps(stack2, step, 'B');
		push(stack2, stack1);
		print_command(PA);
		rotate(stack1);
		print_command(RA);
	}
}

void	stack_middle_third_sort(t_list *stack1, t_list *stack2)
{
	t_list	*min;
	t_list	*max;
	long	step;

	while (stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B');
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B');
			push(stack2, stack1);
			print_command(PA);
		}
	}
	while (stack1->next->ordinal <= (ssize_t)(stack_size(stack1) / 3) * 2)
	{
		rotate(stack1);
		print_command(RA);
	}
}

void	stack_bottom_third_sort(t_list *stack1, t_list *stack2)
{
	t_list	*min;
	// t_list	*max;
	long	step;

	// stack_size(stack1)/3 * 2よりも大きいordinalをstack2に移動
	while (stack1->next->ordinal > (ssize_t)(stack_size(stack1) / 3) * 2)
	{
		// min = search_ordinal(stack1, (ssize_t)(stack_size(stack1) / 3) * 2 + 1);
		// if (min == stack1->next)
		// {
		// 	rotate(stack1);
		// 	print_command(RA);
		// 	puts("[if]");
		// 	printLists(stack1, stack2);
		// 	continue ;
		// }
		push(stack1, stack2);
		print_command(PB);
	}
	while ((ssize_t)stack_size(stack2) > 0)
	{
		if (stack2->next->ordinal > stack2->next->next->ordinal)
		{
			swap(stack2);
			print_command(SB);
		}
		min = find_min(stack2);
		step = cal_steps(stack2, min);
		rotate_min_steps(stack2, step, 'B');
		push(stack2, stack1);
		print_command(PA);
		rotate(stack1);
		print_command(RA);
	}
		return ;
}
