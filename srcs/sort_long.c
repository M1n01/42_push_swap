/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/03/21 14:35:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	sort(t_list *stack1, t_list *stack2);
static void	split_into_stack(t_list *stack1, t_list *stack2, size_t size);

void	sort_long(t_list *stack1, t_list *stack2)
{
	// pivot以下のものをstackBに移す
	// quick_sort(stack1, stack2, stack_size(stack1) / 2);
	// init_bucket(stack2);
	// printLists(stack1, stack2);
	split_into_stack(stack1, stack2, stack_size(stack1));
	sort(stack1, stack2);
	return ;
}

static void	sort(t_list *stack1, t_list *stack2)
{
	// ssize_t	i;
	// ssize_t	p1;
	// ssize_t	p2;

	// p1 = size / 3;
	// p2 = size * 2 / 3;
	printLists(stack1, stack2);
	// stack1はsortedとする
	sort_middle(stack1, stack2);
	// printf("%zd\n", size);
	// printLists(stack1, stack2);
}

void	split_into_stack(t_list *stack1, t_list *stack2, size_t size)
{
	size_t	i;
	ssize_t	p1, p2;

	i = 0;
	p1 = size / 3;
	p2 = size * 2 / 3;
	while (i < size)
	{
		// pushし終えた時点で大中小には分けたい
		// 
		// low
		if (stack1->next->ordinal < p1)
		{
			command2(stack1, stack2, PB);
			print_command(PB);
			command1(stack2, RB);
			print_command(RB);
		}
		// middle
		else if (stack1->next->ordinal < p2)
		{
			command2(stack1, stack2, PB);
			print_command(PB);
		}
		// high
		else
		{
			rotate(stack1);
			print_command(RA);
		}
		i++;
	}
}
