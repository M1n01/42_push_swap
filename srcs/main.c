/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:34:45 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 15:07:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

int	main(int ac, char *av[])
{
	t_list	*stack1;
	t_list	*stack2;

	stack1 = make_stack1(ac, av);
	stack2 = init_stack();
	push_swap(stack1, stack2, ac - 1);
	safer_free(stack2);
	// system("leaks -q a.out");
	return (0);
}
