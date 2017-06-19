#include "../ft_printf.h"

void hex_hash(t_val *ret)
{
  if (ret->fmt->spec != 'x' && ret->fmt->spec != 'X')
    return;
  if (!ft_strchr(ret->fmt->flag, '0'))
    ret->mid_str = ft_strjoin("0X", ret->mid_str);
}

void octal_hash(t_val *ret)
{
  int i;

  i = 0;
  if (ret->fmt->spec != 'o' && ret->fmt->spec != 'O')
    return;
  if (ret->str_len < ret->fmt->width &&
      !ft_strchr(ret->fmt->flag, '0'))
    ret->mid_str = ft_strjoin("0", ret->mid_str);
}

int check_zero(t_val *ret)
{
  if (ft_strchr(ret->fmt->flag, '0') &&
      ret->fmt->precision == 0 &&
      /* ret->fmt->width > ret->str_len && */
      !ft_strchr(ret->fmt->flag, '-') &&
      (ret->fmt->spec != 's' || ret->fmt->spec != 'S' ||
       ret->fmt->spec != 'c' || ret->fmt->spec != 'C' ||
       ret->fmt->spec != 'p'))    
    return (1);
  else
    return (0);
}

char *replace_beg(t_val *ret)
{
  char *ret_str;
  int i;

  i = 0;
  ret_str = ft_strnew(ft_strlen(ret->final_string));
  while (ret->final_string[i])
    {
      if ((ret->fmt->spec == 'o' || ret->fmt->spec == 'O') &&
	  i == 0)
	{
	  ret_str[0] = '0';
	  i = 1;
	}
      if ((ret->fmt->spec == 'x' || ret->fmt->spec == 'X') &&
	   i == 0)
	{
	  ret_str[0] = '0';
	  ret_str[1] = 'X';
	  i = 2;
	}
      ret_str[i] = ret->final_string[i];
      i++;
    }
  ret_str[i] = '\0';
  return (ret_str);
}
