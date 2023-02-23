/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:05:10 by minabe            #+#    #+#             */
/*   Updated: 2023/02/23 22:17:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include <stdio.h>

void	swap(t_list *stack)
{
	t_list	*big;
	t_list	*small;
	int		tmp1;
	ssize_t	tmp2;

	if (stack->next->ordinal > stack->next->next->ordinal)
	{
		small = stack->next->next;
		big = stack->next;
	}
	else
	{
		small = stack->next;
		big = stack->next->next;
	}
	tmp1 = small->value;
	tmp2 = small->ordinal;
	small->value = big->value;
	small->ordinal = big->ordinal;
	big->value = tmp1;
	big->ordinal = tmp2;
	return ;
}

void	push(t_list *from, t_list *to)
{
	t_list	*src;

	src = from->next;
	lstcpy(src, to);
	lstdelone_node(src);
	return ;
}

void	rotate(t_list *stack)
{
	t_list	*src;
	t_list	*head;
	t_list	*tail;

	tail = search_tail(stack);
	head = stack;
	src = head->next;
	head->next = src->next;
	src->next->prev = head;
	src->prev = tail;
	src->next = head;
	tail->next = src;
	head->prev = src;
	return ;
}

void	rev_rotate(t_list *stack)
{
	t_list	*src;
	t_list	*head;
	t_list	*dest;

	head = stack;
	dest = head->next;
	src = search_tail(stack);
	src->prev->next = head;
	head->prev = src->prev;
	src->prev = head;
	head->next = src;
	src->next = dest;
	dest->prev = src;
	head->next = src;
	return ;
}
