/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2023/03/20 15:59:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	dfs(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn);

void	sort_short(t_list *stack1, t_list *stack2)
{
	t_tool	*tool;

	tool = init_tool();
	dfs(stack1, stack2, tool, 0);
	print_ans(tool, tool->turn);
	free_tool(tool);
	return ;
}

static void	dfs(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn)
{
	int	cmd;

	if (turn >= tool->turn)
		return ;
	if (stack_size(stack2) == 0 && is_sorted(stack1, ASC))
		return (update_ans(tool, turn));
	cmd = -1;
	while (++cmd < 11)
	{
		if (is_detour(cmd, tool) || turn >= tool->turn)
			continue ;
		if (!exec_cmd(stack1, stack2, cmd))
			continue ;
		tool->pre = cmd;
		tool->tmp[turn] = cmd;
		dfs(stack1, stack2, tool, turn + 1);
		exec_cmd(stack1, stack2, ch_cmd(cmd));
	}
}
