/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:36:47 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:33:53 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dispatch_args(char *format, va_list ap, t_val *ret)
{
	if (check_no_spec(format, ret) == 0)
		ret->mid_str = ft_strdup(format);
	decipher_flags(format, ret, ap);
	set_wild_flags(ret, format, ap);
	set_the_width(ret);
	if (ret->fmt->spec == 's')
		print_s(ret, ap);
	if (ret->fmt->spec == 'D' || ret->fmt->spec == 'd' || ret->fmt->spec == 'i')
		begin_ints(ret, ap);
	continue_dispatching(ret, ap);
}

char	*find_next_specifiers(char *fmt, t_val *ret, int i)
{
	int		k;
	int		g;
	char	*format;

	ret->flag = 0;
	g = 0;
	k = i + 1;
	while (fmt[k])
	{
		if (SPEC(fmt[k]) || fmt[k] == '\0')
		{
			format = ft_strsub(fmt, i + 1, (k - i));
			return (format);
		}
		k++;
	}
	return (ft_strdup(""));
}

void	gather_specs(char *fmt, t_val *ret)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			ret->format[count] = find_next_specifiers(fmt, ret, index);
			index += ft_strlen(ret->format[count]);
			count++;
		}
		index++;
	}
}

void	parse_fmt(char *fmt, va_list ap, t_val *ret)
{
	int		i;
	size_t	k;

	k = 0;
	i = 0;
	while (fmt[k])
	{
		if (fmt[k] == '%' && ret->format[i] != NULL)
		{
			if (ft_strchr(ret->format[i], '*'))
				ret->wild_width = 1;
			if (ret->format[i] != NULL)
				dispatch_args(ret->format[i], ap, ret);
			k += ft_strlen(ret->format[i++]);
			k++;
		}
		if (fmt[k] && k < ft_strlen(fmt) && fmt[k] != '%')
		{
			ft_putchar(fmt[k]);
			ret->r++;
		}
		if (fmt[k] != '%' && fmt[k])
			k++;
	}
}

int		ft_printf(char *fmt, ...)
{
	t_val	*ret;
	va_list	ap;
	int		i;

	i = 0;
	ret = (t_val*)malloc(sizeof(t_val));
	initialize_return_struct(ret);
	va_start(ap, fmt);
	gather_specs(fmt, ret);
	parse_fmt(fmt, ap, ret);
	free(ret->format);
	free(ret);
	va_end(ap);
	return (ret->r);
}
