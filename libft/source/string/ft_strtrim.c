/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:19:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlength(const char *s)
{
	size_t i;
	size_t len;
	size_t j;

	i = 0;
	len = ft_strlen(s);
	j = len;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		return (0);
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	j = (len - 1) - j;
	len = len - (i + j);
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	str = NULL;
	if (s)
	{
		i = 0;
		len = ft_strlength(s);
		if (!(str = (char*)ft_memalloc(len + 1)))
			return (NULL);
		if (!len)
			return (ft_strdup(""));
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		i = 0;
		while (s[i])
			i++;
		i--;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		ft_strncpy(str, s, i + 1);
		return (str);
	}
	return (NULL);
}
