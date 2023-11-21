/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:50 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/21 17:12:34 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*nstr;

	if (!s1[0])
		return ((char *) s2);
	//if (!s2[0])
	//	return ((char *) s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	i = -1;
	while (s1[++i])
		nstr[i] = s1[i];
	j = 0;
	while (s2[j])
		nstr[i++] = s2[j++];
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (&((char *) s)[i]);
		i++;
	}
	if ((unsigned char) c == 0)
		return (&((char *) s)[i]);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 && size == 0)
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		((char *) ptr)[0] = '\0';
	}
	else
	{
		ptr = malloc(size * nmemb);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
	}
	return (ptr);
}
