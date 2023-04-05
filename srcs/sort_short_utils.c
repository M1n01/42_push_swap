/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:50:13 by minabe            #+#    #+#             */
/*   Updated: 2023/04/05 12:42:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	update_ans(t_info *info, size_t turn)
{
	size_t	i;

	if (info->ans != NULL)
		safer_free(info->ans);
	info->ans = malloc(sizeof(size_t) * (turn));
	if (!info->ans)
		malloc_error(info);
	i = 0;
	while (i < turn)
	{
		info->ans[i] = info->tmp[i];
		i++;
	}
	info->turn = turn;
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

bool	is_detour(int cmd, t_info *info)
{
	if (cmd == PA && info->pre == PB)
		return (true);
	if (cmd == PB && info->pre == PA)
		return (true);
	if (cmd == SA && (info->pre == SA || info->pre == SB || info->pre == SS))
		return (true);
	if (cmd == SB && (info->pre == SA || info->pre == SB || info->pre == SS))
		return (true);
	if (cmd == SS && (info->pre == SA || info->pre == SB || info->pre == SS))
		return (true);
	if (cmd == RA && (info->pre == RRA || info->pre == RRR))
		return (true);
	if (cmd == RB && (info->pre == RRB || info->pre == RRR))
		return (true);
	if (cmd == RR && (info->pre == RRA || info->pre == RRB || info->pre == RRR))
		return (true);
	if (cmd == RRA && (info->pre == RA || info->pre == RR))
		return (true);
	if (cmd == RRB && (info->pre == RB || info->pre == RR))
		return (true);
	if (cmd == RRR && (info->pre == RA || info->pre == RB || info->pre == RR))
		return (true);
	return (false);
}

void	print_ans(t_info *info, size_t turn)
{
	size_t	i;

	i = 0;
	while (i < turn)
	{
		print_command(info->ans[i]);
		i++;
	}
}
