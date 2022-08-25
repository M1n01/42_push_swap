/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2022/08/25 18:43:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	ssize_t			ordinal;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list	*init_stack(void);
t_list	*search_tail(t_list	*stack);
int		*make_array(int ac, char *av[]);
void	coordinate_compression(int *array, size_t *coordinate, size_t size);
t_list	*make_stack(int *array, size_t *coordinate, size_t size);
void	swap(t_list *big, t_list *small);
void	push(t_list *from, t_list *to);
void	rotate(t_list *stack);
void	rev_rotate(t_list *stack);
t_list	*lstdelone_node(t_list *trash);
void	lstcpy(t_list *src, t_list *dest);
t_list	*search_value(t_list *stack, ssize_t value);
void	error(void);
void	safer_free(void *p);

#endif