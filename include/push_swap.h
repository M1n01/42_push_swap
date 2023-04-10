/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/04/08 16:32:39 by minabe           ###   ########.fr       */
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

#include "./debug.h"

# define LIMIT_SHORT 12
# define LIMIT_LONG 30
# define ASC 1
# define DESC 2

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	sort_short(t_list *stack1, t_list *stack2);

void	sort_long(t_list *stack1, t_list *stack2);
void	stack_top_third_sort(t_list *stack1, t_list *stack2);
void	stack_middle_third_sort(t_list *stack1, t_list *stack2);
void	stack_bottom_third_sort(t_list *stack1, t_list *stack2);

void	lstclear(t_list *stack);

#endif