/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:32 by minabe            #+#    #+#             */
/*   Updated: 2023/03/15 11:57:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

// static size_t	set_stack(t_list *stack1, t_list *stack2, t_tool *tool, size_t n);
// static size_t	count_rotate(t_list *stack, ssize_t n);
// static size_t	count_revrotate(t_list *stack, ssize_t n);

void	push_swap(t_list *stack1, t_list *stack2, size_t size)
{
	if (is_sorted(stack1, ASC))
		return ;
	if (size <= 6)
	{
		sort_short(stack1, stack2);
		return ;
	}
	sort_long(stack1, stack2);
	return ;
}
