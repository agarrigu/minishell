/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algarrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:45:02 by algarrig          #+#    #+#             */
/*   Updated: 2024/04/02 20:55:29 by algarrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stddef.h>
# define CASE_DELTA 0x20

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* char utils */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* str utils */
char	**ft_split(const char *s, char c);
char	*ft_concat(int membs, const char *a, const char *b, ...);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *left, const char *right);
char	*ft_strnstr(const char *hay, const char *ndl, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_stris(char *s, int (*is)(int c));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strvlen(char **strv);

/* mem utils */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

/* puts */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* prints */
/* like `puts to stdout and returns succesfully printed bytes (not including nul
 * terminators */
int		ft_printchar(char c);
int		ft_printnbr(int n);
int		ft_printptr(void *p);
int		ft_printubase(unsigned long long n, const char *base);
int		ft_printstr(const char *s);
int		ft_printf(const char *format, ...);

/* list utils */
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/* converters */
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

/* mappers and iterators */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_freesplit(char **split);

#endif /* FT_H */
