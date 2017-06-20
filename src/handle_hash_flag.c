#include "../ft_printf.h"

char *sub_zero(char *str)
{
  char *ret_str;
  int  i;
  int k;

  i = 0;
  k = 2;
  ret_str = ft_strnew(ft_strlen(str) + 1);
  while (str[i] == ' ')
    i++;
  ret_str[0] = '0';
  ret_str[1] = 'X';
  while (str[i])
      ret_str[k++] = str[i++];
  ret_str[k] = '\0';
  return (ret_str);
}

char *insert_zeros(char *str, int beg, int len)
{
  char *ret_str;
  int i;
  int k;

  i = 0;
  k = 0;
  ret_str = ft_strnew((ft_strlen(str) + len));
  while (i < beg)
    {
      ret_str[i] = str[k++];
      i++;
    }
  while (i < (beg + len))
      ret_str[i++] = '0';
  while (str[k])
      ret_str[i++] = str[k++];
  ret_str[i] = '\0';
  return (ret_str);
}

char *string_prec(t_val *ret)
{
  int i;
  char *ret_str;

  i = 0;
  if (ret->fmt->spec == 'c' || ret->fmt->spec == 'C' ||
      ret->fmt->spec == 'p')
    return (ret->mid_str);
  if (ret->fmt->precision > 0 &&
      ret->fmt->precision <= ft_strlen(ret->mid_str))
    {
      ret_str = ft_strsub(ret->mid_str, 0 , ret->fmt->precision);
      return (ret_str);
    }
  else
    return (ret->mid_str);
  return (NULL);
}

void precision(t_val *ret)
{
  int i;
  char *prec;

  i = 0;
  if (ret->fmt->precision == 0)
    return;
  if (ret->fmt->spec == 's' || ret->fmt->spec == 'c' ||
      ret->fmt->spec == 'S' || ret->fmt->spec == 'C' ||
      ret->fmt->spec == 'p')
    {
      ret->mid_str = string_prec(ret);
      return;
    }
  prec = make_string('0', ret->fmt->precision);
  if (ft_strlen(ret->mid_str) > ft_strlen(prec))
    {
      free(prec);
      return;
    }
  else
    ret->mid_str = right_justify(ret->mid_str, prec);
}
  
  
void handle_hash(t_val *ret) //the hash flag is only relevant to the o x and X specifiers so let's assume we already checked for them
{
  if (!ft_strchr(ret->fmt->flag, '#'))
    return;
  /* if (!ft_strchr(ret->fmt->flag, '0')) */
  /*   { */
      octal_hash(ret);
      hex_hash(ret);
      return;
    
  
  /* if ((ret->fmt->spec == 'o' || ret->fmt->spec == 'O') ) */
  /*   { */
  /*     if ((ret->str_len + 1) >= ret->fmt->width) */
  /* 	ret->mid_str = ft_strjoin("0", ret->final_string); */
  /*     return; */
  /*   } */
  /* if (ret->fmt->spec == 'x' || ret->fmt->spec == 'X') */
  /*   { */
  /*     if (ret->str_len == (ret->fmt->width + 1) && */
  /* 	  ft_strchr(ret->fmt->flag, '0')) */
  /* 	ret->mid_str = insert_str("X", ret->final_string, 1, 1); */
  /*     else if (ret->str_len == (ret->fmt->width + 1) && */
  /* 	       !ft_strchr(ret->fmt->flag, '0')) */
  /* 	ret->mid_str = sub_zero(ret->final_string); */
  /*     else if ((ret->str_len + 2) >= ret->fmt->width) */
  /* 	ret->mid_str = ft_strjoin("0X", ret->final_string); */
  /*   } */
}
