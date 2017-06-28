/* Header */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <inttypes.h>
# include <limits.h>
# include <wchar.h>
# include <stdarg.h>
# define CHECK_FLAGS(x) x == '+' || x == '-' || x == '0' || x == '#' || x == ' '
# define LENGTH_FMT(x) x == 'h' || x == 'l' || x == 'z' || x == 'j'
# define CHECK_SPEC(x) x == 'p' || x == 'S' || x == 's' || x == 'C' || x == 'c'
# define CHECK_CHAR(x) x != 'p' || x != 'S' || x != 's' || x != 'C' || x != 'c'
# define CHECK_INT(x) x == 'i' || x == 'd' || x == 'D'
# define CHECK_SIGN(x) x != 'i' && x != 'd' && x != 'D'
# define SPEC(x) x == 's' || x == 'S' || x == 'c' || x == 'C' || SPEC2(x)
# define SPEC2(x) x == 'p' || x == 'd' || x == 'D' || x == 'i' || SPEC3(x)
# define SPEC3(x) x == 'o' || x == 'O' || x == 'u' || x == 'U' || SPEC4(x)
# define SPEC4(x) x == 'x' || x == 'X' || x == '%'

typedef struct s_form
{
  char *flag;
  size_t  width;
  size_t precision;
  char *length;
  char spec;
}              t_form;

typedef struct s_val
{
  int wild_prec;
  int wild_width;
  size_t str_len;
  int r;
  int flag;
  int prec_case;
  int no_spec;
  char *specifiers;
  char *flags;
  char *width;
  char *precision;
  char *length;
  char **format;
  void (*print_func)(const char*);
  char *mid_str;
  char *final_string;
  t_form *fmt;
  
  /* array of function pointers? */
}              t_val;

int ft_printf(char *fmt, ...);
void initialize_return_struct(t_val *ret);
void decipher_flags(char *fmt, t_val *ret);
void set_the_width(t_val *ret);
char *ft_uitoa_base(unsigned int val, int base);
char *ft_itoa_base(int value, int base);
char *ft_longtoa_base(long long val,long long base);
char *ft_us_longlong_toa_base(unsigned long long val, long long base);

void ft_putstr_lower(const char *str);

int smallfmt(char spec, va_list ap, t_val *ret);

int count_digits(int val, int base);
int count_digits_int(int val, int base);
int count_uns_long_long(unsigned long long val, long long base);
char *uns_long_edge_cases(unsigned long long n);

char *left_justify(char *str, char *dst);
char *right_justify(char *str, char *dst);
char *make_string(char c, int len);

int change_to_signed_char(int s);
int change_to_unsigned_char(int s);
int change_to_unsigned_short_int(int s);

//void put_us_int(unsigned int n);
void *ft_bspace(void *b, size_t size);
void *ft_fill_with(void *b, char c, size_t size);
void ft_be_any(void *s, char c, int n);

//functions that read the va_arg and print the formatted result:
void print_c(t_val *ret, va_list ap);
void print_s(t_val *ret, va_list ap);
char *format_ptr_addr(void *addr);

void begin_ints(t_val *ret, va_list ap);
void handle_short_int(t_val *ret, va_list ap, int base);
void handle_long_int(t_val *ret, va_list ap, int base);
void handle_intmax_t(t_val *ret, va_list ap, int base);
void handle_size_t(t_val *ret, va_list ap, int base);
void handle_normal_int(t_val *ret, va_list ap, int base);
void handle_unsigned_normal_int(t_val *ret, va_list ap, int base);
void handle_hh_ll(t_val *ret, va_list ap, int base);
void handle_ll(t_val *ret, va_list ap, long long int h, int base);

void begin_hex_values(t_val *ret, va_list ap);
void handle_unsigned_short_hex(t_val *ret, va_list ap, int base);
void handle_unsigned_long_hex(t_val *ret, va_list ap, int base);
void handle_intmax_t_hex(t_val *ret, va_list ap, int base);
void handle_size_t_hex(t_val *ret, va_list ap, int base);
void handle_normal_int_hex(t_val *ret, va_list ap, int base);
void handle_hh_ll_hex(t_val *ret, va_list ap, int base);
void handle_ll_hex(t_val *ret, va_list ap, long long int h, int base);

void begin_caps_hex_values(t_val *ret, va_list ap);
void begin_unsigned_int_values(t_val *ret, va_list ap);
void begin_unsigned_octal_values(t_val *ret, va_list ap);
void begin_printing_pointer(t_val *ret, va_list ap);
void handle_modulo(t_val *ret);

void handle_hash(t_val *ret);
void octal_hash(t_val *ret);
void hex_hash(t_val *ret);

void print_final_product(t_val *ret);

void handle_undefinded_behavior(t_val *ret);
void handle_wild_card(t_val *ret, va_list ap);
void set_wild_flags(t_val *ret, char *fmt, va_list ap);

void precision(t_val *ret);

char *insert_str(char *str, char *dst, int beg, int len);
char *insert_zeros(char *str, int beg, int len);
char *replace_beg(t_val *ret);

int check_zero(t_val *ret);
void handle_sign(t_val *ret);
void reset_flags(t_val *ret);
int check_no_spec(char *fmt, t_val *ret);
void continue_dispatching(t_val *ret, va_list ap);
#endif
