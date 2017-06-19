#include "../ft_printf.h"

char	*format_ptr_addr(void *addr)
{
  unsigned long to_print;
  char *recv;
  char *tmp;
  
  to_print = (unsigned long)addr;
  recv = ft_us_longlong_toa_base(to_print, 16);
  tmp = recv;
  recv = ft_strjoin("0x", recv);
  free(tmp);
  return (recv);
}

char *insert_str(char *str, char *dst, int beg, int len)
{
  int i;
  int k;
  char *ret_str;
  int str_len;

  i = 0;
  k = 0;
  str_len = (ft_strlen(str) + ft_strlen(dst));
  ret_str = (char*)malloc(str_len + 1);
  while (i < beg)
    {
      ret_str[i] = str[i];
      i++;
    }
  while ((i - beg) < len)
      ret_str[i++] = dst[k++];
  k = i - k;
  while (str[k] != '\0')
      ret_str[i++] = str[k++];
  ret_str[i] = '\0';
  return (ret_str);
}

void attach_zero(t_val *ret)
{
  char *add;

  add = "0X";
  if ((ret->fmt->spec == 'o' || ret->fmt->spec == 'O') &&
      ft_strchr(ret->fmt->flag, '-') && ft_strlen(ret->final_string) <
      ret->fmt->width)
    ret->final_string = insert_str(ret->final_string, add, 0, 1);
  else if ((ret->fmt->spec == 'x' || ret->fmt->spec == 'X') &&
      ft_strchr(ret->fmt->flag, '-'))
    ret->final_string = insert_str(ret->final_string, add, 0, 2);
  /* else */
  /*   handle_cases_with_zeros(ret); */
}

void print_final_product(t_val *ret)
{
  precision(ret);
  ret->str_len = ft_strlen(ret->mid_str);
  if (ret->fmt->spec == 'o' || ret->fmt->spec == 'O' ||
      ret->fmt->spec == 'x' || ret->fmt->spec == 'X')
    handle_hash(ret);
  if (ft_strchr(ret->fmt->flag, '-'))
    ret->final_string =
      left_justify(ret->mid_str, ret->final_string);
  else
    ret->final_string =
      right_justify(ret->mid_str, ret->final_string);
  printf("check %d\n", check_zero(ret));
  if (check_zero(ret) == 1 && ft_strchr(ret->fmt->flag, '#'))
    ret->final_string = replace_beg(ret);
  ret->print_func(ret->final_string);
  ret->r += ft_strlen(ret->final_string);
}

