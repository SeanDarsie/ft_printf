#include "../ft_printf.h"

void begin_caps_hex_values(t_val *ret, va_list ap)
{
  ret->print_func = &ft_putstr;
  if (ft_strlen(ret->fmt->length) == 2)
    {
      handle_hh_ll_hex(ret, ap, 16); // both are unsigned base 16;
      return;
    }   // h l j z are left
  if (ret->fmt->length[0] == '\0')
    handle_normal_int_hex(ret, ap, 16); //unsigned base 16
  if (ret->fmt->length[0] == 'z')
    handle_size_t_hex(ret, ap, 16); //unsigned can reuse the int version base 16
  if (ret->fmt->length[0] == 'l')
    handle_unsigned_long_hex(ret, ap, 16); //unsigned base 16
  if (ret->fmt->length[0] == 'h')
    handle_unsigned_short_hex(ret, ap, 16); //unsigned base 16
  if (ret->fmt->length[0] == 'j')
    handle_intmax_t_hex(ret, ap, 16); // unsigned base 16
}

void begin_unsigned_int_values(t_val *ret, va_list ap)
{
  ret->print_func = &ft_putstr;
  if (ft_strlen(ret->fmt->length) == 2)
    {
      handle_hh_ll_hex(ret, ap, 10); // both are unsigned; base 10
      return;
    }   // h l j z are left
  if (ret->fmt->length[0] == '\0')
    handle_normal_int_hex(ret, ap, 10); //unsigned base 10
  if (ret->fmt->length[0] == 'z')
    handle_size_t_hex(ret, ap, 10); //unsigned can reuse the int version base 10
  if (ret->fmt->length[0] == 'l')
    handle_unsigned_long_hex(ret, ap, 10); //unsigned base 10
  if (ret->fmt->length[0] == 'h')
    handle_unsigned_short_hex(ret, ap, 10); //unsigned base 10
  if (ret->fmt->length[0] == 'j')
    handle_intmax_t_hex(ret, ap, 10); // unsigned base 10
}

void begin_unsigned_octal_values(t_val *ret, va_list ap)
{
  ret->print_func = &ft_putstr;
  if (ft_strlen(ret->fmt->length) == 2)
    {
      handle_hh_ll_hex(ret, ap, 8); // both are unsigned; base 10
      return;
    }   // h l j z are left
  if (ret->fmt->length[0] == '\0')
    handle_unsigned_normal_int(ret, ap, 8); //unsigned base 10
  if (ret->fmt->length[0] == 'z')
    handle_size_t_hex(ret, ap, 8); //unsigned can reuse the int version base 10
  if (ret->fmt->length[0] == 'l')
    handle_unsigned_long_hex(ret, ap, 8); //unsigned base 10
  if (ret->fmt->length[0] == 'h')
    handle_unsigned_short_hex(ret, ap, 8); //unsigned base 10
  if (ret->fmt->length[0] == 'j')
    handle_intmax_t_hex(ret, ap, 8); // unsigned base 10
}

void begin_printing_pointer(t_val *ret, va_list ap)
{
  void *pointer;

  ret->print_func = ft_putstr_lower;
  pointer = va_arg(ap, void*);
  ret->mid_str = format_ptr_addr(pointer);
  print_final_product(ret);
  /* if (ft_strchr(ret->fmt->flag, '-')) */
  /*   ret->final_string = left_justify(recv, ret->final_string); */
  /* else */
  /*   ret->final_string = right_justify(recv, ret->final_string); */
  /* ret->print_func(ret->final_string); */
  /* ret->r += ft_strlen(ret->final_string); */
}

void handle_modulo(t_val *ret)
{
  char *to_print;

  to_print = "%";
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string = left_justify(to_print, ret->final_string);
  else
    ret->final_string = right_justify(to_print, ret->final_string);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}
