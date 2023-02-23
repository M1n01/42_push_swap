/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/02/23 22:16:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	command1(t_list *stack, char *str)
{
	if (str == "sa" || str == "sb")
	{
		swap(stack);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb"))
	{
		rotate(stack);
		ft_printf("%s\n", str);
	}
	else if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb"))
	{
		rev_rotate(stack);
		ft_printf("%s\n", str);
	}
	else
		printf("Nothing, %s\n", str);
}

void	command2(t_list *stackA, t_list *stackB, char *str)
{
	// if (str == "ss")
	// {
	// 	swap(stackA);
	// 	swap(stackB);
	// 	ft_printf("%s\n", str);
	// }
	if (!ft_strcmp(str, "rr"))
	{
		rotate(stackA);
		rotate(stackB);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate(stackA);
		rev_rotate(stackB);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
	{
		push(stackA, stackB);
		ft_printf("%s\n", str);
	}
	else
		printf("Nothing\n");
}