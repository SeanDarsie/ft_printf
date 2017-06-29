/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hash_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:40:01 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:37:07 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*sub_zero(char *str)
{
	char	*ret_str;
	int		i;
	int		k;

	i = 0;
	k = 2;
	ret_str = ft_strnew(ft_strlen(str) + 1);
	while (str[i] == ' ')
		i++;
	ret_str[0] = '0';
	ret_str[1] = 'X';
	while (str[i])
		ret_str[k++] = str[i++];
	ret_str[k] = '\0';
	return (ret_str);
}

char	*insert_zeros(char *str, int beg, int len)
{
	char	*ret_str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (len <= 0)
		return (ft_strdup(str));
	ret_str = ft_strnew((ft_strlen(str) + len));
	while (i < beg)
	{
		ret_str[i] = str[k++];
		i++;
	}
	while (i < (beg + len))
		ret_str[i++] = '0';
	while (str[k])
		ret_str[i++] = str[k++];
	ret_str[i] = '\0';
	return (ret_str);
}

char	*string_prec(t_val *ret)
{
	int		i;
	char	*ret_str;

	i = 0;
	if (ret->wild_prec == 1 && ret->fmt->precision == 0)
	{
		printf("%s\n", "GET LVL 7");
		ret->mid_str[0] = '\0';
		return (ret->mid_str);
	}
	if (ret->fmt->spec == 'c' || ret->fmt->spec == 'C' ||
			ret->fmt->spec == 'p')
		return (ret->mid_str);
	if (ret->fmt->precision > 0 &&
			ret->fmt->precision <= ft_strlen(ret->mid_str))
	{
		ret_str = ft_strsub(ret->mid_str, 0, ret->fmt->precision);
		return (ret_str);
	}
	if (ret->mid_str[0] == '\0' || (ret->wild_prec == 1 &&
				ret->fmt->precision == 0))
		return (make_string(' ', 0));
	return (ret->mid_str);
}

void	precision(t_val *ret)
{
	int		i;
	char	*prec;

	i = 0;
	if (ret->mid_str[0] == '0' && ft_strlen(ret->mid_str) == 1)
		ret->flag = 1;
	if (CHECK_INT(ret->fmt->spec))
	{
		handle_sign(ret);
		return ;
	}
	if (CHECK_SPEC(ret->fmt->spec))
	{
		ret->mid_str = string_prec(ret);
		return ;
	}
	if (ret->fmt->precision == 0)
		return ;
	prec = make_string('0', ret->fmt->precision);
	ret->mid_str = right_justify(ret->mid_str, prec);
	free(prec);
}

void	handle_hash(t_val *ret)
{
	if ((CHECK_INT(ret->fmt->spec)) &&
			ft_strchr(ret->fmt->flag, ' ') &&
			!ft_strchr(ret->fmt->flag, '+') &&
			!ft_strchr(ret->mid_str, '-'))
		ret->mid_str = ft_strjoin(" ", ret->mid_str);
	if (ret->fmt->spec != 'o' && ret->fmt->spec != 'O' &&
			ret->fmt->spec != 'x' && ret->fmt->spec != 'X')
		return ;
	if (!ft_strchr(ret->fmt->flag, '#'))
		return ;
	octal_hash(ret);
	hex_hash(ret);
}
