/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:33 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 12:59:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	rotate_min_steps(t_list *stack, long step, int which_stack)
{
	if (step >= 0)
	{
		while (step > 0)
		{
			rotate(stack);
			if (which_stack == 'A')
				print_command(RA);
			else if (which_stack == 'B')
				print_command(RB);
			step--;
		}
	}
	else
	{
		while (step < 0)
		{
			rev_rotate(stack);
			if (which_stack == 'A')
				print_command(RRA);
			else if (which_stack == 'B')
				print_command(RRB);
			step++;
		}
	}
}

long	cal_min_steps_to_pivot(t_list *stack, ssize_t pivot)
{
	long	min_step;
	ssize_t	i;
	t_list	*find;

	// pivot以下の値が先頭に来るまでに最短で何手か計算する
	min_step = LONG_MAX;
	i = 0;
	while (i <= pivot)
	{
		if (min_step == 0)
			break ;
		find = search_ordinal(stack, i);
		if (find == NULL)
		{
			i++;
			continue ;
		}
		// printf("value: %ld\n", i);
		if (min_step > ABS(cal_steps(stack, find)))
			min_step = cal_steps(stack, find);
		// printf("min_step: %ld\n", min_step);
		i++;
	}
	return (min_step);
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
