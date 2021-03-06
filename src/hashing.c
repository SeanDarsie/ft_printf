/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:43:29 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:40:16 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	hex_hash(t_val *ret)
{
	if (ret->fmt->spec != 'x' && ret->fmt->spec != 'X')
		return ;
	if (ret->fmt->precision == 0 && ft_strchr(ret->fmt->flag, '0') &&
			!ft_strchr(ret->fmt->flag, '-'))
		return ;
	if (ret->flag == 0)
		ret->mid_str = ft_strjoin("0X", ret->mid_str);
}

void	octal_hash(t_val *ret)
{
	if (ret->fmt->spec != 'o' && ret->fmt->spec != 'O')
		return ;
	if (ret->mid_str[0] == '0' && ft_strlen(ret->mid_str) == 1)
	{
		ret->flag = 0;
		return ;
	}
	if (ret->fmt->precision == 0 && ft_strchr(ret->fmt->flag, '0'))
		return ;
	if (ret->fmt->precision < (ret->str_len + 1))
		ret->mid_str = ft_strjoin("0", ret->mid_str);
}

int		check_zero(t_val *ret)
{
	if (ft_strchr(ret->fmt->flag, '0') &&
			ret->fmt->precision == 0 &&
			!ft_strchr(ret->fmt->flag, '-') &&
			(ret->fmt->spec != 's' || ret->fmt->spec != 'S' ||
			ret->fmt->spec != 'c' || ret->fmt->spec != 'C' ||
			ret->fmt->spec != 'p'))
		return (1);
	else
		return (0);
}

char	*replace_beg(t_val *ret)
{
	char	*ret_str;
	int		i;

	i = -1;
	ret_str = ft_strnew(ft_strlen(ret->final_string));
	while (ret->final_string[++i])
	{
		if ((ret->fmt->spec == 'o' || ret->fmt->spec == 'O') &&
				i == 0)
		{
			ret_str[0] = '0';
			i = 1;
		}
		if ((ret->fmt->spec == 'x' || ret->fmt->spec == 'X') &&
				i == 0)
		{
			ret_str[0] = '0';
			ret_str[1] = 'X';
			i = 2;
		}
		ret_str[i] = ret->final_string[i];
	}
	ret_str[i] = '\0';
	return (ret_str);
}

void	handle_sign(t_val *ret)
{
	char	*tmp;

	if (ft_strchr(ret->fmt->flag, '+') && !ft_strchr(ret->mid_str, '-'))
	{
		tmp = ret->mid_str;
		ret->mid_str = ft_strjoin("+", ret->mid_str);
		free(tmp);
	}
	if (ft_strchr(ret->mid_str, '-') || ft_strchr(ret->mid_str, '+'))
	{
		tmp = ret->mid_str;
		ret->mid_str =
			insert_zeros(ret->mid_str, 1,
					(ret->fmt->precision) - ft_strlen(ret->mid_str) + 1);
		return ;
	}
	if (ret->fmt->precision > ft_strlen(ret->mid_str))
		ret->mid_str = insert_zeros(ret->mid_str, 0,
				(ret->fmt->precision) - ft_strlen(ret->mid_str));
}
