#include "../ft_printf.h"


void print_s(t_val *ret, va_list ap)
{
  char *s;

  s = va_arg(ap, char*);
  ret->precision = NULL;
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string = left_justify(s, ret->final_string);
  else
    ret->final_string = right_justify(s, ret->final_string);
  ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

/* void prrint_wint_t(t_val *ret, va_list ap) */
/* { */
/*   wint_t to_print; */

/*   to_print = va_arg */
/* } */


void print_c(t_val *ret, va_list ap)
{
  char c;

  /* if (ft_strlen(ret->fmt->length) < 2 && ret->fmt->length[0] == l) */
  /*   { */
  /*     print_wint_t(ret, ap);//print a w_int */
  /*     return; */
  /*   } */
  c = va_arg(ap, int);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string[0] = c;
  else
    ret->final_string[ft_strlen(ret->final_string) - 1] = c;
  ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}
