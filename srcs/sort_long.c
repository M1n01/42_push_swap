/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/23 23:39:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	set_stack(t_list *stack1, t_list *stack2, t_info *info)
{
	size_t	size;

	size = stack_size(stack1); // 500
	// 中間の+-3/5をpushする
	size_t	push_count = 0;
	// while (stack_size(stack1) < size * 2 / 5) // 300
	while (push_count < 300) // 300
	{
		if ((ssize_t)size / 5 <= stack1->next->ordinal && stack1->next->ordinal < (ssize_t)size * 4 / 5) // 100 ~ 399
		{
			record_command(stack1, stack2, info, PB);
			if (stack2->next->ordinal < (ssize_t)size / 2) // 100 ~ 249
				record_command(stack1, stack2, info, RB);
			push_count++;
		}
		else
			record_command(stack1, stack2, info, RA);
	}
	push_count = 0;
	while (push_count < 100) // 100
	{
		if (stack1->next->ordinal < (ssize_t)size / 2) // 0 ~ 249
			record_command(stack1, stack2, info, RA);
		else
		{
			record_command(stack1, stack2, info, PB);
			if (stack2->next->ordinal < (ssize_t)size * 9 / 10) // 400 ~ 449
				record_command(stack1, stack2, info, RB);
			push_count++;
		}
	}

	return ;
}

void	bottom_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	size_t	push_count = 0;

	// 3rd
	while (push_count < 100) // 100
	{
		find_max_and_pa(stack1, stack2, info);
		push_count++;
	}
	push_count = 0;
	while (push_count < 100)
	{
		if (300 <= stack2->next->ordinal && stack2->next->ordinal < 400)
		{
			record_command(stack1, stack2, info, PA);
			if (stack1->next->ordinal >= 350)
				record_command(stack1, stack2, info, RA);
			push_count++;
		}
		else
			record_command(stack1, stack2, info, RB);
	}
	for (ssize_t i = 300; i < 400; i++)
	{
		find_ordinal_and_pb(stack1, stack2, info, i);
	}
	push_count = 0;
	while (push_count < 150) // 100
	{
		find_max_and_pa(stack1, stack2, info);
		push_count++;
	}
	while (push_count < 100) // 100
	{
		find_max_and_pa(stack1, stack2, info);
		push_count++;
	}
	// 2nd
	push_count = 0;
	while (push_count < 100)
	{
		if (150 <= stack2->next->ordinal && stack2->next->ordinal < 250)
		{
			record_command(stack1, stack2, info, PA);
			if (stack1->next->ordinal >= 200)
				record_command(stack1, stack2, info, RA);
			push_count++;
		}
		else
			record_command(stack1, stack2, info, RB);
	}
	for (ssize_t i = 150; i < 250; i++)
	{
		find_ordinal_and_pb(stack1, stack2, info, i);
	}
	push_count = 0;
	while (push_count < 150) // 100
	{
		find_max_and_pa(stack1, stack2, info);
		push_count++;
	}
	// 1st
	push_count = 0;
	while (push_count < 100)
	{
		// ここは先にpbして2つに分割した方が良さげ
		find_min_and_pb(stack1, stack2, info);
		push_count++;
	}
	while (stack_size(stack2) > 0)
		record_command(stack1, stack2, info, PA);
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	t_info	*info;

	info = init_info_long_ver();
	// printLists(stack1, stack2);
	set_stack(stack1, stack2, info);
	// printLists(stack1, stack2);
	bottom_sort(stack1, stack2, info);
	// stack_middle_third_sort(stack1, stack2, info);
	// stack_top_third_sort(stack1, stack2, info);
	ans_optimize(info);
	print_ans(info);
	free_info(info);
	// printLists(stack1, stack2);
	// printf("stackA size: %ld, stackB size: %ld\n", stack_size(stack1), stack_size(stack2));
	return ;
}
