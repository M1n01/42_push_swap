/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:51:14 by minabe            #+#    #+#             */
/*   Updated: 2023/04/07 18:10:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	is_chunk(t_list *stack)
{
	if (ABS(stack->next->ordinal - stack->next->next->ordinal) < 3)
		return (true);
	return (false);
}

long	chunk_len(t_list *stack)
{
	long	count;

	count = 0;
	while (is_chunk(stack))
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

// void	chunk_sort(t_list *stack1, t_list *stack2, long chunk_size)
// {
// 	long	i;
// 	long	steps;
// 	t_list	*find;

// 	i = 0;
// 	if (chunk_size == 2 && stack1->next->ordinal > stack1->next->next->ordinal)
// 	{
// 		swap(stack1);
// 		print_command(SA);
// 	}
// 	else if (chunk_size == 3)
// 	{
// 		t_list	*midiam = 
// 	}
// 	return ;
// }

void	sort2(t_list *stack1, t_list *stack2)
{
	while (!is_sorted(stack1, ASC) || stack_size(stack2) > 0)
	{
		// stack2とstack1のtailや先頭と比較
		if (search_tail(stack1)->ordinal == stack2->next->ordinal - 1 || stack1->next->ordinal == stack2->next->ordinal + 1)
		{
			push(stack2, stack1);
			print_command(PA);
			rotate(stack1);
			print_command(RA);
		}
		// sortedならrotate
		if (stack1->next->ordinal - search_tail(stack1)->ordinal == 1)
		{
			rotate(stack1);
			print_command(RA);
		}
		// individualならpush
		else if (ABS(stack1->next->ordinal - search_tail(stack1)->ordinal) >= 3 && ABS(stack1->next->ordinal - stack1->next->next->ordinal) >= 3)
		{
			push(stack1, stack2);
			print_command(PB);
		}
		// chunkならsort
		// 以下変更の必要あり.
		else if (is_chunk(stack1))
		{
			puts("[chunk]");
			size_t	chunk_size = chunk_len(stack1);
			printf("chunk_size: %ld\n", chunk_size);
			// chunk_sort(stack1, stack2, chunk_size);
			break ;
		}
		else
		{
			push(stack1, stack2);
			print_command(PB);
			t_list	*find = search_ordinal(stack1, stack2->next->ordinal + 1);
			long	steps = cal_steps(stack1, find);
			rotate_min_steps(stack1, steps, 'A');
			push(stack2, stack1);
			print_command(PA);
		}
	}
	return ;
}