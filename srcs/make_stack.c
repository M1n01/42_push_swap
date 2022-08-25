/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:53:25 by minabe            #+#    #+#             */
/*   Updated: 2022/08/25 19:00:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	lstadd_tail(t_list *stack, int value, ssize_t coodinate);

t_list	*make_stack(int *array, size_t *coordinate, size_t size)
{
	size_t	i;
	t_list	*stack;

	stack = init_stack();
	i = 0;
	while (i < size)
	{
		lstadd_tail(stack, array[i], coordinate[i]);
		i++;
	}
	return (stack);
}

t_list	*init_stack(void)
{
	t_list	*head;
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (stack == NULL)
		error();
	head = stack;
	stack->prev = head;
	stack->value = 0;
	stack->ordinal = -1;
	stack->next = head;
	return (stack);
}

static void	lstadd_tail(t_list *stack, int value, ssize_t coodinate)
{
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	head = stack;
	tail = search_tail(stack);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		error();
	new->value = value;
	new->ordinal = coodinate;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
	return ;
}

