/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:21:58 by minabe            #+#    #+#             */
/*   Updated: 2023/04/05 12:42:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

t_info	*init_info(void)
{
	size_t	i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		malloc_error(info);
	info->tmp = malloc(sizeof(int) * (LIMIT_SHORT));
	if (info->tmp == NULL)
		malloc_error(info->tmp);
	i = 0;
	while (i < LIMIT_SHORT)
	{
		info->tmp[i] = -1;
		i++;
	}
	info->turn = LIMIT_SHORT;
	info->ans = NULL;
	info->pre = -1;
	return (info);
}

void	free_info(t_info *info)
{
	safer_free(info->tmp);
	safer_free(info->ans);
	safer_free(info);
}
