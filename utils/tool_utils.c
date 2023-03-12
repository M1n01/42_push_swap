/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:21:58 by minabe            #+#    #+#             */
/*   Updated: 2023/03/11 17:24:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

#include "../include/debug.h"

t_tool	*init_tool(void)
{
	size_t	i;
	t_tool	*tool;

	tool = malloc(sizeof(t_tool));
	if (!tool)
		malloc_error(tool);
	tool->tmp = malloc(sizeof(int) * (LIMIT_SHORT));
	if (tool->tmp == NULL)
		malloc_error(tool->tmp);
	i = 0;
	while (i < LIMIT_SHORT)
	{
		tool->tmp[i] = -1;
		i++;
	}
	tool->turn = LIMIT_SHORT;
	tool->ans = NULL;
	tool->pre = -1;
	return (tool);
}

void	free_tool(t_tool *tool)
{
	safer_free(tool->tmp);
	safer_free(tool->ans);
	safer_free(tool);
}
