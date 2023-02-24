/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:32 by minabe            #+#    #+#             */
/*   Updated: 2023/02/24 17:31:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	printList(t_list *stack);

static void		set_stack(t_list *stack1, t_list *stack2, size_t n);
static size_t	count_rotate(t_list *stack, ssize_t n);
static size_t	count_revrotate(t_list *stack, ssize_t n);

void	push_swap(t_list *stackA, t_list *stackB, size_t size)
{
	t_tool	*tool;

	tool = init_tool();
	puts("~~~stackA~~~");
	printList(stackA);
	puts("~~~stackB~~~");
	printList(stackB);
	// pbしたい数字を上と下から見つけて早い方でpbまで行う
	set_stack(stackA, stackB, size / 2);
	if (size <= 6)
	{
		sort6_or_less(stackA, stackB, tool, 0);
		return ;
	}
	// dfs(stackA, stackB);
	puts("~~~stackA~~~");
	printList(stackA);
	puts("~~~stackB~~~");
	printList(stackB);
	// printf("%p", tool);
	return ;
}

static void	set_stack(t_list *stackA, t_list *stackB, size_t n)
{
	size_t	i;
	size_t	step;

	i = 0;
	while (i < n)
	{
		if (count_rotate(stackA, n - 1) <= count_revrotate(stackA, n - 1))
		{
			step = count_rotate(stackA, n - 1);
			while (step > 0)
			{
				command1(stackA, RA);
				step--;
			}
		}
		else
		{
			step = count_revrotate(stackA, n - 1);
			while (step > 0)
			{
				command1(stackA, RRA);
				step--;
			}
		}
		command2(stackA, stackB, PB);
		i++;
	}
}

// scopeでやるかポインタでやるか考える
static size_t	count_rotate(t_list *stack, ssize_t n)
{
	size_t	step;

	step = 0;
	stack = stack->next;
	while (stack->ordinal > n)
	{
		stack = stack->next;
		step++;
	}
	return (step);
}

// scopeでやるかポインタでやるか考える
static size_t	count_revrotate(t_list *stack, ssize_t n)
{
	size_t	step;

	step = 1;
	stack = search_tail(stack);
	while (stack->ordinal > n)
	{
		stack = stack->prev;
		step++;
	}
	return (step);
}

void	printList(t_list *stack)
{
	t_list	*head;

	puts("[value] [ordinal]");
	head = stack;
	for (;stack->next != head;)
	{
		stack = stack->next;
		printf("%d %zd\n", stack->value, stack->ordinal);
	}
	stack = stack->next;
	return ;
}
