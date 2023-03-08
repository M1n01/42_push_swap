/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:50:21 by minabe            #+#    #+#             */
/*   Updated: 2023/03/08 12:18:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

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

bool	is_sorted(t_list *stack)
{
	while (stack->next->ordinal != -1)
	{
		if (stack->ordinal > stack->next->ordinal)
			return (false);
		stack = stack->next;
	}
	return (true);
}
