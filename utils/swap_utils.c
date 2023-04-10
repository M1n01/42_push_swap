/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:06:05 by minabe            #+#    #+#             */
/*   Updated: 2023/04/10 19:25:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	is_swap(t_list *stack)
{
	if (stack->next->ordinal - stack->next->next->ordinal == 1)
		return (true);
	return (false);
}

void	opt_swap(t_list *stack1, t_list *stack2, int command)
{
	if (command == SA && stack2->next->next->ordinal - stack2->next->ordinal == 1)
	{
		swap(stack1);
		swap(stack2);
		print_command(SS);
	}
	else if (command == SA)
	{
		swap(stack1);
		print_command(SA);
	}
	else if (command == SB && stack1->next->ordinal - stack1->next->next->ordinal == 1)
	{
		swap(stack1);
		swap(stack2);
		print_command(SS);
	}
	else if (command == SB)
	{
		swap(stack2);
		print_command(SB);
	}
	return ;
}
