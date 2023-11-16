/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:55 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/16 20:14:14 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_endlcheck(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
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

void	ft_cleanbuffer(char *str, char *res)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = ft_strlen(res);
	while (str[j++])
		i++;
	new = malloc(sizeof(char) * i + 1);

}

char	*ft_read(int fd)
{
	static size_t	i;
	size_t	sz;
	static char	left[BUFFER_SIZE];
	char	str[BUFFER_SIZE];
	char	*line;

	sz = 1;
	ft_bzero(str, BUFFER_SIZE);
	i = ft_strlen(str);
	while (sz > 0)
	{
		sz = read(fd, str, BUFFER_SIZE - 1);
		if (ft_endlcheck(str, sz))
		{
			res = ft_resultline(str);
			if (!res)
				return (NULL);
			ft_cleanbuffer(str,res);
			return (res);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		str[BUFFER_SIZE];
	char		*line;
	int			sz;

	if (left && ft_endlcheck(left))
		return (ft_resultline(left));
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, str, BUFFER_SIZE);
		str[sz] = '\0';
		left = ft_strjoin(left, str);
		if (!left)
			return (NULL);
		if (ft_endlcheck(left))
		{
			res = ft_resultline(left);
			if (!res)
				return (free(left), NULL);
			ft_cleanbuffer(left,res);
			return (res);
		}
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	int fd = open("test.txt", O_RDONLY);
	printf("first line : %s\n", ft_read(fd));
	printf("second line : %s\n", ft_read(fd));
	close(fd);
	return (1);
}