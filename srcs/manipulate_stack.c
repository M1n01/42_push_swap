/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:42:12 by minabe            #+#    #+#             */
/*   Updated: 2022/08/25 19:00:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

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
