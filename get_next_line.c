/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:55 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/18 17:09:46 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_n_free(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

char	*ft_update_buff(char *buffer)
{
	char	*new;
	char	*ptr;
	size_t	i;

	ptr = ft_strchr(buffer, '\n');
	new = ft_calloc(ft_strlen(ptr) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		new[i] = ptr[i];
		i++;
	}
	free(buffer);
	return (new);
}

char	*ft_line(char *buffer)
{
	char	*new;
	size_t	i;
	size_t	size;

	size = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n'));
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = buffer[i];
		i++;
	}
	return (new);
}

char	*ft_read(int fd, char *buffer)
{
	int		sz;
	char	*str;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, str, BUFFER_SIZE);
		if (sz == -1)
			return (free(str), NULL);
		str[sz] = '\0';
		buffer = ft_join_n_free(buffer, str);
		if (!buffer)
			return (free(str), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	printf("%p", buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	buffer = ft_update_buff(buffer);
	if (!buffer)
		return (free(line), NULL);
	return (line);
}

int	main(int argc, char **argv)
{
	(void) argc;
	int fd = open("test.txt", O_RDONLY);
	printf("first line : %s\n", get_next_line(fd));
	printf("second line : %s\n", get_next_line(fd));
	close(fd);
	return (1);
}