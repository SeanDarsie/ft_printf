/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:21:21 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:14:50 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_the_flags(t_val *ret)
{
	int	i;
	int	len;

	i = 0;
	len = ret->fmt->width;
	if (ret->fmt->precision > ret->fmt->width)
		len = ret->fmt->precision;
	else
		len = ret->fmt->width;
	if (ft_strchr(ret->fmt->flag, '0'))
		ret->final_string = make_string('0', len);
	else
		ret->final_string = make_string(' ', len);
}

void	set_the_width(t_val *ret)
{
	int	len;

	len = 0;
	if (ret->fmt->width > 0)
		len = ret->fmt->width;
	if (ft_strchr(ret->fmt->flag, '0') &&
			ret->fmt->precision == 0 &&
			!ft_strchr(ret->fmt->flag, '-') &&
			(ret->fmt->spec != 's' || ret->fmt->spec != 'S' ||
			ret->fmt->spec != 'c' || ret->fmt->spec != 'C' ||
			ret->fmt->spec != 'p'))
		ret->final_string = make_string('0', len);
	else
		ret->final_string = make_string(' ', len);
}

void	star_width(t_val *ret, va_list ap, char *fmt)
{
	int	i;
	int	wide;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '*' && fmt[i - 1] != '.')
		{
			wide = va_arg(ap, int);
			if (wide < 0)
			{
				if (!ft_strchr(ret->fmt->flag, '-'))
					ret->fmt->flag = ft_strjoin("-", ret->fmt->flag);
				wide *= -1;
			}
			ret->fmt->width = (size_t)wide;
		}
		i++;
	}
}
