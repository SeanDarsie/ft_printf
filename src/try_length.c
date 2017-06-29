/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:03:03 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:46:41 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_ll(t_val *ret, va_list ap, long long int h, int base)
{
	h = va_arg(ap, long long);
	ret->mid_str = ft_longtoa_base(h, base);
	print_final_product(ret);
}

void	handle_hh_ll(t_val *ret, va_list ap, int base)
{
	int			i;
	long long	h;

	i = 0;
	h = 0;
	if (ret->fmt->length[0] == 'h')
	{
		i = va_arg(ap, int);
		i = change_to_signed_char(i);
		ret->mid_str = ft_itoa_base(i, base);
	}
	else
	{
		handle_ll(ret, ap, h, 10);
		return ;
	}
	print_final_product(ret);
}

void	handle_normal_int(t_val *ret, va_list ap, int base)
{
	int	to_print;

	to_print = va_arg(ap, int);
	ret->mid_str = ft_itoa_base(to_print, base);
	print_final_product(ret);
}

void	handle_size_t(t_val *ret, va_list ap, int base)
{
	size_t	to_print;

	to_print = va_arg(ap, size_t);
	ret->mid_str = us_longlong_toa_base(to_print, base);
	print_final_product(ret);
}

void	begin_ints(t_val *ret, va_list ap)
{
	if (ret->wild_width == 1)
		handle_wild_card(ret, ap);
	if (ret->fmt->spec == 'D')
	{
		handle_long_int(ret, ap, 10);
		return ;
	}
	if (ft_strlen(ret->fmt->length) == 2)
	{
		handle_hh_ll(ret, ap, 10);
		return ;
	}
	if (ret->fmt->length[0] == '\0')
		handle_normal_int(ret, ap, 10);
	if (ret->fmt->length[0] == 'z')
		handle_intmax_t(ret, ap, 10);
	if (ret->fmt->length[0] == 'l')
		handle_long_int(ret, ap, 10);
	if (ret->fmt->length[0] == 'h')
		handle_short_int(ret, ap, 10);
	if (ret->fmt->length[0] == 'j')
		handle_intmax_t(ret, ap, 10);
}
