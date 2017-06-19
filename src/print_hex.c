/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:29:52 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/17 13:29:54 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void handle_ll_hex(t_val *ret, va_list ap, long long int h, int base)
{
  h = va_arg(ap, long long);
  ret->mid_str = ft_us_longlong_toa_base(h, base);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_us_longlong_toa_base(h, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_us_longlong_toa_base(h, base), ret->final_string); */
  /* ret->print_func(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}

void handle_hh_ll_hex(t_val *ret, va_list ap, int base)
{
  int i;
  long long h;

  i = 0;
  h = 0;
  if (ret->fmt->length[0] == 'h')
    {
      i = va_arg(ap, int);
      i = change_to_unsigned_char(i);
      ret->mid_str = ft_uitoa_base(i, base);
      print_final_product(ret);
      /* if (strchr(ret->fmt->flag, '-')) */
      /* 	ret->final_string = */
      /* 	  left_justify(ft_uitoa_base(i, base), ret->final_string); */
      /* else */
      /* 	ret->final_string = */
      /* 	  right_justify(ft_uitoa_base(i, base), ret->final_string); */
      /* ret->print_func(ret->final_string); */
      /* ret->r += ft_strlen(ret->final_string); */
    }
  else
    handle_ll_hex(ret, ap, h, base);
}

void handle_normal_int_hex(t_val *ret, va_list ap, int base)
{
  int to_print;
  unsigned int real;

  to_print = 0;
  to_print = va_arg(ap, int);
  real = (unsigned int)to_print;
  if (to_print < 0)
    real =  to_print + 4294967295 + 1;
  ret->mid_str = ft_us_longlong_toa_base(real, base); // send this to the printing function that deals with the conflicts between precision and width and #
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_us_longlong_toa_base(real, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_us_longlong_toa_base(real, base), ret->final_string); */
  /* ret->print_func(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}

void handle_size_t_hex(t_val *ret, va_list ap, int base)
{
  size_t to_print;

  to_print = va_arg(ap, size_t);
  ret->mid_str = ft_us_longlong_toa_base(to_print, base);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string); */
  //ret->print_func(ret->final_string);
  //ret->r += ft_strlen(ret->final_string);
}

//size_t is fine int short long long long and char all need to be unsigned
void begin_hex_values(t_val *ret, va_list ap)
{
  ret->print_func = &ft_putstr_lower;
  if (ft_strlen(ret->fmt->length) == 2)
    {
      handle_hh_ll_hex(ret, ap, 16);
      return;
    }   // h l j z are left
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
