/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:26:27 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:29:39 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		numlen(int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	write_neg(char *s, int num, int base)
{
	int	len;

	len = numlen(num, base);
	num *= -1;
	s[len] = '\0';
	len--;
	while (num >= 1)
	{
		s[len] = '0' + (num % base);
		len--;
		num /= base;
	}
	s[0] = '-';
}

void	write_big(char *s, int num, int base)
{
	char	*numbers;
	int		len;

	numbers = "0123456789ABCDEF";
	len = numlen(num, base);
	s[len] = '\0';
	len--;
	while (num)
	{
		s[len] = numbers[(num % base)];
		num /= base;
		len--;
	}
}

char	*edgecases(int n)
{
	char	*num;

	if (n == 0)
	{
		num = (char*)malloc(sizeof(char) * 2);
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	else
	{
		num = (char*)malloc(sizeof(char) * 12 + 1);
		num = "-2147483648";
		return (num);
	}
	return (num);
}

char	*ft_itoa_base(int value, int base)
{
	char	*num;
	int		len;

	len = numlen(value, base);
	if (value == 0 || value == -2147483648)
	{
		num = edgecases(value);
		return (num);
	}
	if (base < 2 || base > 16)
		return (0);
	if (base != 10 && value < 0)
		value *= -1;
	num = (char*)malloc(sizeof(char) * len + 1);
	number_set(num, value, base, len);
	return (num);
}
