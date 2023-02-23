/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:11:08 by minabe            #+#    #+#             */
/*   Updated: 2023/02/23 22:16:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft.h"

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
void	swap(t_list *stack);
void	push(t_list *from, t_list *to);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);
void	move_find_to_second(t_list *stack, t_list *find);
t_list	*lstdelone_node(t_list *trash);
void	lstcpy(t_list *src, t_list *dest);
t_list	*search_smaller(t_list *stack, ssize_t value);
t_list	*search_value(t_list *stack, ssize_t value);
void	malloc_error(void *p);
void	safer_free(void *p);

# endif