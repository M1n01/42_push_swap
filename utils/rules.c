/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:05:10 by minabe            #+#    #+#             */
/*   Updated: 2023/03/08 12:42:10 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include <stdio.h>

bool	swap(t_list *stack)
{
	t_list	*src;

	src = stack->next;
	if (src->next->ordinal == -1)
		return (false);
	lstcpy(src, src->next);
	lstdelone_node(src);
	return (true);
}

bool	push(t_list *from, t_list *to)
{
	if (from->next->ordinal == -1)
		return (false);
	lstcpy(from->next, to);
	lstdelone_node(from->next);
	return (true);
}

bool	rotate(t_list *stack)
{
	t_list	*src;

	if (stack->next->ordinal == -1)
		return (false);
	src = stack->next;
	lstcpy(src, search_tail(stack));
	lstdelone_node(src);
	return (true);
}

bool	rev_rotate(t_list *stack)
{
	t_list	*src;

	if (stack->next->ordinal == -1)
		return (false);
	src = stack->next;
	lstcpy(search_tail(stack), src);
	lstdelone_node(search_tail(stack));
	return (true);
}
