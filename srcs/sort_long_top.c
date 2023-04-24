/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:40:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:18:34 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	top_sort(t_list *stack1, t_list *stack2, t_info *info)
{
	size_t	size;
	size_t	push_count;

	push_count = 0;
	size = stack_size(stack1) / 5;
	while (push_count < size)
	{
		find_min_and_pb(stack1, stack2, info);
		push_count++;
	}
	while (stack_size(stack2) > 0)
		record_command(stack1, stack2, info, PA);
}
