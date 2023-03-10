/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/03/10 17:51:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	command1(t_list *stack, int cmd)
{
	if ((cmd == SA || cmd == SB) && is_swap(stack, NULL, cmd))
	{
		swap(stack);
		return (true);
	}
	if ((cmd == RA || cmd == RB) && is_rotate(stack, NULL, cmd))
	{
		rotate(stack);
		return (true);
	}
	if ((cmd == RRA || cmd == RRB) && is_revrotate(stack, NULL, cmd))
	{
		rev_rotate(stack);
		return (true);
	}
	return (false);
}

bool	command2(t_list *stack1, t_list *stack2, int cmd)
{
	// puts("Hello");
	if (cmd == SS && is_swap(stack1, stack2, cmd))
	{
		// puts("ss");
		swap(stack1);
		swap(stack2);
		return (true);
	}
	if (cmd == RR && is_rotate(stack1, stack2, cmd))
	{
		// puts("rr");
		rotate(stack1);
		rotate(stack2);
		return (true);
	}
	if (cmd == RRR && is_revrotate(stack1, stack2, cmd))
	{
		// puts("rrr");
		rev_rotate(stack1);
		rev_rotate(stack2);
		return (true);
	}
	if (cmd == PA && is_push(stack2, cmd))
	{
		// puts("pa");
		push(stack2, stack1);
		return (true);
	}
	if (cmd == PB && is_push(stack1, cmd))
	{
		// puts("pb");
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
