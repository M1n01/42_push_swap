/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/05 12:39:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	set_stack(t_list *stack1, t_list *stack2, size_t pivot);

void	sort1(t_list *stack1, t_list *stack2)
{
	t_list	*min;
	t_list	*max;
	long	step;

	while (stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		// stack2の中で一番大きい値をstack1の先頭に持ってくる
		// cal_stepsを使う
		if (cal_steps(stack2, max) <= cal_steps(stack2, min))
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step);
			push(stack2, stack1);
			print_command(PA);
		}
		else
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step);
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
	}
	return ;
}

t_list	*find_not_sorted(t_list *stack)
{
	while (stack->next->ordinal != -1)
	{
		if (ABS(stack->ordinal - stack->prev->ordinal) > 3\
		&& ABS(stack->ordinal - stack->next->ordinal) > 3)
			return (stack->next);
		stack = stack->next;
	}
	return (NULL);
}

void	sort2(t_list *stack1, t_list *stack2)
{
	long	step;
	t_list	*max;
	t_list	*min;

	while (!is_sorted(stack1, ASC))
	{
		if (find_not_sorted(stack1) != NULL)
		{
			step = cal_steps(stack1, find_not_sorted(stack1));
			rotate_min_steps(stack1, step);
			push(stack1, stack2);
			print_command(PB);
		}
	}
	// stack2の中身をstack1に戻す
	while (stack_size(stack2) > 0)
	{
		max = find_max(stack2);
		min = find_min(stack2);
		// stack2の中で一番大きい値をstack1の先頭に持ってくる
		// cal_stepsを使う
		if (cal_steps(stack2, max) <= cal_steps(stack2, min))
		{
			step = cal_steps(stack2, max);
			rotate_min_steps(stack2, step);
			push(stack2, stack1);
			print_command(PA);
		}
		else
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step);
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
	}
	return ;
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	size_t	i;

	i = 1;
	while (i <= 1)
	{
		// printLists(stack1, stack2);
		set_stack(stack1, stack2, (stack_size(stack1) / 2) - 1);
		// printLists(stack1, stack2);
		sort1(stack1, stack2);
		// printLists(stack1, stack2);
		sort2(stack1, stack2);
		// printLists(stack1, stack2);
		i++;
	}
	while (stack1->next->ordinal != 0)
	{
		rotate(stack1);
		print_command(RA);
	}
	return ;
}

void	ra(t_list *stack1, t_list *stack2, ssize_t p)
{
	// stack2の先頭がpivot/2より大きい場合、rrを実行
	if (stack2->next->ordinal != -1 && stack2->next->ordinal <= p)
	{
		// printf("p: %ld\n", stack2->next->ordinal);
		rotate(stack1);
		rotate(stack2);
		print_command(RR);
	}
	else
	{
		rotate(stack1);
		print_command(RA);
	}
}

static void	set_stack(t_list *stack1, t_list *stack2, size_t pivot)
{
	size_t	i;
	long	step;

	// printf("pivot: %ld\n", pivot);
	i = 0;
	while (i < pivot)
	{
		// pivot以下の値をstack2に移動
		step = cal_min_steps_to_pivot(stack1, pivot);
		// printf("[step]: %ld\n", step);
		if (step >= 0)
		{
			// あとでrrもできる関数に変更
			while (step > 0)
			{
				ra(stack1, stack2, pivot / 2);
				step--;
			}
		}
		else
		{
			while (step < 0)
			{
				rev_rotate(stack1);
				print_command(RRA);
				step++;
			}
		}
		push(stack1, stack2);
		print_command(PB);
		// printLists(stack1, stack2);
		i++;
	}
}
