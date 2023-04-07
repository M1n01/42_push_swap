/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/06 14:16:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	max = stack->next;
	while (stack->next->ordinal != -1)
	{
		if (max->ordinal < stack->next->ordinal)
			max = stack->next;
		stack = stack->next;
	}
	// printf("max: %ld\n", max->ordinal);
	return (max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;

	min = stack->next;
	while (stack->next->ordinal != -1)
	{
		if (min->ordinal > stack->next->ordinal)
			min = stack->next;
		stack = stack->next;
	}
	// printf("min: %ld\n", min->ordinal);
	return (min);
}

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
