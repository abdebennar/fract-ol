/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:22 by abennar           #+#    #+#             */
/*   Updated: 2024/02/14 03:25:38 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

/*
 * get_next_line
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*strjoin(char *s1, char *s2);
char	*ft_strndup(char *str, size_t len);
bool	detect_n(char *buff);
void	m_free(char *mem);
char	*get_next_line(int fd);

/*
ft_printf
*/

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putprsnt(void);
int		ft_putnbr(int n);
int		ft_putusg(unsigned int n);
int		ft_puthex(unsigned int nb, char x);
int		ft_putptr(unsigned long ptr);
int		ft_putnull(void);

/*
 * printing functions
*/
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/*
 * is...functions 
*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/*
 * memory funcs
*
*/
void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const	void *s1, const void *s2, size_t n);

/*
 * to...func
*/
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
/*
 * str...function
*/
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *str1, char *str2);

#endif 
