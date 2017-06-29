/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:42:10 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:18:46 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		count_digits_long_long(long long val, long long base)
{
	int	i;

	i = 0;
	if (val < 0)
	{
		val *= -1;
		i = 1;
	}
	while (val)
	{
		i++;
		val /= base;
	}
	return (i);
}

char	*edge_cases_big(long long n)
{
	char	*num;

	if (n == 0)
	{
		num = ft_strnew(2);
		num[0] = '0';
	}
	if (n == LLONG_MIN)
	{
		num = (char*)malloc(22);
		num = "-9223372036854775808";
	}
	return (num);
}

char	*ft_longtoa_base(long long val, long long base)
{
	char	*num;
	char	*digits;
	int		len;

	if (val == 0 || val == LLONG_MIN)
		return (edge_cases_big(val));
	digits = "0123456789ABCDEF";
	len = count_digits_long_long(val, base);
	num = (char *)malloc(len + 1);
	if (val < 0)
	{
		val *= -1;
		num[0] = '-';
	}
	num[len] = '\0';
	len--;
	while (val && len >= 0 && num[len] != '-')
	{
		num[len--] = digits[(val % base)];
		val /= base;
	}
	return (num);
}

char	*us_longlong_toa_base(unsigned long long val, long long base)
{
	char	*num;
	char	*digits;
	int		len;

	if (val == 0)
		return (uns_long_edge_cases(val));
	digits = "0123456789ABCDEF";
	len = count_uns_long_long(val, base);
	num = (char *)malloc(len + 1);
	num[len] = '\0';
	len--;
	while (val && len >= 0 && num[len] != '-')
	{
		num[len--] = digits[(val % base)];
		val /= base;
	}
	return (num);
}
