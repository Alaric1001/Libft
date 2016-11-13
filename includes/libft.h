/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:12:54 by asenat            #+#    #+#             */
/*   Updated: 2017/06/15 16:05:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>

# define QUEUE_SIZE 75

/*
** Output hanling.
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putnchar(char *s, size_t n);
void				ft_putstr(char const *s);
void				ft_putendl(char const*s);
void				ft_putnbr(int n);
void				ft_queuechar(char s);
void				ft_queuestr(char *s);
void				ft_queuenbr(intmax_t nbr);
void				ft_writequeue(void);

/*
** Memory handling.
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memmove(void *dest, void const *src, size_t n);
void				*ft_memchr(void const *str, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_realloc(void *target, size_t size);
void				ft_doublearraydel(void ***array);
void				ft_doublearrayndel(void ***array, size_t n);

/*
** String Manipulation.
*/

size_t				ft_strlen(char const *s);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strdup(char const *s);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
char				*ft_strstr(char const *big, char const *little);
char				*ft_strnstr(char const *big, char const *little,
					size_t len);
size_t				ft_strlcat(char *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrev(char *s);
int					ft_putnstr(char const *s, size_t n);
char				*ft_strappend(char *dst, char *src);
char				*ft_strcappend(char *dst, char c);
char				*ft_strnappend(char *dst, char *s, size_t n);
char				*ft_strncappend(char *dst, char c, size_t n);
char				*ft_removechar(char *dst, size_t loc);
char				*ft_path_append(char *path, char *app);

/*
** WideChar Manipulation
*/

size_t				ft_wcharsize(wchar_t c);
void				ft_putwchar_fd(wchar_t c, int fd, size_t size);
void				ft_putwchar(wchar_t c, size_t size);
void				ft_putwstr_fd(wchar_t *str, int fd);
void				ft_putwstr(wchar_t *str);
int					ft_putnbyteswstr(wchar_t *str, size_t n);
size_t				ft_wstrsize(wchar_t *str);
size_t				ft_wstrlen(wchar_t *str);

/*
** Integer<=>String
*/

int					ft_atoi(char const *s);
char				*ft_itoa(long long n);
char				*ft_uitoa(unsigned long long nb);

/*
** Char utils
*/

int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isstrnum(char *str);
int					ft_isstrprintable(char *str);

/*
** String utils
*/

char				ft_getmissing_quote(char *str);
char				*ft_strescape(char *s, char *to_escape);
char				**ft_splitfilepath(char *file);
int					ft_star_match(char *str, char *pattern);

/*
** Math
*/

double				ft_pow(double n, int pow);
long int			ft_getnblen(unsigned long long n);

/*
** List handling
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnewraw(void *content);
t_list				*ft_lstgetlast(t_list *lst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **lst, void *content, size_t size);
void				ft_lstrev(t_list **lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstopnext(t_list *node, void (*del)(void*, size_t));

#endif
