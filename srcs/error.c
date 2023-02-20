/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:49:56 by minabe            #+#    #+#             */
/*   Updated: 2022/10/23 23:17:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../include/push_swap.h"

void	malloc_error(void *p)
{
	safer_free(p);
	ft_printf("Error\n");
	exit(1);
}

void	safer_free(void *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
