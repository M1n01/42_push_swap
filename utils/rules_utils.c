/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:54:43 by minabe            #+#    #+#             */
/*   Updated: 2023/02/23 22:23:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

t_list	*lstdelone_node(t_list *trash)
{
	t_list	*prev;

	prev = trash->prev;
	trash->next->prev = prev;
	prev->next = trash->next;
	safer_free(trash);
	return (prev->next);
}

void	lstcpy(t_list *src, t_list *dest)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		malloc_error(new);
	new->value = src->value;
	new->ordinal = src->ordinal;
	new->next = dest->next;
	new->prev = dest;
	dest->next->prev = new;
	dest->next = new;
	return ;
}

t_list	*search_tail(t_list	*stack)
{
	while (stack->next->ordinal != -1)
		stack = stack->next;
	return (stack);
}
