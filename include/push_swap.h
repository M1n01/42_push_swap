/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/02/18 13:37:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

// 0 2 1 3 4ってな感じで最初に番兵ノードがきやす
typedef struct s_list
{
	int				value;
	ssize_t			ordinal;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list	*make_stack(int ac, char *av[]);
int		*make_array(int ac, char *av[]);
ssize_t	*compression(int *array, size_t	size);
t_list	*init_stack(void);
t_list	*search_tail(t_list	*stack);
void	swap(t_list *big, t_list *small);
void	push(t_list *from, t_list *to);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);
void	move_find_to_second(t_list *stack, t_list *find);
void	phase1(t_list *stack1, t_list *stack2, size_t value);
t_list	*lstdelone_node(t_list *trash);
void	lstcpy(t_list *src, t_list *dest);
t_list	*search_smaller(t_list *stack, ssize_t value);
t_list	*search_value(t_list *stack, ssize_t value);
void	malloc_error(void *p);
void	safer_free(void *p);
void	push_swap(t_list *stack1, t_list *stack2, size_t size);

#endif