/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 13:02:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

int	ch_cmd(int cmd)
{
	if (cmd == PA)
		return (PB);
	if (cmd == PB)
		return (PA);
	if (cmd == RA)
		return (RRA);
	if (cmd == RB)
		return (RRB);
	if (cmd == RR)
		return (RRR);
	if (cmd == RRA)
		return (RA);
	if (cmd == RRB)
		return (RB);
	if (cmd == RRR)
		return (RR);
	return (cmd);
}

bool	exec_cmd(t_list *stack1, t_list *stack2, int cmd)
{
	if (cmd == SA || cmd == RA || cmd == RRA)
		return (command1(stack1, cmd));
	if (cmd == SB || cmd == RB || cmd == RRB)
		return (command1(stack2, cmd));
	else
		return (command2(stack1, stack2, cmd));
}

bool	command1(t_list *stack, int cmd)
{
	if (stack_size(stack) <= 1)
		return (false);
	if (cmd == SA || cmd == SB)
		return (swap(stack), true);
	if (cmd == RA || cmd == RB)
		return(rotate(stack), true);
	if (cmd == RRA || cmd == RRB)
		return (rev_rotate(stack), true);
	return (false);
}

bool	command2(t_list *stack1, t_list *stack2, int cmd)
{
	if (cmd == SS && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (swap(stack1), swap(stack2), true);
	if (cmd == RR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (rotate(stack1), rotate(stack2), true);
	if (cmd == RRR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (rev_rotate(stack1), rev_rotate(stack2), true);
	if (cmd == PA && stack_size(stack2) > 0)
		return (push(stack2, stack1), true);
	if (cmd == PB && stack_size(stack1) > 0)
		return (push(stack1, stack2), true);
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
