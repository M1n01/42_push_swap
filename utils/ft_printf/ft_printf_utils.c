/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:45:09 by minabe            #+#    #+#             */
/*   Updated: 2022/10/23 20:31:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long long n)
{
	int	res;

	res = 0;
	if (n == INT_MIN)
	{
		n /= 10;
		res += ft_putnbr(n);
		res += ft_putchar('8');
		return (res);
	}
	if (n < 0)
	{
		res += ft_putchar('-');
		n *= -1;
		res += ft_putnbr(n);
		return (res);
	}
	if (n < 10)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_putnbr(n / 10);
	res += ft_putchar(n % 10 + '0');
	return (res);
}

int	put_str(char *s)
{
	size_t	i;
	int		res;

	if (s == NULL)
		return (put_str("(null)"));
	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}

int	put_ptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += put_str("0x");
	return (res + putnbr_hex(ptr, 'x'));
}
