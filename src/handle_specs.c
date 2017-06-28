#include "../ft_printf.h"


void handle_wild_card(t_val *ret, va_list ap)
{
  int len;
  char *tmp;
  
  len = va_arg(ap, int);
  if (len < 0 && !ft_strchr(ret->fmt->flag, '-'))
    {
      tmp = ret->fmt->flag;
      ret->fmt->flag = ft_strjoin("-", ret->fmt->flag);
      free(tmp);
      len *= - 1;
    }
  ret->fmt->width = len;
  set_the_width(ret);
  ret->wild_width = 0;
  begin_ints(ret, ap);
}

void set_wild_flags(t_val *ret, char *fmt, va_list ap)
{
  int i;
  int prec;

  i = 0;
  prec = 0;
  while (fmt[i])
    {
      if (fmt[i] == '.' && fmt[i + 1] == '*')
	{
	  ret->wild_prec = 1;
	  prec = va_arg(ap, int);
	}
      i++;
    }
  if (prec > 0)
    ret->fmt->precision = prec;
}

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
    }
  if (s)
    {
      tmp = ret->mid_str;
      ret->mid_str = ft_strdup(s);
      /* if (ret->wild_prec == 1 && ret->fmt->precision <= */
      /* 	  ft_strlen(ret->mid_str)) */
      /* 	{ */
      /* 	  printf("BLAARGSASDF   %zu\n", ret->fmt->precision); */
      /* 	  ret->mid_str[ret->fmt->precision] = '\0'; */
      /* 	} */
      free(tmp);
    }
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
  int c;
  
  if (ret->fmt->length[0] == 'l')
    {
      print_wint_t(ret, ap);
      return;
    }
  c = va_arg(ap, int);
  if (c == 0 && ret->fmt->width > 0)
    ret->r++;
  ret->print_func = ft_putstr;
  if (c == 0 && ret->fmt->width < 1)
    ret->r += 1;
  if (c == '\0' && ret->fmt->width > 1 && !ft_strchr(ret->fmt->flag, '0'))
    ret->final_string = make_string(' ', (ret->fmt->width - 1));
  if (c == '\0' && ret->fmt->width > 1 && ft_strchr(ret->fmt->flag, '0'))
    ret->final_string = make_string('0', (ret->fmt->width - 1));
  // printf("hi");
  ret->mid_str = make_string(c, 1);
  //printf("hi");
  
  print_final_product(ret);
}
