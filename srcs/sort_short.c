/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2023/03/10 22:06:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

int		ch_cmd(int cmd);
void	update_ans(t_tool *tool, size_t turn);
bool	exec_cmd(t_list *stack1, t_list *stack2, int cmd);
bool	is_detour(int cmd, t_tool *tool);
void	dfs(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn);

void	sort_short(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn)
{
	tool->turn = LIMIT_LESS6;
	dfs(stack1, stack2, tool, turn);
	// puts("~~~~~~~~");
	print_ans(tool, tool->turn);
	// printf("%zd\n", tool->turn);
	return ;
}

void	dfs(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn)
{
	int	cmd;

	// printf("turn : %zd\n", turn);
	if (turn >= tool->turn)
		return ;
	if (stack_size(stack2) == 0 && is_sorted(stack1))
	{
		// puts("");
		// printLists(stack1, stack2);
		// puts("");
		return (update_ans(tool, turn));
	}
	cmd = -1;
	while (++cmd < 11)
	{
		if (is_detour(cmd, tool) || turn >= tool->turn)
			continue ;
		if (!exec_cmd(stack1, stack2, cmd))
		{
			// puts("return");
			// print_command(cmd);
			// printLists(stack1, stack2);
			continue ;
		}
		// print_command(cmd);
		// printLists(stack1, stack2);
		tool->pre = cmd;
		tool->tmp[turn] = cmd;
		dfs(stack1, stack2, tool, turn + 1);
		exec_cmd(stack1, stack2, ch_cmd(cmd));
		// printLists(stack1, stack2);
	}
}

void	update_ans(t_tool *tool, size_t turn)
{
	size_t	i;

	if (tool->ans != NULL)
		safer_free(tool->ans);
	tool->ans = malloc(sizeof(size_t) * (turn));
	if (!tool->ans)
		malloc_error(tool);
	i = 0;
	while (i < turn)
	{
		// printf("%zd\n", i);
		tool->ans[i] = tool->tmp[i];
		i++;
	}
	tool->turn = turn;
	// print_ans(tool, tool->turn);
	return ;
}

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

bool	is_detour(int cmd, t_tool *tool)
{
	if (cmd == PA && tool->pre == PB)
		return (true);
	if (cmd == PB && tool->pre == PA)
		return (true);
	if (cmd == SA && (tool->pre == SA || tool->pre == SB || tool->pre == SS))
		return (true);
	if (cmd == SB && (tool->pre == SA || tool->pre == SB || tool->pre == SS))
		return (true);
	if (cmd == SS && (tool->pre == SA || tool->pre == SB || tool->pre == SS))
		return (true);
	if (cmd == RA && (tool->pre == RRA || tool->pre == RRR))
		return (true);
	if (cmd == RB && (tool->pre == RRB || tool->pre == RRR))
		return (true);
	if (cmd == RR && (tool->pre == RRA || tool->pre == RRB || tool->pre == RRR))
		return (true);
	if (cmd == RRA && (tool->pre == RA || tool->pre == RR))
		return (true);
	if (cmd == RRB && (tool->pre == RB || tool->pre == RR))
		return (true);
	if (cmd == RRR && (tool->pre == RA || tool->pre == RB || tool->pre == RR))
		return (true);
	return (false);
}

void	print_ans(t_tool *tool, size_t turn)
{
	size_t	i;

	i = 0;
	while (i < turn)
	{
		print_command(tool->ans[i]);
		i++;
	}
}
