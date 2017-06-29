/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_dispatching.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:43:25 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/29 00:48:52 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	begin_caps_hex_values(t_val *ret, va_list ap)
{
	ret->print_func = &ft_putstr;
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

void	begin_unsigned_int_values(t_val *ret, va_list ap)
{
	ret->print_func = &ft_putstr;
	if (ft_strlen(ret->fmt->length) == 2)
	{
		handle_hh_ll_hex(ret, ap, 10);
		return ;
	}
	if (ret->fmt->length[0] == '\0')
		handle_hh_ll_hex(ret, ap, 10);
	if (ret->fmt->length[0] == 'z')
		handle_size_t_hex(ret, ap, 10);
	if (ret->fmt->length[0] == 'l')
		handle_unsigned_long_hex(ret, ap, 10);
	if (ret->fmt->length[0] == 'h')
		handle_unsigned_short_hex(ret, ap, 10);
	if (ret->fmt->length[0] == 'j')
		handle_intmax_t_hex(ret, ap, 10);
}

void	begin_unsigned_octal_values(t_val *ret, va_list ap)
{
	ret->print_func = &ft_putstr;
	if (ft_strlen(ret->fmt->length) == 2)
	{
		handle_hh_ll_hex(ret, ap, 8);
		return ;
	}
	if (ret->fmt->length[0] == '\0')
		handle_hh_ll_hex(ret, ap, 8);
	if (ret->fmt->length[0] == 'z')
		handle_size_t_hex(ret, ap, 8);
	if (ret->fmt->length[0] == 'l')
		handle_unsigned_long_hex(ret, ap, 8);
	if (ret->fmt->length[0] == 'h')
		handle_unsigned_short_hex(ret, ap, 8);
	if (ret->fmt->length[0] == 'j')
		handle_intmax_t_hex(ret, ap, 8);
}

void	begin_printing_pointer(t_val *ret, va_list ap)
{
	void	*pointer;

	ret->print_func = ft_putstr_lower;
	pointer = va_arg(ap, void*);
	if (pointer == 0x0 && ret->prec_case == 0)
	{
		ret->mid_str = ft_strdup("0x0");
		if (ft_strchr(ret->fmt->flag, '0'))
		{
			ret->mid_str = left_justify(ret->mid_str, ret->final_string);
			ret->print_func(ret->mid_str);
			return ;
		}
	}
	else
		ret->mid_str = format_ptr_addr(pointer);
	print_final_product(ret);
}

void	handle_modulo(t_val *ret)
{
	char	*to_print;

	to_print = "%";
	if (ft_strchr(ret->fmt->flag, '-'))
		ret->final_string = left_justify(to_print, ret->final_string);
	else
		ret->final_string = right_justify(to_print, ret->final_string);
	ret->print_func(ret->final_string);
	ret->r += ft_strlen(ret->final_string);
}
