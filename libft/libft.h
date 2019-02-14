/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:25:21 by thorker           #+#    #+#             */
/*   Updated: 2019/02/14 18:08:12 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include <OpenCL/opencl.h>

typedef struct			s_opencl
{
	cl_device_id		device_id;
	cl_int				error;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				memobj;
	cl_program			program;
	cl_kernel			kernel;
	size_t				src_kernel_size;
	char				*src_kernel_str;
}						t_opencl;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
	struct s_vector 	*next;
}						t_vector;

typedef struct			s_comp
{
	double				real;
	double				img;
}						t_comp;

t_opencl				*init_opencl(char *name_file, char *name_func);
void					check_error_n_exit(int i, char *str);
void					ft_vctdel(t_vector **begin);
t_vector				*ft_vctadd(t_vector **begin, double x, double y, double z);
t_vector				*ft_vctnew(double x, double y, double z);
int						ft_advatoi(const char *c);
int						ft_skip(const char *num);
void					ft_filedel(t_file **file, int fd);
t_list					*ft_lstaddlast(t_list **begin_list, t_list *new);
int						ft_lstcount(t_list *begin_list);
int						ft_power(int nbr, int power);
char					*ft_strrev(char *c);
void					ft_putnbrln(int n);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_putnbr_fd(int n, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
char					*ft_strtrim(char const *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s, unsigned int start, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
char					*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char					*ft_strmap(char const *s, char (*f)(char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_striter(char *s, void (*f)(char*));
void					ft_strclr(char *s);
void					ft_strdel(char **as);
char					*ft_strnew(size_t size);
void					ft_memdel(void **ap);
void					*ft_memalloc(size_t size);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst, const void *src, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcpy(char *dst, const char *src);
size_t					ft_strlcat(char *dst, const char *s2, size_t size);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strrchr(const char *str, int c);
char					*ft_strchr(const char *str, int c);
char					*ft_strnstr(const char *s1, const char *s2, size_t len);
char					*ft_strstr(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_atoi(const char *c);
void					ft_putchar(char c);
void					ft_putstr(char const *c);
void					ft_putnbr(int c);
#endif
