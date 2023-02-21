/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:32 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:26:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	print_list(t_list *stack);

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	size_t	i;
	// size_t	j;
	// t_list	*find;

	// if (size <= 6)
	// {
	// 	sort(stack1);
	// 	return ;
	// }
	puts("~~~stack1~~~");
	print_list(stack1);
	puts("~~~stack2~~~");
	print_list(stack2);
	// pbしたい数字を上と下から見つけて早い方でpbまで行う
	i = 0;
	while (i < size / 2)
	{
		push_b(stack1, stack2, size / 2);
		i++;
	}
	puts("~~~stack1~~~");
	print_list(stack1);
	puts("~~~stack2~~~");
	print_list(stack2);
	return ;
}

void	print_list(t_list *stack)
{
	t_list	*head;

	puts("[value] [ordinal]");
	head = stack;
	while (stack->next != head)
	{
		stack = stack->next;
		printf("%d %zd\n", stack->value, stack->ordinal);
	}
	stack = stack->next;
	return ;
}
