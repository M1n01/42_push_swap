/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 16:02:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	sort_long(t_list *stack1, t_list *stack2)
{
	// printLists(stack1, stack2);
	set_stack(stack1, stack2);
	// printLists(stack1, stack2);
	stack_top_third_sort(stack1, stack2);
	stack_middle_third_sort(stack1, stack2);
	stack_bottom_third_sort(stack1, stack2);
	// printLists(stack1, stack2);
	return ;
}
