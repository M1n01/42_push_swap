/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:19:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	classify_into_three(t_list *stack1, t_list *stack2, t_info *info)
{
	size_t	size;

	size = stack_size(stack1);
	while (stack_size(stack1) > size * 2 / 5)
	{
		if ((ssize_t)size / 5 <= stack1->next->ordinal && \
			stack1->next->ordinal < (ssize_t)size * 4 / 5)
			pb_and_split_half(stack1, stack2, info, (ssize_t)size / 2);
		else
			record_command(stack1, stack2, info, RA);
	}
	return ;
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	t_info	*info;
	size_t	size;

	info = init_info_long_ver();
	size = stack_size(stack1) * 3 / 10;
	classify_into_three(stack1, stack2, info);
	bottom_sort(stack1, stack2, info);
	middle_sort(stack1, stack2, info, size);
	middle_sort(stack1, stack2, info, size);
	top_sort(stack1, stack2, info);
	ans_optimize(info);
	print_ans(info);
	free_info(info);
	return ;
}
