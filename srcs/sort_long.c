/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/13 21:48:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static t_info	*init_info_long_ver(void)
{
	size_t	i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		malloc_error(info);
	info->tmp = NULL;
	i = 0;
	while (i < info->turn)
	{
		info->tmp[i] = -1;
		i++;
	}
	info->turn = 0;
	info->ans = NULL;
	info->pre = -1;
	return (info);
}

void	ans_optimize(t_info *info)
{
	size_t	i;
	// size_t	count;

	i = 0;
	// count = 0;
	while (i < info->turn - 1)
	{
		if ((info->ans[i - 1] == RA && info->ans[i] == PB) &&\
			(info->ans[i] == PB && info->ans[i + 1] == RRA))
		{
			info->ans[i - 1] = SA;
			ft_memcpy(info->ans + i + 1, info->ans + i + 2, info->turn - i - 2);
			info->turn--;
		}
		if ((info->ans[i - 1] == RB && info->ans[i] == PA) &&\
			(info->ans[i] == PA && info->ans[i + 1] == RRB))
		{
			info->ans[i - 1] = SB;
			ft_memcpy(info->ans + i + 1, info->ans + i + 2, info->turn - i - 2);
			info->turn--;
		}
		i++;
	}
	// printf("count = %zu\n", count);
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	t_info	*info;

	info = init_info_long_ver();
	// printLists(stack1, stack2);
	set_stack(stack1, stack2, info);
	// printLists(stack1, stack2);
	stack_bottom_third_sort(stack1, stack2, info);
	stack_middle_third_sort(stack1, stack2, info);
	stack_top_third_sort(stack1, stack2, info);
	ans_optimize(info);
	print_ans(info);
	safer_free(info->tmp);
	safer_free(info->ans);
	safer_free(info);
	// printLists(stack1, stack2);
	// if (is_sorted(stack1, ASC))
	// 	puts("OK");
	return ;
}
