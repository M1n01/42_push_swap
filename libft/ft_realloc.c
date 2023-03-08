/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:09:31 by minabe            #+#    #+#             */
/*   Updated: 2023/02/25 14:02:00 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"

void	*ft_realloc(void *p, size_t size)
{
	void	*new_data;

	new_data = NULL;
	if (size == 0)
	{
		size = 1;
		free(p);
		p = NULL;
	}
	if (p == NULL)
		return (malloc(size));
	new_data = malloc(size);
	if (!new_data)
	{
		free(new_data);
		exit(1);
	}
	ft_memcpy(new_data, p, size);
	free(p);
	return (new_data);
}
