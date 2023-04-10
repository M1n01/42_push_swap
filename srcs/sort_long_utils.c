/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/10 18:19:29 by minabe           ###   ########.fr       */
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
		if (!is_bottom(stack1->next, pivot))
		{
			execute_and_print(stack1, stack2, PB);
			if (is_middle(stack2->next, pivot) && is_bottom(stack1->next, pivot))
				execute_and_print(stack1, stack2, RR);
			else if (is_middle(stack2->next, pivot))
				execute_and_print(NULL, stack2, RB);
		}
		else
			execute_and_print(stack1, NULL, RA);
	}
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

void	stack_top_third_sort(t_list *stack1, t_list *stack2)
{
	ssize_t	pivot;
	t_list	*min;
	t_list	*max;
	long	step;
	size_t	rotate;

	pivot = (stack_size(stack2) + 1) / 2;
	rotate = 0;
	while ((ssize_t)stack_size(stack2) >= pivot)
	{
		if (stack2->next->ordinal > stack2->next->next->ordinal)
			opt_swap(stack1, stack2, SB);
		min = find_min(stack2);
		max = find_pivot_max(stack2, pivot);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B');
			execute_and_print(stack1, stack2, PA);
			execute_and_print(stack1, stack2, RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B');
			execute_and_print(stack1, stack2, PA);
			rotate++;
		}
	}
	while (rotate-- > 0)
		execute_and_print(stack1, NULL, RA);
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
			execute_and_print(stack1, stack2, PA);
			execute_and_print(stack1, stack2, RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step, 'B');
			execute_and_print(stack1, stack2, PA);
		}
	}
	while (stack1->next->ordinal <= (ssize_t)(stack_size(stack1) / 3) * 2)
	{
		execute_and_print(stack1, stack2, RA);
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
		execute_and_print(stack1, stack2, PB);
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
		execute_and_print(stack1, stack2, PA);
		execute_and_print(stack1, stack2, RA);
	}
		return ;
}

void	execute_and_print(t_list *stack1, t_list *stack2, int command)
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
	print_command(command);
}
