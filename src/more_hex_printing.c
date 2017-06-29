/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hex_printing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:54:12 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 14:54:39 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_unsigned_long_hex(t_val *ret, va_list ap, int base)
{
	long	to_print;

	to_print = va_arg(ap, long);
	ret->mid_str = us_longlong_toa_base(to_print, base);
	print_final_product(ret);
}

void	handle_intmax_t_hex(t_val *ret, va_list ap, int base)
{
	intmax_t	to_print;

	to_print = va_arg(ap, intmax_t);
	ret->mid_str = us_longlong_toa_base(to_print, base);
	print_final_product(ret);
}

void	handle_unsigned_short_hex(t_val *ret, va_list ap, int base)
{
	unsigned short	to_print;

	to_print = va_arg(ap, int);
	ret->mid_str = ft_uitoa_base(to_print, base);
	print_final_product(ret);
}
