#include "../ft_printf.h"


/* ( hh ) changes the arguments i, d, to SIGNED CHAR and the args u, o, x, X to UNSIGNED CHAR; */

/* ( h ) changes the arguements i, d to SHORT INT and the args to u, o, x X to UNSIGNED SHORT INT; */

/* ( l ) changes the args i, d to LONG INT the args: u, o, x, X to UNSIGNED LONG INT the arg c to WINT_T and the arg s to WCHAR_T*; */

/* ( ll ) changes the args i, d to LONG LONG INT the args: u o x X to UNSIGNED LONG LONG INT; */

/* ( j ) changes the args i, d to INTMAX_T the args u o x X to UINTMAX_T */

/* ( z ) changes the args i, d to SIZE_T and the args: u o x X to SIZE_T; */
//           ret->fmt->length

void handle_ll(t_val *ret, va_list ap, long long int h, int base)
{
  h = va_arg(ap, long long);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_longtoa_base(h, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_longtoa_base(h, base), ret->final_string);
  ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void handle_hh_ll(t_val *ret, va_list ap, int base)
{
  int i;
  long long h;

  i = 0;
  h = 0;
  if (ret->fmt->length[0] == 'h')
    {
      i = va_arg(ap, int);
      i = change_to_signed_char(i);
      if (strchr(ret->fmt->flag, '-'))
	ret->final_string =
	  left_justify(ft_itoa_base(i, base), ret->final_string);
      else
	ret->final_string =
	  right_justify(ft_itoa_base(i, base), ret->final_string);
      ft_putstr(ret->final_string);
      ret->r += ft_strlen(ret->final_string);
    }
  else
    handle_ll(ret, ap, h, 10);
}

void handle_normal_int(t_val *ret, va_list ap, int base)
{
  int to_print;

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

void handle_size_t(t_val *ret, va_list ap, int base)
{
  size_t to_print;

  to_print = va_arg(ap, size_t);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  else
    ret->final_string =
      right_justify(ft_us_longlong_toa_base(to_print, base), ret->final_string);
  ft_putstr(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

void begin_ints(t_val *ret, va_list ap)
{
  if (ft_strlen(ret->fmt->length) == 2)
    {
      handle_hh_ll(ret, ap, 10);
      return;
    }   // h l j z are left
  if (ret->fmt->length[0] == '\0')
    handle_normal_int(ret, ap, 10);
  if (ret->fmt->length[0] == 'z')
    handle_size_t(ret, ap, 10);
  if (ret->fmt->length[0] == 'l')
    handle_long_int(ret, ap, 10);
  if (ret->fmt->length[0] == 'h')
    handle_short_int(ret, ap, 10);
  if (ret->fmt->length[0] == 'j')
    handle_intmax_t(ret, ap, 10);
}



/* int main() */
/* { */
/*   int i; */

/*   i = 128; */
/*   print_signed_char(i); */
/*   return (0); */
/* } */
