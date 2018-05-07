// (C) Copyright 2016-2018 Délypse

#ifndef FT_OUTPUT_H
#define FT_OUTPUT_H

#include <wchar.h>

# define QUEUE_SIZE 75

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putnchar(char *s, size_t n);
void	ft_putstr(char const *s);
void	ft_putendl(char const*s);
void	ft_putnbr(int n);
int		ft_putnstr(char const *s, size_t n);
void	ft_putwchar_fd(wchar_t c, int fd, size_t size);
void	ft_putwchar(wchar_t c, size_t size);
void	ft_putwstr_fd(wchar_t *str, int fd);
void	ft_putwstr(wchar_t *str);
int		ft_putnbyteswstr(wchar_t *str, size_t n);

void	ft_queuechar(char s);
void	ft_queuestr(char *s);
void	ft_queuenbr(int nbr);
void	ft_writequeue(void);

#endif 
