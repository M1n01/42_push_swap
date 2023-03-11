/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:33 by minabe            #+#    #+#             */
/*   Updated: 2023/03/11 11:59:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	is_swap(t_list *stack, t_list *stack2, int cmd)
{
	// puts("Hey");
	if (stack_size(stack) <= 1)
		return (false);
	if (cmd == SA && stack->next->ordinal < stack->next->next->ordinal)
		return (true);
	if (cmd == SB && stack->next->ordinal > stack->next->next->ordinal)
		return (true);
	if (cmd == SS && stack_size(stack2) > 1 && stack->next->ordinal < stack->next->next->ordinal && stack2->next->ordinal > stack2->next->next->ordinal)
		return (true);
	return (false);
}

bool	is_rotate(t_list *stack, t_list *stack2, int cmd)
{
	// 要素が1つ以下のときreturn
	// puts("He");
	// printf("%zd\n", stack_size(stack));
	if (stack_size(stack) <= 1)
		return (false);
	if (cmd == RA)
		return (true);
	if (cmd == RB)
		return (true);
	if (cmd == RR && stack_size(stack2) > 1)
		return (true);
	return (false);
}

bool	is_revrotate(t_list *stack, t_list *stack2, int cmd)
{
	// 要素が1つ以下のときreturn
	// puts("Hep");
	// printf("%zd\n", stack_size(stack));
	if (stack_size(stack) <= 1)
		return (false);
	if (cmd == RRA)
		return (true);
	if (cmd == RRB)
		return (true);
	if (cmd == RRR && stack_size(stack2) > 1)
		return (true);
	return (false);
}

bool	is_push(t_list *from, int cmd)
{
	// puts("Yep");
	if (stack_size(from) == 0)
		return (false);
	if (cmd == PA)
		return (true);
	if (cmd == PB)
		return (true);
	return (false);
}
