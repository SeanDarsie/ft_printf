#include "../ft_printf.h"


void print_s(t_val *ret, va_list ap)
{
  char *s;
  char *tmp;

  s = va_arg(ap, char*);
  if (!s)
    {
      tmp = ret->mid_str;
      ret->mid_str = ft_strdup("(null)");
      free(tmp);
      ret->r -= 5;
      print_final_product(ret);
      return;
    }
  tmp = ret->mid_str;
  ret->mid_str = ft_strdup(s);
  free(tmp);
  print_final_product(ret);
}

void print_wint_t(t_val *ret, va_list ap)
{
  /* int i; */
  int to_print;

  /* i = 0; */
  to_print = va_arg(ap, int);
  /* while (to_print[i] && i < 4) */
  /*   ret->mid_str[i] = to_print[i]; */
  ret->mid_str[0] = to_print;
  print_final_product(ret);
}


void print_c(t_val *ret, va_list ap)
{
  char c;

  /* if (ft_strlen(ret->fmt->length) < 2 && ret->fmt->length[0] == l) */
  /*   { */
  /*     print_wint_t(ret, ap);//print a w_int */
  /*     return; */
  /*   } */
  if (ret->fmt->length[0] == 'l')
    {
      print_wint_t(ret, ap);
      return;
    }
  c = va_arg(ap, int);
  ret->print_func = ft_putstr;
  if (c == '\0' && ret->fmt->width < 1)
    ret->r += 1;
  if (c == '\0' && ret->fmt->width == 2)
    ret->r++;
  if (c == '\0' && ret->fmt->width > 1 && !ft_strchr(ret->fmt->flag, '0'))
    ret->final_string = make_string(' ', (ret->fmt->width - 1));
  if (c == '\0' && ret->fmt->width > 1 && ft_strchr(ret->fmt->flag, '0'))
    ret->final_string = make_string('0', (ret->fmt->width - 1));
  ret->mid_str = make_string(c, 1);
  print_final_product(ret);
}
