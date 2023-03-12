/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/03/11 15:17:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	command1(t_list *stack, int cmd)
{
	if ((cmd == SA || cmd == SB) && stack_size(stack) > 1)
	{
		swap(stack);
		return (true);
	}
	if ((cmd == RA || cmd == RB) && stack_size(stack) > 1)
	{
		rotate(stack);
		return (true);
	}
	if ((cmd == RRA || cmd == RRB) && stack_size(stack) > 1)
	{
		rev_rotate(stack);
		return (true);
	}
	return (false);
}

bool	command2(t_list *stack1, t_list *stack2, int cmd)
{
	if (cmd == SS && stack_size(stack1) > 1 && stack_size(stack2) > 1)
	{
		swap(stack1);
		swap(stack2);
		return (true);
	}
	if (cmd == RR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
	{
		rotate(stack1);
		rotate(stack2);
		return (true);
	}
	if (cmd == RRR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
	{
		rev_rotate(stack1);
		rev_rotate(stack2);
		return (true);
	}
	if (cmd == PA && stack_size(stack2) > 0)
	{
		push(stack2, stack1);
		return (true);
	}
	if (cmd == PB && stack_size(stack1) > 0)
	{
		push(stack1, stack2);
		return (true);
	}
	return (false);
}

void	print_command(int cmd)
{
	if (cmd == SA)
		ft_printf("sa\n");
	if (cmd == SB)
		ft_printf("sb\n");
	if (cmd == SS)
		ft_printf("ss\n");
	if (cmd == RA)
		ft_printf("ra\n");
	if (cmd == RB)
		ft_printf("rb\n");
	if (cmd == RR)
		ft_printf("rr\n");
	if (cmd == RRA)
		ft_printf("rra\n");
	if (cmd == RRB)
		ft_printf("rrb\n");
	if (cmd == RRR)
		ft_printf("rrr\n");
	if (cmd == PA)
		ft_printf("pa\n");
	if (cmd == PB)
		ft_printf("pb\n");
}
