/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/03/08 12:30:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

bool	command1(t_list *stack, int command)
{
	if ((command == SA && stack->next->ordinal < stack->next->next->ordinal) || (command == SB && stack->next->ordinal < stack->next->next->ordinal))
	{
		if (swap(stack))
		{
			// print_command(command);
			return (true);
		}
	}
	if (command == RA || command == RB)
	{
		if (rotate(stack))
		{
			// print_command(command);
			return (true);
		}
	}
	else if (command == RRA || command == RRB)
	{
		if (rev_rotate(stack))
		{
			// print_command(command);
			return (true);
		}
	}
	return (false);
}

bool	command2(t_list *stackA, t_list *stackB, int command)
{
	if (command == SS)
	{
		if (swap(stackA), swap(stackB))
		{
			// print_command(command);
			return (true);
		}
	}
	if (command == RR)
	{
		if (rotate(stackA), rotate(stackB))
		{
			// print_command(command);
			return (true);
		}
	}
	if (command == RRR)
	{
		if (rev_rotate(stackA), rev_rotate(stackB))
		{
			// print_command(command);
			return (true);
		}
	}
	if (command == PA)
	{
		if (push(stackB, stackA))
		{
			// print_command(command);
			return (true);
		}
	}
	if (command == PB)
	{
		if (push(stackA, stackB))
		{
			// print_command(command);
			return (true);
		}
	}
	return (false);
}

void	print_command(int command)
{
	if (command == SA)
		ft_printf("sa\n");
	if (command == SB)
		ft_printf("sb\n");
	if (command == SS)
		ft_printf("ss\n");
	if (command == RA)
		ft_printf("ra\n");
	if (command == RB)
		ft_printf("rb\n");
	if (command == RR)
		ft_printf("rr\n");
	if (command == RRA)
		ft_printf("rra\n");
	if (command == RRB)
		ft_printf("rrb\n");
	if (command == RRR)
		ft_printf("rrr\n");
	if (command == PA)
		ft_printf("pa\n");
	if (command == PB)
		ft_printf("pb\n");
}
