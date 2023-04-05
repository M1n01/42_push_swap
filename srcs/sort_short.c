/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2023/04/05 12:42:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	dfs(t_list *stack1, t_list *stack2, t_info *info, size_t turn);

void	sort_short(t_list *stack1, t_list *stack2)
{
	t_info	*info;

	info = init_info();
	dfs(stack1, stack2, info, 0);
	print_ans(info, info->turn);
	free_info(info);
	return ;
}

static void	dfs(t_list *stack1, t_list *stack2, t_info *info, size_t turn)
{
	int	command;

	if (turn >= info->turn)
		return ;
	if (stack_size(stack2) == 0 && is_sorted(stack1, ASC))
		return (update_ans(info, turn));
	command = -1;
	while (++command < 11)
	{
		if (is_detour(command, info) || turn >= info->turn)
			continue ;
		if (!exec_cmd(stack1, stack2, command))
			continue ;
		info->pre = command;
		info->tmp[turn] = command;
		dfs(stack1, stack2, info, turn + 1);
		exec_cmd(stack1, stack2, ch_cmd(command));
	}
}
