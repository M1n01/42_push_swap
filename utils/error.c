/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:49:56 by minabe            #+#    #+#             */
/*   Updated: 2023/03/10 16:27:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

void	malloc_error(void *p)
{
	safer_free(p);
	ft_printf("Error\n");
	exit(1);
}

void	safer_free(void *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

void	lstclear(t_list *stack)
{
	t_list	*p;
	t_list	*head;

	if (stack == NULL)
		return ;
	// puts("lstclear1");
	head = stack;
	while (stack->next != head)
	{
		p = stack->next;
		// puts("lstclear2");
		lstdelone_node(stack);
		stack = p;
	}
	// puts("lstclear3");
	stack = NULL;
	return ;
}
