/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:33:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"
# include "./utils.h"

#include <stdio.h>

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	push_b(t_list *stack1, t_list *stack2, size_t n);
size_t	count_rotate(t_list *stack, ssize_t n);
size_t	count_revrotate(t_list *stack, ssize_t n);
void	command1(t_list *stack, char *str);
void	command2(t_list *stack1, t_list *stack2, char *str);

#endif