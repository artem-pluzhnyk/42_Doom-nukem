/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:08:34 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/17 13:03:14 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Lib
*/
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

/*
** Inc
*/
# include "color.h"

/*
** Def
*/
# define BUFF_SIZE	32
# define FD_MAX		4864

# define CHECK(x) if (!x) return (-1);
# define SQR(x)	x*x
# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))
# define CLAMP(a,mi,ma) MIN(MAX(a,mi),ma)
# define VXS(x0,y0,x1,y1) ((x0)*(y1)-(x1)*(y0))
# define OVERLAP(a0,a1,b0,b1) (MIN(a0,a1)<=MAX(b0,b1)&&MIN(b0,b1)<=MAX(a0,a1))
# define ISB(x0,y0,x1,y1,x2,y2,x3,y3) (ISBX(x0,x1,x2,x3)&&ISBY(x0,x1,x2,x3))
# define ISBX(x0,x1,x2,x3) OVERLAP(x0,x1,x2,x3)
# define ISBY(y0,y1,y2,y3) OVERLAP(y0,y1,y2,y3)
# define PS(px,py,x0,y0,x1,y1) VXS((x1)-(x0),(y1)-(y0),(px)-(x0),(py)-(y0))

/*
** Struct
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_xy
{
	float			x;
	float			y;
}					t_xy;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

/*
** check
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/*
** convert
*/
float				ft_atof(char *str);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** gnl
*/
int					get_next_line(const int fd, char **line);

/*
** list
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_lstfold(t_list *lst, void *(*f)(const void *,
					const void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstsplit(char const *s, char c);

/*
** memory
*/
void				ft_bzero(void *s, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_realloc(void *ptr, size_t new_size);

/*
** number
*/
size_t				ft_nbrlen(int num);

/*
** other
*/
void				ft_exit(char *error);
void				ft_swap(void *a, void *b);
int					ft_wordcount(const char *s, char c);
char				*ft_wordfound(const char *s, char c, int *i);

/*
** output
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);

/*
** string
*/
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strlchr(const char *s, int c);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *str, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

#endif
