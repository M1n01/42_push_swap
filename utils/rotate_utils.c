/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:33 by minabe            #+#    #+#             */
/*   Updated: 2023/04/13 14:59:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	rotate_min_steps(t_list *stack, long step, int which_stack, t_info *info)
{
	if (step >= 0)
	{
		while (step > 0)
		{
			if (which_stack == 'A')
			{
				record_command(stack, NULL, info, RA);
				// command(stack, NULL, RA);
				// info->ans = add_ans(info, RA);
			}
			else if (which_stack == 'B')
			{
				record_command(NULL, stack, info, RB);
				// command(NULL, stack, RB);
				// info->ans = add_ans(info, RB);
			}
			step--;
		}
	}
	else
	{
		while (step < 0)
		{
			if (which_stack == 'A')
			{
				record_command(stack, NULL, info, RRA);
				// command(stack, NULL, RRA);
				// info->ans = add_ans(info, RRA);
			}
			else if (which_stack == 'B')
			{
				record_command(NULL, stack, info, RRB);
				// command(NULL, stack, RRB);
				// info->ans = add_ans(info, RRB);
			}
			step++;
		}
	}
}

void	ra(t_list *stack1, t_list *stack2, ssize_t p)
{
	// stack2の先頭がpivot/2より大きい場合、rrを実行
	if (stack2->next->ordinal != -1 && stack2->next->ordinal <= p)
	{
		// printf("p: %ld\n", stack2->next->ordinal);
		command(stack1, stack2, RR);
		// execute_and_print(stack1, stack2, RR);
	}
	else
	{
		command(stack1, NULL, RA);
		// execute_and_print(stack1, NULL, RA);
	}
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
