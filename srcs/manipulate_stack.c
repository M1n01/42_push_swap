/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:42:12 by minabe            #+#    #+#             */
/*   Updated: 2022/10/23 20:28:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../include/push_swap.h"

t_list	*search_smaller(t_list *stack, ssize_t value)
{
	stack = stack->next;
	while (stack->ordinal != -1)
	{
		if (stack->ordinal < value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*search_value(t_list *stack, ssize_t value)
{
	stack = stack->next;
	while (stack->ordinal != -1)
	{
		if (stack->ordinal == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*search_tail(t_list	*stack)
{
	t_list	*last;

	while (stack->next->ordinal != -1)
		stack = stack->next;
	last = stack;
	return (last);
}
