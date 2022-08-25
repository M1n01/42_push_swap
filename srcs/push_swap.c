/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:34:45 by minabe            #+#    #+#             */
/*   Updated: 2022/08/25 18:43:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	pre_pushb(t_list *stack, t_list *find);

void	print_list(t_list *stack);

#include <stdio.h>

int	main(int ac, char *av[])
{
	int		*array;
	size_t	*coordinate;
	t_list	*stack1;
	t_list	*stack2;

	coordinate = malloc(sizeof(size_t) * (ac - 1));
	if (coordinate == NULL)
		error();
	array = make_array(ac, av);
	coordinate_compression(array, coordinate, ac - 1);
	stack1 = make_stack(array, coordinate, ac - 1);
	stack2 = init_stack();
	push_swap(stack1, stack2, ac - 1);
	// system("leaks -q push_swap");
	return (0);
}

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	size_t	i;
	size_t	median;
	t_list	*find;

	median = size / 2;
	i = 1;
	while (i <= median)
	{
		find = search_value(stack1, median - i);
		pre_pushb(stack1, find);
		push(stack1, stack2);
		ft_printf("pb\n");
		i++;
	}
	return ;
}

void	pre_pushb(t_list *stack, t_list *find)
{
	t_list	*tail;
	t_list	*head;

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
