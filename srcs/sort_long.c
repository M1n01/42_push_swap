/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:25:54 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 12:29:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	skip_sorted(t_list *stack1)
{
	while (stack1->next->next->ordinal - stack1->next->ordinal == 1)
	{
		rotate(stack1);
		print_command(RA);
	}
	rotate(stack1);
	print_command(RA);
}

void	sort_long(t_list *stack1, t_list *stack2)
{
	// printLists(stack1, stack2);
	set_stack(stack1, stack2);
	// printLists(stack1, stack2);
	// [stack2の上位半分をsortし、stack1に移動する]
	sort1(stack1, stack2);
	// [ソートしていないところまでスキップする]
	// skip_sorted(stack1);
	// printLists(stack1, stack2);
	// sort2(stack1, stack2);
	// rotate_min_steps(stack1, cal_steps(stack1, search_ordinal(stack1, 0)), 'A');
	// printLists(stack1, stack2);
	return ;
}
