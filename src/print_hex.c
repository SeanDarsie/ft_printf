/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:29:52 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/29 00:48:33 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	do_ll_hex(t_val *ret, va_list ap, long long int h, int base)
{
	h = va_arg(ap, long long);
	if (ret->fmt->spec == 'u' && ret->fmt->length[0] == '\0')
	{
		while (h > 4294967295)
			h -= 4294967296;
		while (h < 0)
			h += 4294967296;
	}
	ret->mid_str = us_longlong_toa_base(h, base);
	print_final_product(ret);
}

void	handle_hh_ll_hex(t_val *ret, va_list ap, int base)
{
	int			i;
	long long	h;

	i = 0;
	h = 0;
	if (ret->fmt->length[0] == 'h')
	{
		i = va_arg(ap, int);
		i = change_to_unsigned_char(i);
		ret->mid_str = ft_uitoa_base(i, base);
		print_final_product(ret);
	}
	else
		do_ll_hex(ret, ap, h, base);
}

void	handle_normal_int_hex(t_val *ret, va_list ap, int base)
{
	int				to_print;
	unsigned int	real;

	to_print = 0;
	to_print = va_arg(ap, int);
	real = (unsigned int)to_print;
	ret->mid_str = us_longlong_toa_base(real, base);
	print_final_product(ret);
}

void	handle_size_t_hex(t_val *ret, va_list ap, int base)
{
	size_t	to_print;

	to_print = va_arg(ap, size_t);
	ret->mid_str = us_longlong_toa_base(to_print, base);
	print_final_product(ret);
}

void	begin_hex_values(t_val *ret, va_list ap)
{
	ret->print_func = &ft_putstr_lower;
	if (ft_strlen(ret->fmt->length) == 2)
	{
		handle_hh_ll_hex(ret, ap, 16);
		return ;
	}
	if (ret->fmt->length[0] == '\0')
		handle_normal_int_hex(ret, ap, 16);
	if (ret->fmt->length[0] == 'z')
		handle_size_t_hex(ret, ap, 16);
	if (ret->fmt->length[0] == 'l')
		handle_unsigned_long_hex(ret, ap, 16);
	if (ret->fmt->length[0] == 'h')
		handle_unsigned_short_hex(ret, ap, 16);
	if (ret->fmt->length[0] == 'j')
		handle_intmax_t_hex(ret, ap, 16);
}
