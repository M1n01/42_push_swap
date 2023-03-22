/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/03/22 22:36:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	sort(t_list *stack1, t_list *stack2);
static void	split_into_stack(t_list *stack1, t_list *stack2, size_t size);
size_t	count_rotate(t_list *stack, ssize_t find);
size_t	count_revrotate(t_list *stack, ssize_t find);

void	sort_long(t_list *stack1, t_list *stack2)
{
	// pivot以下のものをstackBに移す
	// quick_sort(stack1, stack2, stack_size(stack1) / 2);
	// init_bucket(stack2);
	// printLists(stack1, stack2);
	split_into_stack(stack1, stack2, stack_size(stack1));
	// puts("[after split]");
	// printLists(stack1, stack2);
	sort(stack1, stack2);
	// printLists(stack1, stack2);
	return ;
}

static void	sort(t_list *stack1, t_list *stack2)
{
	size_t	step;

	while (stack_size(stack2) > 0)
	{
		if (stack2->next->ordinal == (ssize_t)(stack_size(stack2) - 1))
		{
			push(stack2, stack1);
			print_command(PA);
		}
		else
		{
			if (count_rotate(stack2, stack_size(stack2) - 1) < count_revrotate(stack2, stack_size(stack2) - 1))
			{
				step = count_rotate(stack2, stack_size(stack2) - 1);
				while (step > 0)
				{
					command1(stack2, RB);
					print_command(RB);
					step--;
				}
			}
			else
			{
				step = count_revrotate(stack2, stack_size(stack2) - 1);
				while (step > 0)
				{
					command1(stack2, RRB);
					print_command(RRB);
					step--;
				}
			}
		}
	}
}

size_t	count_rotate(t_list *stack, ssize_t find)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < stack_size(stack))
	{
		if (stack->next->ordinal == find)
			break ;
		stack = stack->next;
		count++;
		i++;
	}
	return (count);
}

size_t	count_revrotate(t_list *stack, ssize_t find)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < stack_size(stack))
	{
		if (stack->next->ordinal == find)
			break ;
		stack = stack->prev;
		count++;
		i++;
	}
	return (count);
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
	while (stack_size(stack1) != 1)
	{
		if (stack1->next->ordinal == (ssize_t)size - 1)
		{
			rotate(stack1);
			print_command(RA);
		}
		else
		{
			push(stack1, stack2);
			print_command(PB);
		}
	}
}
