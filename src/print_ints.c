#include "../ft_printf.h"

void handle_long_int(t_val *ret, va_list ap, int base)
{
  long to_print;

  to_print = va_arg(ap, long);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_longtoa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_longtoa_base(to_print, base), ret->final_string);
 ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void  handle_intmax_t(t_val *ret, va_list ap, int base)
{
  intmax_t to_print;

  to_print = va_arg(ap, intmax_t);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_longtoa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_longtoa_base(to_print, base), ret->final_string);
 ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void  handle_short_int(t_val *ret, va_list ap, int base)
{
  short to_print;

  to_print = va_arg(ap, int);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_itoa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_itoa_base(to_print, base), ret->final_string);
  ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}
