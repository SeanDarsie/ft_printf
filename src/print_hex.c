#include "../ft_printf.h"

void handle_ll_hex(t_val *ret, va_list ap, long long int h, int base)
{
  h = va_arg(ap, long long);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_us_longlong_toa_base(h, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_us_longlong_toa_base(h, base), ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
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
      if (strchr(ret->fmt->flag, '-'))
	ret->final_string =
	  left_justify(ft_uitoa_base(i, base), ret->final_string);
      else
	ret->final_string =
	  right_justify(ft_uitoa_base(i, base), ret->final_string);
      ret->print_func(ret->final_string);
      ret->r += ft_strlen(ret->final_string);
    }
  else
    handle_ll_hex(ret, ap, h, base);
}

void handle_normal_int_hex(t_val *ret, va_list ap, int base)
{
  int to_print;

  to_print = va_arg(ap, int);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_uitoa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_uitoa_base(to_print, base), ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void handle_size_t_hex(t_val *ret, va_list ap, int base)
{
  size_t to_print;

  to_print = va_arg(ap, size_t);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
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
