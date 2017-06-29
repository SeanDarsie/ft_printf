/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory_addrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:59:23 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/29 12:49:55 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*format_ptr_addr(void *addr)
{
	unsigned long	to_print;
	char			*recv;
	char			*tmp;

	to_print = (unsigned long)addr;
	recv = us_longlong_toa_base(to_print, 16);
	tmp = recv;
	recv = ft_strjoin("0x", recv);
	free(tmp);
	return (recv);
}

void	reset_flags(t_val *ret)
{
	ret->fmt->width = 0;
	ret->fmt->precision = 0;
	ret->flag = 0;
	ret->prec_case = 0;
	ret->no_spec = 1;
	ret->fmt->spec = '\0';
	ret->wild_prec = 0;
	ret->wild_width = 0;
	ret->prec_case = 0;
	ft_bzero(ret->fmt->flag, 6);
	ft_bzero(ret->fmt->length, 3);
	ft_bzero(ret->mid_str, ft_strlen(ret->mid_str));
	ft_bzero(ret->final_string, ft_strlen(ret->final_string));
}

int		check_no_spec(char *fmt, t_val *ret)
{
	int	g;

	g = 0;
	while (fmt[g] && fmt[g] != '\%')
	{
		if (SPEC(fmt[g++]))
			ret->no_spec = 0;
	}
	if (ft_strchr(fmt, '*'))
		return (1);
	if (ret->no_spec == 1)
		return (1);
	return (0);
}

char	*insert_str(char *str, char *dst, int beg, int len)
{
	int		i;
	int		k;
	char	*ret_str;
	int		str_len;

	i = 0;
	k = 0;
	str_len = (ft_strlen(str) + ft_strlen(dst));
	ret_str = (char*)malloc(str_len + 1);
	while (i < beg)
	{
		ret_str[i] = str[i];
		i++;
	}
	while ((i - beg) < len)
		ret_str[i++] = dst[k++];
	k = i - k;
	while (str[k] != '\0')
		ret_str[i++] = str[k++];
	ret_str[i] = '\0';
	return (ret_str);
}

void	print_final_product(t_val *ret)
{
	ret->str_len = ft_strlen(ret->mid_str);
	precision(ret);
	handle_hash(ret);
	if (ft_strchr(ret->fmt->flag, '-'))
		ret->final_string =
			left_justify(ret->mid_str, ret->final_string);
	else if (ft_strchr(ret->fmt->flag, '0') && ft_strchr(ret->mid_str, '+'))
		ret->final_string = insert_zeros(ret->mid_str, 1,
				ret->fmt->width - ft_strlen(ret->mid_str));
	else
		ret->final_string =
			right_justify(ret->mid_str, ret->final_string);
	if (check_zero(ret) == 1 && ft_strchr(ret->fmt->flag, '#'))
		ret->final_string = replace_beg(ret);
	if (ret->flag && ret->prec_case)
		ret->final_string = make_string(' ', ret->fmt->width);
	ret->print_func(ret->final_string);
	ret->r += ft_strlen(ret->final_string);
}
