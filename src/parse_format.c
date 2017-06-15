 /* header */

#include "../ft_printf..h"

int find_percent(char *fmt, int index, t_val *ret)
{
  
  
  while (fmt[indx])
    {
      if (fmt[index] == '%')
	return (index);
      ft_putchar(fmt[i]);
      ret->r++;
      i++;
    }
  return (0);
}

char *parse_fmt(char *fmt, va_list ap)
{
  int i;
  t_val *ret;

  ret = (t_val*)malloc(sizeof(t_val));
  ret->r = 0;
  i = find_percent(fmt, 0, ret);
  while (fmt[i])
    {
      if (fmt[i] == 'c')
	;/* print char; */
      if (fmt[i] == 's')
	hi; /* print string */
      if (fmt[i] == 'd')
	hi; /* print integer */
      i++;
    }
}
