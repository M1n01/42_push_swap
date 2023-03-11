/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:05:10 by minabe            #+#    #+#             */
/*   Updated: 2023/03/11 11:56:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	swap(t_list *stack)
{
	t_list	*src;

	src = stack->next;
	lstcpy(src, src->next);
	lstdelone_node(src);
	return ;
}

// fromの1つ目(0個目は番兵ノード)をtoの1つ目(0個目は番兵ノード)にpush
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

	src = stack->next;
	lstcpy(src, stack->prev);
	lstdelone_node(src);
	return ;
}

void	rev_rotate(t_list *stack)
{
	t_list	*src;

	src = stack->prev;
	lstcpy(src, stack);
	lstdelone_node(src);
	return ;
}
