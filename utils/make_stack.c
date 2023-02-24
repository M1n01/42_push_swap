/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:53:25 by minabe            #+#    #+#             */
/*   Updated: 2023/02/24 17:19:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	lstadd_tail(t_list *stack, int value, ssize_t coodinate);

t_list	*make_stack(int ac, char *av[])
{
	int	*array;
	int	i;
	ssize_t	*coordinate;
	t_list	*stack;

	array = make_array(ac, av);
	coordinate = compression(array, ac - 1);
	stack = init_stack();
	i = 0;
	while (i < ac - 1)
	{
		lstadd_tail(stack, array[i], coordinate[i]);
		i++;
	}
	free(array);
	free(coordinate);
	return (stack);
}

t_list	*init_stack(void)
{
	t_list	*head;
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (stack == NULL)
		malloc_error(stack);
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
		malloc_error(new);
	new->value = value;
	new->ordinal = coodinate;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
	return ;
}

t_tool	*init_tool()
{
	t_tool	*tool;

	tool = malloc(sizeof(t_tool));
	if (!tool)
		malloc_error(tool);
	tool->ans = NULL;
	tool->turn = 0;
	return (tool);
}