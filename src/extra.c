/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:26:02 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/28 16:19:26 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		change_to_unsigned_short_int(int s)
{
	while (s > 65535)
	{
		s -= 65536;
	}
	return (s);
}

char	*put_space_infront(char *str)
{
	char	*spc;
	char	*tmp;

	spc = (char*)malloc(ft_strlen(str) + 1);
	tmp = str;
	spc = ft_strjoin(" ", str);
	return (spc);
}

char	*left_justify(char *str, char *dst)
{
	char	*ret_str;
	int		i;

	i = 0;
	if (ft_strlen(str) >= ft_strlen(dst))
		return (str);
	ret_str = (char*)malloc(ft_strlen(dst));
	while (str[i])
	{
		ret_str[i] = str[i];
		i++;
	}
	while (dst[i])
	{
		ret_str[i] = dst[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

char	*right_justify(char *str, char *dst)
{
	char	*ret_str;
	int		i;
	int		len;

	i = 0;
	if (ft_strlen(str) >= ft_strlen(dst))
		return (str);
	if (ft_strchr(str, '-') && dst[0] == '0')
		return (insert_zeros(str, 1, (ft_strlen(dst) - ft_strlen(str))));
	ret_str = (char*)malloc(ft_strlen(dst));
	len = ft_strlen(dst) - ft_strlen(str);
	while (i < len)
	{
		ret_str[i] = dst[i];
		i++;
	}
	i = 0;
	while (str[i])
	{
		ret_str[len++] = str[i];
		i++;
	}
	ret_str[len] = '\0';
	return (ret_str);
}
