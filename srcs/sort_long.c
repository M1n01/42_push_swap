/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/12 15:11:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static t_info	*init_inf(void)
{
	size_t	i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		malloc_error(info);
	info->tmp = malloc(sizeof(int));
	if (info->tmp == NULL)
		malloc_error(info->tmp);
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

void	sort_long(t_list *stack1, t_list *stack2)
{
	t_info	*info;

	info = init_inf();
	// printLists(stack1, stack2);
	set_stack(stack1, stack2, info);
	// printLists(stack1, stack2);
	stack_bottom_third_sort(stack1, stack2, info);
	stack_middle_third_sort(stack1, stack2, info);
	stack_top_third_sort(stack1, stack2, info);
	print_ans(info);
	safer_free(info->tmp);
	safer_free(info->ans);
	safer_free(info);
	// printLists(stack1, stack2);
	return ;
}
