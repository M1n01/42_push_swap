/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/03/21 13:51:00 by minabe           ###   ########.fr       */
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
bool	command1(t_list *stack, int command);
bool	command2(t_list *stack1, t_list *stack2, int command);
bool	is_sorted(t_list *stack, int order);
void	print_ans(t_tool *tool, size_t turn);
int		ch_cmd(int cmd);
void	update_ans(t_tool *tool, size_t turn);
bool	exec_cmd(t_list *stack1, t_list *stack2, int cmd);
bool	is_detour(int cmd, t_tool *tool);
void	sort_long(t_list *stack1, t_list *stack2);
void	sort_middle(t_list *stack1, t_list *stack2);


#endif