#include "../ft_printf.h"

void handle_the_flags(t_val *ret)
{
  int i;
  int len;

  i = 0;
  len = ret->fmt->width;
  if (ret->fmt->precision > ret->fmt->width)
    len = ret->fmt->precision;
  else
    len = ret->fmt->width;
  // ft_printf("%s\n", ret->fmt->flag);
  if (ft_strchr(ret->fmt->flag, '0'))
    ret->final_string = make_string('0', len);
  else
    ret->final_string = make_string(' ', len);
  //printf("%s\n", ret->fmt->flag);
  //printf("%s\n", ret->final_string);
}

void set_the_width(t_val *ret)
{
  //  printf("width: %d\tprec: %d\n", ret->fmt->width, ret->fmt->precision);
  if (ret->fmt->width > 0)
    {
      if (ret->fmt->precision > ret->fmt->width)	
	ret->final_string = (char*)malloc(ret->fmt->precision);
      else
	ret->final_string = (char*)malloc(ret->fmt->width + 1);
    }
   handle_the_flags(ret);
}

