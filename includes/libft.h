/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:19:39 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:25:25 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <locale.h>
# include <inttypes.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <wchar.h>
# define HEXLO "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DECIM "0123456789"
# define OCTAL "01234567"
# define QUERY_FD -2
# define BUFF_SIZE 15

typedef struct		s_str
{
	char			*addr;
	size_t			len;
}					t_str;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer
{
	int				fildes;
	char			buf[BUFF_SIZE + 1];
}					t_buffer;

typedef struct		s_wslen
{
	ssize_t			count;
	ssize_t			bytes;
}					t_wslen;

typedef enum				e_type
{
	TABEND = -1,
	D,
	HD,
	HHD,
	LD,
	LLD,
	JD,
	ZD,
	U,
	HU,
	HHU,
	LU,
	LLU,
	JU,
	ZU,
	O,
	HO,
	HHO,
	LO,
	LLO,
	JO,
	ZO,
	X,
	HX,
	HHX,
	LX,
	LLX,
	JX,
	ZX,
	XX,
	HXX,
	HHXX,
	LXX,
	LLXX,
	JXX,
	ZXX,
	P,
	C,
	CC,
	S,
	SS,
	PC
}							t_type;

union						u_intype
{
	int						d;
	int						i;
	short int				hd;
	signed char				hhd;
	long int				ld;
	long long int			lld;
	intmax_t				jd;
	intmax_t				zd;
	unsigned int			u;
	unsigned short int		hu;
	unsigned char			hhu;
	unsigned long int		lu;
	unsigned long long int	llu;
	uintmax_t				ju;
	size_t					zu;
	unsigned int			o;
	unsigned short int		ho;
	unsigned char			hho;
	unsigned long int		lo;
	unsigned long long int	llo;
	uintmax_t				jo;
	size_t					zo;
	unsigned int			x;
	unsigned short int		hx;
	unsigned char			hhx;
	unsigned long int		lx;
	unsigned long long int	llx;
	uintmax_t				jx;
	size_t					zx;
};

typedef union				u_cast
{
	char					*(*uitoa)(uintmax_t, char *);
	char					*(*itoa)(intmax_t, char *);
	void					*(*memcpy)(void *, const void *, size_t);
	ssize_t					(*wcrtomb)(unsigned char *, wchar_t);
	unsigned char			*(*wcstombs)(const wchar_t *);
	char					*(*strdup)(const char *);
	void					(*err)(void);
}							t_cast;

typedef struct				s_padding
{
	_Bool					zeroes;
	_Bool					neg_width;
}							t_padding;

typedef struct				s_prefix
{
	_Bool					space;
	_Bool					plus;
}							t_prefix;

typedef struct				s_tag
{
	t_type					type;
	t_cast					to_out;
	int						width;
	int						precision;
	_Bool					alter;
	t_padding				*padding;
	t_prefix				*prefix;
	_Bool					null_val;
}							t_tag;

int					ft_atoi(const char *str);
intmax_t			ft_atoimax(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t nbr, char *base);
char				*ft_uitoa_base(uintmax_t nbr, char *base);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_abs(int c);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstrtab(char **tab);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putbstr(const void *s, size_t len, char sep);

void				init_wslen(t_wslen *p_wslen);
void				ft_putwchar(wint_t c);
void				ft_putwstr(const wchar_t *s);
void				ft_putwstr_fd(const wchar_t *s, int fd);
ssize_t				ft_wcharlen(wchar_t wcr);
_Bool				ft_wcstrlen(const wchar_t *s, t_wslen *wslen);
ssize_t				ft_wcrtomb(unsigned char *mbs, wchar_t val);
unsigned char		*ft_wcstombs(const wchar_t *wstr);

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *s);
size_t				ft_wordcount(char const *s, char c);
int					get_next_line(const int fd, char **line);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_free(char const *s, unsigned int start, \
		size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, _Bool b1, char const *s2, \
		_Bool b2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_blanks(char *s);
void				ft_stabdel(char ***pstab);

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void **addr, size_t oldsize, size_t newsize);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **addr, t_list *new);
void				ft_linkdel(void *ptr, size_t size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstpop(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
ssize_t				ft_lstlen(t_list *lst);

int					ret_val(int val);
int					ft_printf(char *fmt, ...);
int					ft_printf_fd(int fd, char *fmt, ...);
int					fd_out(int fd);
void				put_list(t_list *elem);
void				clean_elem(void *content, size_t content_size);
t_list				*get_queue(char *fmt);
_Bool				tagend(char c);
ssize_t				get_taglen(const char *s);
ssize_t				get_len(const char *s);
void				process_fmt(va_list *pap, t_list *start);
t_tag				*init_tag(void);
void				ft_reinit_tag(t_tag *tag);
void				preset_conversion(t_tag *tag, char *s);
t_type				get_type(char *s);
t_type				get_d(char *s);
t_type				get_u(char *s);
t_type				get_o(char *s);
t_type				get_x(char *s);
t_type				get_xx(char *s);
t_type				get_txt(char *s);
t_type				get_p(char *s);
t_type				get_pc(char *s);
_Bool				get_class(t_type *table, t_type tocheck);
t_cast				get_action(t_type intype);
_Bool				ft_parse(t_tag *tag, char *s);
_Bool				check_flags(t_tag *tag, char **pts);
_Bool				check_width(t_tag *tag, char **pts);
_Bool				check_prec(t_tag *tag, char **pts);
_Bool				check_length(char **pts);
void				set_flags(t_tag *tag, char *flags);
void				ft_convert(va_list *pap, t_tag *tag, void **addr);
void				d_to_str(va_list *pap, t_tag *tag, void **addr);
void				u_to_str(va_list *pap, t_tag *tag, void **addr);
void				o_to_str(va_list *pap, t_tag *tag, void **addr);
void				x_to_str(va_list *pap, t_tag *tag, void **addr);
void				p_to_str(va_list *pap, t_tag *tag, void **addr);
void				txt_to_str(va_list *pap, t_tag *tag, void **addr);
void				pc_to_str(t_tag *tag, void **addr);
void				ft_format(t_tag *tag, void **addr);
void				set_empty(t_tag *tag, void **addr);
void				cut_mbs(unsigned char *mbs);
void				ft_clean_tag(t_tag *tag);
void				transfer_minus(char **ppad, void **addr);
void				transfer_0x(char **ppad, void **addr);
_Bool				is_0x(t_tag *tag);
void				launch_conversion(t_tag *tag, va_list *pap,\
		void **addr);
void				transfer_plus(char **ppad, void **addr);
void				fmt_unconvertible(void **addr);
#endif
