#include "../ft_printf.h"


/* void smallfmt4(char fmt, va_list ap, t_val *ret) */
/* { */
/*   void *p; */
/*   char *s; */

/*   if (fmt == 'p') */
/*     { */
/*       p = va_arg(ap, p); */
/*       //somehow print the pointer */
/*     } */
/*   if (fmt == 'C') */
/*     { */
/*       s = va_arg(ap, char *); */
/*       ft_putstr(s); */
/*       ret->r++; */
/*     } */
/* } */

void smallfmt3(char fmt, va_list ap, t_val *ret)
{
  unsigned int u;

  if (fmt == 'u') // print unsigned int
    {
      u = va_arg(ap, unsigned int);
      put_us_int(u);
      ret->r += count_digits(u, 10);
    }
  if (fmt == 'o') // unsigned int in octal
    {
      u = va_arg(ap, unsigned int);
      ft_putstr_lower(ft_itoa_base(u, 8));
      ret->r += count_digits(u, 8);
      
    }
  if (fmt == 'O')
    {
      u = va_arg(ap, unsigned int);
      ft_putstr(ft_itoa_base(u, 8));
      ret->r += count_digits(u, 8);
    }
	//  smallfmt4(fmt, ap, ret);
}

void smallfmt2(char fmt, va_list ap, t_val *ret)
{
  unsigned int x;
  char *s;

  if (fmt == 'x')
    {
      x = va_arg(ap, unsigned int);      /* write the number(in hexadecimal) to the standard output and count how many chracters written   */
      s = ft_uitoa_base(x, 16);
      ft_putstr_lower(s);
      ret->r += count_digits(x, 16);
    }
   if (fmt == 'X')      /* write the number(in capital hexadecimal) to the standard output and count how many chracters written   */
    {
      x = va_arg(ap, unsigned int);
      s = ft_uitoa_base(x, 16);
      ft_putstr(s);
      ret->r += count_digits(x, 16);
    }
   if (fmt == 'D')
     {
       x = va_arg(ap, unsigned int);
       put_us_int(x);
       ret->r += count_digits(x, 10);
     }
   smallfmt3(fmt, ap, ret);
}

int smallfmt(char spec, va_list ap, t_val *ret)
{
  int d;
  char *s;

  d = 0;
  if (spec == 'c')
    {
      d = va_arg(ap, int);
      ft_putchar(d);
      ret->r++;
    }
  if (spec == 's')
    {
      s = va_arg(ap, char *);
      ft_putstr(s);
      ret->r += ft_strlen(s);
    }
  if (spec == 'd' || spec == 'i')
    {
      d = va_arg(ap, int);
      ft_putnbr(d);
      ret->r += count_digits(d, 10);
    }
  smallfmt2(spec, ap, ret);
  return (0);
}
