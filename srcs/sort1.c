/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:48:19 by minabe            #+#    #+#             */
/*   Updated: 2023/04/06 14:02:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

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
			rotate_min_steps(stack2, step, 'B');
			push(stack2, stack1);
			print_command(PA);
		}
		else
		{
			step = cal_steps(stack2, min);
			rotate_min_steps(stack2, step, 'B');
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
	}
	return ;
}