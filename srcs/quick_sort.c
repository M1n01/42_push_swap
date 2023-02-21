/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:50:10 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	push_b(t_list *stack1, t_list *stack2, size_t n)
{
	size_t	fstep;
	size_t	bstep;

	fstep = count_rotate(stack1, n);
	bstep = count_revrotate(stack1, n);
	if (fstep <= bstep)
	{
		while (fstep > 0)
		{
			command1(stack1, "ra");
			fstep--;
		}
	}
	else
	{
		while (bstep > 0)
		{
			command1(stack1, "rra");
			bstep--;
		}
	}
	command2(stack1, stack2, "pb");
}

// scopeでやるかポインタでやるか考える
size_t	count_rotate(t_list *stack, ssize_t n)
{
	size_t	step;

	step = 0;
	stack = stack->next;
	while (stack->ordinal > n)
	{
		stack = stack->next;
		step++;
	}
	printf("fstep: %zu\n", step);
	return (step);
}

// scopeでやるかポインタでやるか考える
size_t	count_revrotate(t_list *stack, ssize_t n)
{
	size_t	step;

	step = 1;
	stack = search_tail(stack);
	while (stack->ordinal > n)
	{
		stack = stack->prev;
		step++;
	}
	printf("bstep: %zu\n", step);
	return (step);
}