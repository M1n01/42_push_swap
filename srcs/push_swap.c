/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:32 by minabe            #+#    #+#             */
/*   Updated: 2023/02/20 16:05:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../include/push_swap.h"

#include <stdio.h>

int		check_sort1(t_list *stack1);
int		check_sort2(t_list *stack2);
void	print_list(t_list *stack);

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	// size_t	i;
	// size_t	j;
	// t_list	*find;

	// if (size <= 6)
	// {
	// 	sort(stack1);
	// 	return ;
	// }
	// phase1(stack1, stack2, push_len);
	puts("~~~stack1~~~");
	print_list(stack1);
	puts("~~~stack2~~~");
	print_list(stack2);
	// pbしたい数字を上と下から見つけて早い方でpbまで行う
	int	fstep = 0;
	int	bstep = 0;
	t_list	*head = stack1;
	t_list	*tail = search_tail(stack1);
	int	n = size / 2;
	stack1 = head->next;
	while (stack1->ordinal > n)
	{
		stack1 = stack1->next;
		fstep++;
	}
	stack1 = tail;
	bstep++;
	while (stack1->ordinal > n)
	{
		stack1 = stack1->prev;
		bstep++;
	}
	printf("step: %d %d\n", fstep, bstep);
	stack1 = head;
	if (fstep <= bstep)
	{
		while (fstep > 0)
		{
			rotate(stack1);
			ft_printf("ra\n");
			fstep--;
		}
		push(stack1, stack2);
		ft_printf("pb\n");
	}
	else
	{
		while (bstep > 0)
		{
			rev_rotate(stack1);
			ft_printf("rra\n");
			bstep--;
		}
		push(stack1, stack2);
		ft_printf("pb\n");
	}
	puts("~~~stack1~~~");
	print_list(stack1);
	puts("~~~stack2~~~");
	print_list(stack2);
	// i = 0;
	// while (i <= size)
	// {
	// 	while (check_sort1(stack1) && check_sort2(stack2))
	// 	{
	// 		if (head1->next->ordinal > head1->next->next->ordinal)
	// 		{
	// 			find = head1->next;
	// 			swap(head1->next, find);
	// 			rotate(stack1);
	// 			ft_printf("sa\n");
	// 			rotate(stack1);
	// 			ft_printf("sa\n");
	// 		}
	// 		if (head2->next->ordinal < head2->next->next->ordinal)
	// 		{
	// 			find = head2->next->next;
	// 			swap(head2->next, find);
	// 			rotate(stack2);
	// 			ft_printf("sb\n");
	// 			rotate(stack2);
	// 			ft_printf("sb\n");
	// 		}
	// 	}
	// 	i++;
	// }
	return ;
}

int	check_sort1(t_list *stack1)
{
	t_list	*head;

	head = stack1->next;
	while (stack1->next != head)
	{
		if (stack1->ordinal > stack1->next->ordinal)
			return (1);
		stack1 = stack1->next;
	}
	return (0);
}

int	check_sort2(t_list *stack2)
{
	t_list	*head;

	head = stack2->next;
	while (stack2->next != head)
	{
		if (stack2->ordinal < stack2->next->ordinal)
			return (1);
		stack2 = stack2->next;
	}
	return (0);
}

void	move_find_to_second(t_list *stack, t_list *find)
{
	t_list	*head;
	t_list	*tail;

	head = stack;
	tail = search_tail(stack);
	if (find - head <= tail - find)
	{
		while (head->next != find)
		{
			rotate(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (head->next != find)
		{
			rev_rotate(stack);
			ft_printf("rra\n");
		}
	}
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
