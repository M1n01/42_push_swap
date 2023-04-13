/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:11:08 by minabe            #+#    #+#             */
/*   Updated: 2023/04/14 00:18:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "./libft.h"

// 0 2 1 3 4ってな感じで最初に番兵ノードがきやす
typedef struct	s_list
{
	int				value;
	ssize_t			ordinal;
	ssize_t			pos;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct	s_info
{
	size_t	turn;
	int		*tmp;
	int		*ans;
	int		pre;
}				t_info;

typedef enum	e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_cmd;

t_list	*make_stack1(int ac, char *av[]);
int		*make_array(int ac, char *av[]);
ssize_t	*compression(int *array, size_t	size);
t_list	*init_stack(void);
t_list	*find_tail(t_list	*stack);

void	swap(t_list *stack);
void	push(t_list *from, t_list *to);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);

t_list	*lstdelone_node(t_list *trash);
void	lstcpy(t_list *src, t_list *dest);
void	malloc_error(void *p);
void	safer_free(void *p);
size_t	stack_size(t_list *stack);

void	print_command(int command);
bool	is_sorted(t_list *stack, int order);
void	print_ans(t_info *info);
int		ch_cmd(int command);
bool	exec_cmd(t_list *stack1, t_list *stack2, int command);
bool	is_detour(int cmd, t_info *info);

t_info	*init_info(void);
t_info	*init_info_long_ver(void);
void	free_info(t_info *cmd);

ssize_t	count_rotate(t_list *stack, t_list *find);
long	cal_steps(t_list *stack, t_list *find);
void	rotate_min_steps(t_list *stack, long step, int which_stack, t_info *info);

// t_list	*find_ordinal(t_list *stack, ssize_t value);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);

void	opt_swap(t_list *stack1, t_list *stack2, int command);

void	command(t_list *stack1, t_list *stack2, int command);
bool	is_middle(t_list *list, ssize_t pivot);
bool	is_bottom(t_list *list, ssize_t pivot);
bool	is_top(t_list *list, ssize_t pivot);
bool	is_swap(t_list *stack);
int		*add_ans(t_info *info, int command);
void	record_command(t_list *stack1, t_list *stack2, t_info *info, int cmd);
t_list	*find_min_more_than_pivot(t_list *stack, ssize_t pivot);

void	free_stack(t_list *stack);
void	ans_optimize(t_info *info);

void	find_max_and_pa(t_list *stack1, t_list *stack2, t_info *info);

# endif