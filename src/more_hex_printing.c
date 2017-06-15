#include "../ft_printf.h"


void handle_unsigned_long_hex(t_val *ret, va_list ap, int base)
{
  long to_print;

  to_print = va_arg(ap, long);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
  /* ft_putstr_lower("where"); */
}

void  handle_intmax_t_hex(t_val *ret, va_list ap, int base)
{
  intmax_t to_print;

  to_print = va_arg(ap, intmax_t);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void  handle_unsigned_short_hex(t_val *ret, va_list ap, int base)
{
  unsigned short to_print;

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
