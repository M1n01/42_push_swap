/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:39:57 by minabe            #+#    #+#             */
/*   Updated: 2023/03/23 00:16:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

size_t	count_rotate(t_list *stack, ssize_t find)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < stack_size(stack))
	{
		if (stack->next->ordinal == find)
			break ;
		stack = stack->next;
		count++;
		i++;
	}
	return (count);
}

size_t	count_revrotate(t_list *stack, ssize_t find)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < stack_size(stack))
	{
		if (stack->next->ordinal == find)
			break ;
		stack = stack->prev;
		count++;
		i++;
	}
	return (count);
}
