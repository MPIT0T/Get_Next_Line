/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:55 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/16 17:01:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_endlcheck(char *str, int sz)
{
	size_t	i;

	i = 0;
	while (i < (size_t) sz)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_resultline(char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	return (res);
}

char	*ft_cleanbuffer(char *str, char *res)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (res[i])
			str[i] = res[i];
		else
			str[i] = '\0';
		i++;
	}
}

char	*ft_read(int fd)
{
	static size_t	i;
	size_t	sz;
	char	str[BUFFER_SIZE];
	char	*res;

	sz = 1;
	ft_bzero(str, BUFFER_SIZE);
	while (sz > 0)
	{
		sz = read(fd, str, BUFFER_SIZE - 1 - ft_strlen(str));
		if (ft_endlcheck(str, sz))
		{
			res = ft_resultline(str);
			if (!res)
				return (NULL);
			return (res);
		}
	}
}

char	*get_next_line(int fd)
{
	static size_t	i;


}

int	main(int argc, char **argv)
{
	(void) argc;
	int fd = open("test.txt", O_RDONLY);
	printf("%s", ft_read(fd));
	close(fd);
	return (1);
}