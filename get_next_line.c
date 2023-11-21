/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:34:55 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/21 18:00:30 by mpitot           ###   ########.fr       */
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
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	free(buffer);
	return (new);
}

char	*ft_line(char *buffer)
{
	char	*new;
	size_t	i;
	size_t	size;

	size = 0;
	while (buffer[size] != '\n' && buffer[size])
		size++;
	if (size == 0)
		return (NULL);
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
		str = ft_join_n_free(buffer, str);
		if (!str)
			return (free(str), NULL);
		if (ft_strchr(str, '\n'))
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
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_update_buff(buffer);
	return (line);
}

int	main(int argc, char **argv)
{
	(void) argc;
	int fd = open("test.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	char *str4 = get_next_line(fd);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	if (str4)
		printf("%s\n", str4);
	else
		printf("(null)\n");
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	close(fd);
	return (1);
}