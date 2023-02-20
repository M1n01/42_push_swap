/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:34:45 by minabe            #+#    #+#             */
/*   Updated: 2023/02/18 13:36:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../include/push_swap.h"

#include <stdio.h>

int	main(int ac, char *av[])
{
	t_list	*stack1;
	t_list	*stack2;

	stack1 = make_stack(ac, av);
	printf("stack1: ");
	for (int i = 0; i < ac; i++)
		printf("%zd ", stack1[i].ordinal);
	puts("");
	stack2 = init_stack();
	push_swap(stack1, stack2, ac - 1);
	// system("leaks -q push_swap");
	return (0);
}
