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

/* int main() */
/* { */
/*   	int test[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140}; */
/* 	int	tab[2] = {36, 45}; */
/* 	char *recv; */
/* 	char *tmp; */
/* 	unsigned char* taste; */
/* 	int i = 0; */
/* 	t_val *thing; */
	
/* 	recv = print_ptr_addr(thing, &test); */
/* 	printf("%s\n", recv); */
/* 	printf("%p\n", test); */
/* 	printf("%s\n", ft_us_longlong_toa_base(0x7fff543759d0, 16)); */
	
/* 	//free(recv); */
/* 	return (0); */
/* } */
