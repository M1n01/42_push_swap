/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:39:57 by minabe            #+#    #+#             */
/*   Updated: 2023/03/21 13:50:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static size_t	find_addr(t_list *stack, ssize_t ordinal);

void	sort_middle(t_list *stack1, t_list *stack2)
{
	size_t	i;
	size_t	ad;

	// stack1の先頭ordinal-1をstack2から探し、先頭に持ってくる
	// その後、paする
	while (stack_size(stack2) > stack_size(stack1) / 3)
	{
		ad = find_addr(stack2, stack1->next->ordinal - 1);
		i = 0;
		if (ad < stack_size(stack2) / 2)
		{
			while (i < ad)
			{
				rotate(stack2);
				print_command(RB);
				i++;
			}
		}
		else
		{
			while (i < ad - stack_size(stack2) / 2)
			{
				rev_rotate(stack2);
				print_command(RRB);
				i++;
			}
		}
		command2(stack1, stack2, PA);
		print_command(PA);
	}
}

static size_t	find_addr(t_list *stack, ssize_t ordinal)
{
	size_t	i;

	i = 0;
	while (stack->next->ordinal != ordinal)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
