/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:21:58 by minabe            #+#    #+#             */
/*   Updated: 2023/04/12 23:03:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

t_info	*init_info(void)
{
	size_t	i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		malloc_error(info);
	info->turn = LIMIT_SHORT;
	info->tmp = malloc(sizeof(int) * (info->turn));
	if (info->tmp == NULL)
		malloc_error(info->tmp);
	i = 0;
	while (i < info->turn)
	{
		info->tmp[i] = -1;
		i++;
	}
	info->ans = NULL;
	info->pre = -1;
	return (info);
}

void	free_info(t_info *info)
{
	safer_free(info->tmp);
	safer_free(info->ans);
	safer_free(info);
}

void	print_ans(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->turn)
	{
		print_command(info->ans[i]);
		i++;
	}
}

int	*add_ans(t_info *info, int command)
{
	int		*ans;

	ans = malloc(sizeof(int) * (info->turn + 1));
	if (!ans)
		malloc_error(ans);
	ft_memcpy(ans, info->ans, info->turn);
	ans[info->turn] = command;
	info->turn++;
	safer_free(info->ans);
	return (ans);
}

void	record_command(t_list *stack1, t_list *stack2, t_info *info, int cmd)
{
	command(stack1, stack2, cmd);
	info->ans = add_ans(info, cmd);
}
