/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_ordinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:08:35 by minabe            #+#    #+#             */
/*   Updated: 2023/04/10 12:24:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

bool	is_not_bottom(t_list *list, ssize_t pivot)
{
	if (list->ordinal < pivot)
		return (true);
	return (false);
}

bool	is_bottom(t_list *list, ssize_t pivot)
{
	if (list->ordinal > pivot)
		return (true);
	return (false);
}