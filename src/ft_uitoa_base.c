
#include "../ft_printf.h"

char *edge_cases(unsigned int n)
{
  char *num;

  
  if (n == 0)
    {
      num = (char*)malloc(2);
      num[0] = '0';
      num[1] = '\0';
    }
  else
    {
      num = (char*)malloc(11);
      num = "4294967295\0";
    }
  return (num);
}

int count_uns_long_long(unsigned long long val, long long base)
{
  int i;

  i = 0;
  while (val)
    {
      i++;
      val /= base;
    }
  return (i);
}

char *uns_long_edge_cases(unsigned long long n)
{
  char *num;

  num = NULL;
   if (n == 0)
    {
      num = ft_strnew(2);
      num[0] = '0';
    }
  return (num);
}

char *ft_uitoa_base(unsigned int val, int base)
{
  char *num;
  char *digits;
  int len;

  if (val == 0 || val == 4294967295)
    return (edge_cases(val));
  digits =  "0123456789ABCDEF";
  len = count_digits(val, base);
  num = (char *)malloc(len + 1);
  num[len] = '\0';
  len--;
  while (val && len >= 0)
    {
      num[len--] = digits[(val % base)];
      val /= base;
    }
  return (num);
}
