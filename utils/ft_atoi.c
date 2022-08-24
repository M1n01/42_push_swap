/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:57:14 by minabe            #+#    #+#             */
/*   Updated: 2022/08/20 22:28:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"
#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	int			sign;
	size_t		i;
	size_t		len;
	long long	nbr;

	len = ft_strlen(str);
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	nbr = 0;
	while (i < len)
	{
		if (!ft_isdigit(str[i]) || nbr < INT_MIN || INT_MAX < nbr)
			error();
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr *= sign;
	return ((int)nbr);
}
