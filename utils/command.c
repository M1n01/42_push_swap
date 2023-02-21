/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:43:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	command1(t_list *stack, char *str)
{
	// if (str == "sa" || str == "sb")
	// {
	// 	swap(stack);
	// 	ft_printf("%s\n", str);
	// }
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb"))
	{
		rotate(stack);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb"))
	{
		rev_rotate(stack);
		ft_printf("%s\n", str);
	}
	else
		printf("Nothing\n");
}

void	command2(t_list *stack1, t_list *stack2, char *str)
{
	// if (str == "ss")
	// {
	// 	swap(stack1);
	// 	swap(stack2);
	// 	ft_printf("%s\n", str);
	// }
	if (!ft_strcmp(str, "rr"))
	{
		rotate(stack1);
		rotate(stack2);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate(stack1);
		rev_rotate(stack2);
		ft_printf("%s\n", str);
	}
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
	{
		push(stack1, stack2);
		ft_printf("%s\n", str);
	}
	else
		printf("Nothing\n");
}