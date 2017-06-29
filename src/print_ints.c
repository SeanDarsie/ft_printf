/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:57:18 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/29 01:00:21 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_long_int(t_val *ret, va_list ap, int base)
{
	long	to_print;

	to_print = va_arg(ap, long);
	ret->mid_str = ft_longtoa_base(to_print, base);
	print_final_product(ret);
}

void	handle_intmax_t(t_val *ret, va_list ap, int base)
{
	intmax_t	to_print;

	to_print = va_arg(ap, intmax_t);
	ret->mid_str = ft_longtoa_base(to_print, base);
	print_final_product(ret);
}

void	handle_short_int(t_val *ret, va_list ap, int base)
{
	short	to_print;

	to_print = va_arg(ap, int);
	ret->mid_str = ft_itoa_base(to_print, base);
	print_final_product(ret);
}

void	handle_unsigned_normal_int(t_val *ret, va_list ap, int base)
{
	int				to_print;
	unsigned int	real;

	to_print = va_arg(ap, int);
	real = (unsigned int)to_print;
	if (to_print < 0)
	{
		real = to_print + 4294967295 + 1;
	}
	ret->mid_str = us_longlong_toa_base(to_print, base);
	print_final_product(ret);
}
