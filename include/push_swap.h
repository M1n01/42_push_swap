/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/03/08 14:09:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft.h"
# include "./utils.h"

# define LIMIT_LESS6 12
# define LIMIT_OVER6 30

#include <stdio.h>

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	sort_short(t_list *stack1, t_list *stack2, t_tool *tool, size_t turn);
bool	command1(t_list *stack, int command);
bool	command2(t_list *stack1, t_list *stack2, int command);
bool	is_sorted(t_list *stack);
void	print_ans(t_tool *tool, size_t turn);


void	printList(t_list *stack);

#endif