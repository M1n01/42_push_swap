/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/03/12 10:47:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

static void	dfs(t_list *stack1, t_list *stack2, size_t pivot);
static void	set_stack(t_list *stack1, t_list *stack2, size_t pivot);
static size_t	count_rotate(t_list *stack, ssize_t pivot);
static size_t	count_revrotate(t_list *stack, ssize_t pivot);

void	sort_long(t_list *stack1, t_list *stack2)
{
	dfs(stack1, stack2, stack_size(stack1) / 2);
	return ;
}

static void	dfs(t_list *stack1, t_list *stack2, size_t pivot)
{
	if (is_sorted(stack1) && stack_size(stack2) == 0)
		return ;
	// pivot以下のものをstackBに移す
	set_stack(stack1, stack2, pivot);
	// stackBを最小単位に分割して入れ替える(再帰)
	printLists(stack1, stack2);
}

static void	set_stack(t_list *stack1, t_list *stack2, size_t pivot)
{
	size_t	i;
	size_t	step;

	i = 0;
	while (i < pivot)
	{
		if (count_rotate(stack1, pivot - 1) <= count_revrotate(stack1, pivot - 1))
		{
			step = count_rotate(stack1, pivot - 1);
			while (step > 0)
			{
				command1(stack1, RA);
				ft_printf("ra\n");
				step--;
			}
		}
		else
		{
			step = count_revrotate(stack1, pivot - 1);
			while (step > 0)
			{
				command1(stack1, RRA);
				ft_printf("rra\n");
				step--;
			}
		}
		command2(stack1, stack2, PB);
		ft_printf("pb\n");
		i++;
	}
	return ;
}

static size_t	count_rotate(t_list *stack, ssize_t pivot)
{
	size_t	step;

	step = 0;
	stack = stack->next;
	while (stack->ordinal > pivot)
	{
		stack = stack->next;
		step++;
	}
	return (step);
}

static size_t	count_revrotate(t_list *stack, ssize_t pivot)
{
	size_t	step;

	step = 1;
	stack = search_tail(stack);
	while (stack->ordinal > pivot)
	{
		stack = stack->prev;
		step++;
	}
	return (step);
}

