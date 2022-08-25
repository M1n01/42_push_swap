/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:49:56 by minabe            #+#    #+#             */
/*   Updated: 2022/08/24 13:51:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../utils/include/libft.h"
#include "../utils/include/ft_printf.h"
#include "../include/push_swap.h"

void	error(void)
{
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
