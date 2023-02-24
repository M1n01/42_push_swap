/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2023/02/24 17:49:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	sort6_or_less(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn)
{
	dfs(stack1, stack2, tool, 0);
}

void	dfs(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn)
{
	int	command;

	if (turn >= LIMIT_LESS6)
		return ;
	if (stack2->next->ordinal == -1 && is_sorted(stack1))
		return ;
	command = 0;
	while (command++ < 11)
	{
		// 枝切り
		if (turn >= LIMIT_LESS6)
			;
		// 
		;
		dfs(stack1, stack2, tool, turn + 1);
		back_track(stack1, stack2, tool, turn);
	}
}

bool	is_sorted(t_list *stack)
{
	stack = stack->next;
	while (stack->next->next->ordinal != -1)
	{
		if (stack->ordinal > stack->next->ordinal)
			return (false);
		stack = stack->next;
	}
	return (true);
}
