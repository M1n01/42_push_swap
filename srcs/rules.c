/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:05:10 by minabe            #+#    #+#             */
/*   Updated: 2022/08/24 11:44:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

void	swap(int *big, int *small)
{
	int	tmp;

	tmp = *big;
	*big = *small;
	*small = tmp;
	return ;
}

void	push(t_list *from, t_list *to)
{
	from = from->next;
	list_cpy(from, to);
	lstdelone_node(from);
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
