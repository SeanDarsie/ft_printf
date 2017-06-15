#include "../ft_printf.h"

void collect_precision(char *fmt, t_val *ret)
{
  int i;
  int k;
  char *prec;

  i = 0;
  k = 0;
  prec = (char*)malloc(10);
  ft_bzero(prec, 10);
  if (!ft_strchr(fmt, '.'))
    return;
  while(fmt[i] != '.')
    i++;
  i++;
  while (fmt[i] >= '0' && fmt[i] <= '9' && fmt[i])
    {
      prec[k] = fmt[i];
      k++;
      i++;
    }
  prec[k] = '\0';
  ret->fmt->precision = ft_atoi(prec);
  //  printf("   %d\n", ret->fmt->precision);
}

void decipher_spec(char *fmt, t_val *ret)
{
  int i;
  int k;

  i = 0;
  while (fmt[i])
    {
      k = 0;
      while (ret->specifiers[k])
	{
	  if (fmt[i] == ret->specifiers[k])
	    ret->fmt->spec = fmt[i];
	  k++;
	}
      i++;
    }
  collect_precision(fmt, ret);
}

void decipher_length(char *fmt, t_val *ret)
{
  int i;
  int k;
  int l;
  //char *length;

  i = 0;
  l = 0;
  k = 0;
  // length = (char*)malloc(35);
  while (fmt[k])
    {
      i = 0;
      while (ret->length[i])
	{
	  if (fmt[k] == ret->length[i])
	    {
	      ret->fmt->length[l] = fmt[k];
	      l++;
	    }
	  i++;
	}
      k++;
    }
  // length[l] = '\0';
  decipher_spec(fmt, ret);
}

void decipher_width(char *fmt, t_val *ret)
{
  int i;
  int k;
  char *number;

  ret->fmt->precision = 1;
  number = (char*)malloc(100);
  ft_bzero(number, 20);
  i = 0;
  k = 0;
  while (fmt[i])
    {
      if (fmt[i] >= '0' && fmt[i] <= '9')
	{
	  while (fmt[i] >= '0' && fmt[i] <= '9' && fmt[i])
	    {
	      number[k] = fmt[i];
	      k++;
	      i++;
	    }
	  ret->fmt->width = ft_atoi(number);
	  break;
	}
      i++;
    }
  decipher_length(fmt, ret);
}

void decipher_flags(char *fmt, t_val *ret)
{  
  int i;
  int k;

  k = 0;
  i = 0;
  while (fmt[i])
    {
      if (fmt[i] > '0' && fmt[i] <= '9')
	break;
      if (CHECK_FLAGS(fmt[i]))
	{
	  while (CHECK_FLAGS(fmt[i]))
	    {
	      ret->fmt->flag[k] = fmt[i];
	      k++;
	      i++;
	    }
	  break;
	}
      i++;
    }
  decipher_width(fmt, ret);
}
