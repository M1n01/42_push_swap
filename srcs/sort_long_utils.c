/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/14 00:19:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	find_max_and_pa(t_list *stack1, t_list *stack2, t_info *info)
{
	t_list	*max;
	long	step;

	max = find_max(stack1);
	step = cal_steps(stack2, max);
	rotate_min_steps(stack2, step, 'B', info);
	record_command(stack1, stack2, info, PA);
}
