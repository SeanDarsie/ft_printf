#include "../ft_printf.h"

void handle_long_int(t_val *ret, va_list ap, int base)
{
  long to_print;

  to_print = va_arg(ap, long);
  ret->mid_str = ft_longtoa_base(to_print, base);
  print_final_product(ret); 
  /* if (ft_strchr(ret->fmt->flag, '-')) */
 /*    ret->final_string = */
 /*      left_justify(ft_longtoa_base(to_print, base), ret->final_string); */
 /*  else */
 /*    ret->final_string = */
 /*      right_justify(ft_longtoa_base(to_print, base), ret->final_string); */
 /* ft_putstr(ret->final_string); */
 /*  ret->r += ft_strlen(ret->final_string); */
}

void  handle_intmax_t(t_val *ret, va_list ap, int base)
{
  intmax_t to_print;

  to_print = va_arg(ap, intmax_t);
  ret->mid_str = ft_longtoa_base(to_print, base);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_longtoa_base(to_print, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_longtoa_base(to_print, base), ret->final_string); */
  /* ft_putstr(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}

void  handle_short_int(t_val *ret, va_list ap, int base)
{
  short to_print;

  to_print = va_arg(ap, int);
  ret->mid_str = ft_itoa_base(to_print, base);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_itoa_base(to_print, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_itoa_base(to_print, base), ret->final_string); */
  /* ft_putstr(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}

void handle_unsigned_normal_int(t_val *ret, va_list ap, int base)
{
  int to_print;
  unsigned int real;
  
  to_print = va_arg(ap, int);
  real = (unsigned int)to_print;
  if (to_print < 0)
    {
      real =  to_print + 4294967295 + 1;
      printf("%u\n", real);
    }
  ret->mid_str = ft_us_longlong_toa_base(to_print, base);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = */
  /*     left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string); */
  /* else */
  /*   ret->final_string = */
  /*     right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string); */
  /* ft_putstr(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}
