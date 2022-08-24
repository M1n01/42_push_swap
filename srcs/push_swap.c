/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:34:45 by minabe            #+#    #+#             */
/*   Updated: 2022/08/24 11:46:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	rev_rotate(t_list *stack);

void	rotate(t_list *stack);
t_list	*search_value(t_list *stack, ssize_t value);
t_list	*lstdelone_node(t_list *trash);
void	list_cpy(t_list *head, t_list *src);
void	lstadd_last(t_list *head, t_list *src);
void	print_list(t_list *stack);

#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	int		*array;
	size_t	*coordinate;
	t_list	*stack1;
	t_list	*stack2;

	array = malloc(sizeof(int) * (ac - 1));
	if (array == NULL)
		error();
	coordinate = malloc(sizeof(size_t) * (ac - 1));
	if (coordinate == NULL)
		error();
	i = 0;
	while (i < ac - 1)
	{
		array[i] = ft_atoi(av[i + 1]);
		i++;
	}
	coordinate_compression(array, coordinate, ac - 1);
	puts("main1");
	stack1 = make_stack1(array, coordinate, ac - 1);
	puts("main2");
	// stack2 = make_stack2();
	stack2 = init_stack();
	push_swap(stack1, stack2, ac - 1);
	return (0);
}

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	size_t	i = 0;

	while (i <= 1)
	{
		puts("~~~~~~stack1~~~~~~");
		print_list(stack1);
		puts("~~~~~~stack2~~~~~~");
		print_list(stack2);
		// rev_rotate(stack1);
		i++;
	}
	printf("size: %zu\n", size);
	return ;
}

t_list	*search_value(t_list *stack, ssize_t value)
{
	t_list	*head;

	head = stack;
	puts("search_value");
	while (stack->next != head)
	{
		if (stack->ordinal == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	print_list(t_list *stack)
{
	t_list	*head;

	puts("[value] [ordinal]");
	head = stack;
	while (stack->next != head)
	{
		stack = stack->next;
		printf("%d ", stack->value);
		printf("%zd\n", stack->ordinal);
	}
	stack = stack->next;
	return ;
}
