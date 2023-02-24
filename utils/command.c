/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/02/24 16:58:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	print_command(int command);

void	command1(t_list *stack, int command)
{
	if (command == SA || command == SB)
	{
		swap(stack);
		print_command(command);
	}
	if (command == RA || command == RB)
	{
		rotate(stack);
		print_command(command);
	}
	else if (command == RRA || command == RRB)
	{
		rev_rotate(stack);
		print_command(command);
	}
	else
		printf("Nothing\n");
}

void	command2(t_list *stackA, t_list *stackB, int command)
{
	if (command == SS)
	{
		swap(stackA);
		swap(stackB);
		print_command(command);
	}
	if (command == RR)
	{
		rotate(stackA);
		rotate(stackB);
		print_command(command);
	}
	if (command == RRR)
	{
		rev_rotate(stackA);
		rev_rotate(stackB);
		print_command(command);
	}
	if (command == PA|| command == PB)
	{
		push(stackA, stackB);
		print_command(command);
	}
	else
		printf("Nothing\n");
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
