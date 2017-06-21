#include "../ft_printf.h"

void ft_putstr_lower(const char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 65 &&str[i] <= 90)
	ft_putchar(str[i] + 32);
      else
	ft_putchar(str[i]);
      i++;
    }
}

int count_digits(int val, int base)
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

int count_digits_int(int val, int base)
{
  int i;

  i = 0;
  if (val < 0)
    {
      i = 1;
      val *= -1;
    }
  while (val)
    {
      i++;
      val /= base;
    }
  return (i);
}

int change_to_signed_char(int s)
{
  while (s > 127 || s < -128)
    {
      if (s < 0)
	s += 256;
      else
	s -= 256;
    }
  return (s);
}

int change_to_unsigned_char(int s)
{
  while (s < 0)
    s+= 256;
  while (s > 255)
    {
	s -= 256;
    }
  return (s);
}
