

#include "../ft_printf.h"

void initialize_return_struct(t_val *ret)
{
  //  ret = (t_val*)malloc(sizeof(t_val));
  ret->r = 0;
  ret->specifiers = (char*)malloc(20);
  ret->specifiers = "sSpdDioOuUxXcC";
  ret->flags = (char*)malloc(5);
  ret->flags = "#O-+ ";
  ret->length = (char*)malloc(20);
  ret->length = "hljz";
  ret->format = (char**)malloc(sizeof(char*) * 50);
  ret->fmt = (t_form*)malloc(sizeof(t_form));
  ret->fmt->length = ft_strnew(5);
  ret->fmt->flag = (char*)malloc(20);
  ret->fmt->width = 0;
  ret->fmt->precision = 0;
  /* ft_strnew(10); */
  ret->print_func = &ft_putstr_lower;
}

void put_us_int(unsigned int n)
{
  if (n == 4294967295)
    {
      ft_putchar('4');
      n -= 4000000000;
    }
  if (n / 10 >= 1)
    put_us_int(n / 10);
  ft_putchar('0' + (n % 10));
}

void *ft_bspace(void *b, size_t size)
{
  size_t i;
  char *s;

  i = -1;
  s = (char*)b;
  while (i++ < size)
    s[i] = ' ';
  return (b);
}

/* void ft_fill_with(char *b, char c, size_t size) */
/* { */
/*   size_t i; */
/*   char *s; */

/*   i = -1; */
/*   s = (char*)b; */
/*   while (i < size) */
/*     s[i++] = c; */
/*   return (b); */
/* } */

char *make_string(char c, int len)
{
  char *ret;
  int  i;

  i = 0;
  ret = ft_strnew(len); 
  while (i < len)
    {
      ret[i] = c;
      i++;
    }
  return (ret);
}


/* void	ft_be_any(void *s, char c,  int n) */
/* { */
/*   size_t size; */

/*   size = (size_t)n; */
/*   ft_memset(s, c, size); */
/* } */





/* int main() */
/* { */
/*   unsigned int s = 4294967295; */
/*   put_us_int(s); */
/*   return (0); */
/* } */
