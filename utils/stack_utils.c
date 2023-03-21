/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:50:21 by minabe            #+#    #+#             */
/*   Updated: 2023/03/20 18:07:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

size_t	stack_size(t_list *stack)
{
	size_t	len;

	len = 0;
	while (stack->next->ordinal != -1)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

bool	is_sorted(t_list *stack, int order)
{
	while (stack->next->ordinal != -1)
	{
		if (order == ASC && stack->ordinal > stack->next->ordinal)
			return (false);
		if (order == DESC && stack->ordinal < stack->next->ordinal)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_nsorted(t_list *stack, size_t n, int order)
{
	size_t	i;

	i = 0;
	while (stack->next->ordinal != -1 && i <= n)
	{
		if (order == ASC && stack->ordinal > stack->next->ordinal)
			return (false);
		if (order == DESC && stack->ordinal < stack->next->ordinal)
			return (false);
		stack = stack->next;
		i++;
	}
	return (true);
}

ssize_t	ordinal(t_list *stack, size_t i)
{
	size_t	j;

	j = 0;
	stack = stack->next;
	while (j < i && stack->next->ordinal != -1)
	{
		stack = stack->next;
		j++;
	}
	return (stack->ordinal);
}
