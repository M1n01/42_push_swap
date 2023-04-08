/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:48:19 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 12:29:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	sort1(t_list *stack1, t_list *stack2)
{
	ssize_t	pivot;
	t_list	*min;
	t_list	*max;
	long	step;

	pivot = (stack_size(stack2) + 1) / 2;
	// 上位のソート
	while ((ssize_t)stack_size(stack2) >= pivot)
	{
		if (stack2->next->ordinal > stack2->next->next->ordinal)
			opt_swap(stack1, stack2, SB);
		min = find_min(stack2);
		step = cal_steps(stack2, min);
		if (step > 0)
		{
			while (step--)
			{
				rotate(stack2);
				print_command(RB);
			}
		}
		else
		{
			while (step++)
			{
				rev_rotate(stack2);
				print_command(RRB);
			}
		}
		push(stack2, stack1);
		print_command(PA);
		rotate(stack1);
		print_command(RA);
	}
	// 中位のソート
	while (stack_size(stack2) > 0)
	{
		min = find_min(stack2);
		max = find_max(stack2);
		if (ABS(cal_steps(stack2, min)) <= ABS(cal_steps(stack2, max)))
		{
			step = cal_steps(stack2, min);
			if (step > 0)
			{
				while (step--)
				{
					rotate(stack2);
					print_command(RB);
				}
			}
			else
			{
				while (step++)
				{
					rev_rotate(stack2);
					print_command(RRB);
				}
			}
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
		else
		{
			step = cal_steps(stack2, max);
			if (step > 0)
			{
				while (step--)
				{
					rotate(stack2);
					print_command(RB);
				}
			}
			else
			{
				while (step++)
				{
					rev_rotate(stack2);
					print_command(RRB);
				}
			}
			push(stack2, stack1);
			print_command(PA);
		}
	}
	while (stack1->next->ordinal <= (ssize_t)(stack_size(stack1) / 3) * 2)
	{
		rotate(stack1);
		print_command(RA);
	}
	// 下位のソート
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
		if (step > 0)
		{
			while (step--)
			{
				rotate(stack2);
				print_command(RB);
			}
		}
		else
		{
			while (step++)
			{
				rev_rotate(stack2);
				print_command(RRB);
			}
		}
		push(stack2, stack1);
		print_command(PA);
		rotate(stack1);
		print_command(RA);
	}
		return ;
}
