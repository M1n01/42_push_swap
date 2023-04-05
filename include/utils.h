/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:11:08 by minabe            #+#    #+#             */
/*   Updated: 2023/04/05 12:42:15 by minabe           ###   ########.fr       */
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
t_list	*search_tail(t_list	*stack);
void	swap(t_list *stack);
void	push(t_list *from, t_list *to);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);
t_list	*lstdelone_node(t_list *trash);
void	lstcpy(t_list *src, t_list *dest);
void	malloc_error(void *p);
void	safer_free(void *p);
t_info	*init_info();
size_t	stack_size(t_list *stack);
void	print_command(int command);
// bool	is_swap(t_list *stack, t_list *stack2, int cmd);
// bool	is_rotate(t_list *stack, t_list *stack2, int cmd);
// bool	is_revrotate(t_list *stack, t_list *stack2, int cmd);
// bool	is_push(t_list *from, int cmd);
void	free_info(t_info *cmd);
ssize_t	count_rotate(t_list *stack, t_list *find);
t_list	*search_ordinal(t_list *stack, ssize_t value);
long	cal_steps(t_list *stack, t_list *find);
long	cal_min_steps_to_pivot(t_list *stack, ssize_t pivot);
void	rotate_min_steps(t_list *stack, long step);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
void	rotate_min_steps(t_list *stack, long step);

# endif