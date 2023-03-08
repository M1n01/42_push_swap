/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:32 by minabe            #+#    #+#             */
/*   Updated: 2023/03/08 14:59:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

static size_t	set_stack(t_list *stack1, t_list *stack2, size_t n);
static size_t	count_rotate(t_list *stack, ssize_t n);
static size_t	count_revrotate(t_list *stack, ssize_t n);

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	t_tool	*tool;
	size_t	turn;

	// if (size <= 1)
	// 	return ;
	if (is_sorted(stack1))
		return ;
	tool = init_tool();
	// pbしたい数字を上と下から見つけて早い方でpbまで行う
	turn = set_stack(stack1, stack2, size / 2);
	// puts("~~~stack1~~~");
	// printList(stack1);
	// puts("~~~stack2~~~");
	// printList(stack2);
	if (size <= 6)
	{
		sort_short(stack1, stack2, tool, turn);
		return ;
	}
	// dfs(stack1, stack2);
	// printf("%p", tool);
	return ;
}

static size_t	set_stack(t_list *stack1, t_list *stack2, size_t n)
{
	size_t	i;
	size_t	turn;
	size_t	step;

	turn = 0;
	i = 0;
	while (i < n)
	{
		if (count_rotate(stack1, n - 1) <= count_revrotate(stack1, n - 1))
		{
			step = count_rotate(stack1, n - 1);
			while (step > 0)
			{
				command1(stack1, RA);
				ft_printf("ra\n");
				turn++;
				step--;
			}
		}
		else
		{
			step = count_revrotate(stack1, n - 1);
			while (step > 0)
			{
				command1(stack1, RRA);
				ft_printf("rra\n");
				turn++;
				step--;
			}
		}
		command2(stack1, stack2, PB);
		ft_printf("pb\n");
		turn++;
		i++;
	}
	return (turn);
}

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
	if (stack->next == head)
	{
		printf("<NULL>\n\n");
		return ;
	}
	for (;stack->next != head;)
	{
		stack = stack->next;
		printf("%d %zd\n", stack->value, stack->ordinal);
	}
	puts("");
	stack = stack->next;
	return ;
}
