/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-sol <adel-sol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:46:31 by adel-sol          #+#    #+#             */
/*   Updated: 2021/04/12 11:13:09 by adel-sol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}			t_list;

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
ssize_t		ft_write(int fildes, void *buf, size_t nbyte);
int			ft_list_size(t_list *begin_list);
void		ft_list_push_front(t_list **begin_list, void *data);
t_list		*ft_create_elem(void *data);
void		ft_list_remove_if(t_list **begin_list, void *data_ref, \
int (*cmp)(), void (*free_fct)(void *));
void		ft_list_sort(t_list **begin_list, int (*cmp)());
int			ft_atoi_base(char *str, char *base);

#endif
