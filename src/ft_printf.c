/* Header */

#include "../ft_printf.h"

void dispatch_args(char *format, va_list ap, t_val *ret)
{
  decipher_flags(format, ret);
  set_the_width(ret);
  if (ret->fmt->spec == 's')
    print_s(ret, ap);
  if (ret->fmt->spec == 'D' || ret->fmt->spec == 'd' || ret->fmt->spec == 'i')
    begin_ints(ret, ap);
  if (ret->fmt->spec == 'c' || ret->fmt->spec == 'C')
    print_c(ret, ap);
  if (ret->fmt->spec == 'x')
    begin_hex_values(ret, ap);
  if (ret->fmt->spec == 'X')
    begin_caps_hex_values(ret, ap);
  if (ret->fmt->spec == 'u' || ret->fmt->spec == 'U')
    begin_unsigned_int_values(ret, ap);
  if (ret->fmt->spec == 'o' || ret->fmt->spec == 'O')
    begin_unsigned_octal_values(ret, ap);
  if (ret->fmt->spec == 'p')
    begin_printing_pointer(ret, ap);
  if (ret->fmt->spec == '%')
    handle_modulo(ret);
  reset_flags(ret);
 }

char *find_next_specifiers(char *fmt, t_val *ret, int i)
{
  int k;
  int g;
  char *format;

  g = 0;
  k = i + 1;
  while (fmt[k])
    {
      g = 0;
      while (ret->specifiers[g])
	{
	  if (fmt[k] == ret->specifiers[g])
	    {
	      format = ft_strsub(fmt, i + 1, (k - i));
	      //	      printf("%s\n", format);
	      return (format);
	    }
	  g++;
	}
      k++;
    }
  return (NULL);
}

void gather_specs(char *fmt, t_val *ret)
{
  int index;
  int count;

  count = 0;
  index = 0;
  while (fmt[index])
    {
      if (fmt[index] == '%')
	{
	  ret->format[count] = find_next_specifiers(fmt, ret, index);
	  index += ft_strlen(ret->format[count]);
	  count++;
	}
      index++;
    }
}

void parse_fmt(char *fmt, va_list ap, t_val *ret)
{
  int i;
  size_t k;

  k = 0;
  i = 0;
  while(fmt[k])
    {
      if (fmt[k] == '%' && ret->format[i] != NULL)
	{
	  dispatch_args(ret->format[i], ap, ret);
	  k += ft_strlen(ret->format[i]);
	  k++;
	  i++;
	}
      if (fmt[k] && k < ft_strlen(fmt) && fmt[k] != '%')
	{
	  ft_putchar(fmt[k]);
	  ret->r++;
	}
      if (fmt[k] != '%' && fmt[k])
	k++;
    }
}

int ft_printf(char *fmt, ...)
{
  t_val *ret;
  va_list ap;
  int i;

  i = 0;
  ret = (t_val*)malloc(sizeof(t_val));
  initialize_return_struct(ret);
  va_start(ap, fmt);
  gather_specs(fmt, ret);
  parse_fmt(fmt, ap, ret);
  free(ret->format);
  free(ret);
  va_end(ap);
  return (ret->r);
 }

