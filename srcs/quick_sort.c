/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:16:09 by minabe            #+#    #+#             */
/*   Updated: 2022/10/23 20:29:07 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../include/push_swap.h"

void	phase1(t_list *stack1, t_list *stack2, size_t value)
{
	size_t	i;
	t_list	*find;

	i = 0;
	while (i < value)
	{
		find = search_smaller(stack1, value);
		move_find_to_second(stack1, find);
		push(stack1, stack2);
		ft_printf("pb\n");
		i++;
	}
}
