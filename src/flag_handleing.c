/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handleing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:27:19 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:20:39 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	collect_precision(char *fmt, t_val *ret)
{
	int		i;
	int		k;
	char	*prec;

	i = 0;
	k = 0;
	prec = ft_strnew(30);
	if (!ft_strchr(fmt, '.'))
		return ;
	while (fmt[i] != '.')
		i++;
	i++;
	if (fmt[i] <= '0' || fmt[i] > '9')
		ret->prec_case = 1;
	while (fmt[i] >= '0' && fmt[i] <= '9' && fmt[i])
	{
		prec[k] = fmt[i];
		k++;
		i++;
	}
	prec[k] = '\0';
	ret->fmt->precision = ft_atoi(prec);
	free(prec);
}

void	decipher_spec(char *fmt, t_val *ret)
{
	int	i;
	int	k;

	i = 0;
	while (fmt[i])
	{
		k = 0;
		while (ret->specifiers[k])
		{
			if (fmt[i] == ret->specifiers[k])
				ret->fmt->spec = fmt[i];
			k++;
		}
		i++;
	}
	collect_precision(fmt, ret);
}

void	decipher_length(char *fmt, t_val *ret)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	l = 0;
	k = 0;
	while (fmt[k])
	{
		i = 0;
		while (ret->length[i])
		{
			if (fmt[k] == ret->length[i])
			{
				ret->fmt->length[l] = fmt[k];
				l++;
			}
			i++;
		}
		k++;
	}
	decipher_spec(fmt, ret);
}

void	decipher_width(char *fmt, t_val *ret)
{
	int		i;
	int		k;
	char	*number;

	number = ft_strnew(12);
	i = ft_strlen(ret->fmt->flag) - 1;
	k = 0;
	while (fmt[++i])
	{
		if (fmt[i] >= '0' && fmt[i] <= '9')
		{
			if (fmt[i - 1] == '.')
				break ;
			while (fmt[i] >= '0' && fmt[i] <= '9' && fmt[i])
			{
				number[k] = fmt[i];
				k++;
				i++;
			}
			ret->fmt->width = ft_atoi(number);
			break ;
		}
	}
	decipher_length(fmt, ret);
}

void	decipher_flags(char *fmt, t_val *ret, va_list ap)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] > '0' && fmt[i] <= '9')
			break ;
		if (CHECK_FLAGS(fmt[i]))
		{
			while (CHECK_FLAGS(fmt[i]))
			{
				ret->fmt->flag[k] = fmt[i];
				k++;
				i++;
			}
			break ;
		}
		i++;
	}
	star_width(ret, ap, fmt);
	decipher_width(fmt, ret);
}
