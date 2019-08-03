/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:12:46 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 14:10:29 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy(char *str, char **tmp)
{
	int		i;
	int		n;
	char	*lst;

	n = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		n = 1;
	str[i] = '\0';
	lst = ft_strdup(str);
	if (n)
		*tmp = ft_strdup(&str[i + 1]);
	else
		*tmp = ft_strdup(&str[i]);
	free(str);
	return (lst);
}

t_list	*fd_manager(const int fd, t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if ((int)tmp->content_size == (int)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew((void *)"\0", fd);
	ft_lstadd(lst, tmp);
	tmp = *lst;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				n;
	char			*str;

	n = 0;
	tmp = 0;
	if (fd < 0 || !line || read(fd, &buf, 0) < 0)
		return (-1);
	tmp = fd_manager(fd, &lst);
	while ((n = read(fd, &buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		str = tmp->content;
		tmp->content = (char*)ft_strjoin((char*)(tmp->content), buf);
		free(str);
	}
	if (n < BUFF_SIZE && !(ft_strlen(tmp->content)))
		return (0);
	*line = ft_copy(tmp->content, (char**)(&tmp->content));
	return (1);
}
