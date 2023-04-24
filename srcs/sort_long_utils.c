/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:13:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	find_val_and_pb(t_list *s1, t_list *s2, t_info *info, ssize_t val)
{
	long	step;

	step = cal_steps(s1, find_ordinal(s1, val));
	rotate_min_steps(s1, step, 'A', info);
	record_command(s1, s2, info, PB);
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

void	pb_and_split_half(t_list *s1, t_list *s2, t_info *info, ssize_t piv)
{
	record_command(s1, s2, info, PB);
	if (s2->next->ordinal < piv)
		record_command(s1, s2, info, RB);
}

void	pa_and_split_half(t_list *s1, t_list *s2, t_info *info, ssize_t piv)
{
	record_command(s1, s2, info, PA);
	if (s1->next->ordinal >= piv)
		record_command(s1, s2, info, RA);
}
