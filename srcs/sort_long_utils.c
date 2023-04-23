/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/23 23:32:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	find_ordinal_and_pa(t_list *stack1, t_list *stack2, t_info *info, ssize_t value)
{
	long	step;

	step = cal_steps(stack2, find_ordinal(stack2, value));
	rotate_min_steps(stack2, step, 'B', info);
	record_command(stack1, stack2, info, PA);
}

void	find_ordinal_and_pb(t_list *stack1, t_list *stack2, t_info *info, ssize_t value)
{
	long	step;

	step = cal_steps(stack1, find_ordinal(stack1, value));
	rotate_min_steps(stack1, step, 'A', info);
	record_command(stack1, stack2, info, PB);
}

void	find_max_and_pa(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*max;
	long	step;

	max = find_max(stack2);
	step = cal_steps(stack2, max);
	rotate_min_steps(stack2, step, 'B', info);
	record_command(stack1, stack2, info, PA);
}

void	find_min_and_pb(t_list *stack1, t_list *stack2, t_info *info)
{
	long	step;

	step = cal_steps(stack1, find_min(stack1));
	rotate_min_steps(stack1, step, 'A', info);
	record_command(stack1, stack2, info, PB);
}
