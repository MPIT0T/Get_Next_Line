/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:33:31 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/16 17:01:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# define BUFFER_SIZE 1024

void	ft_bzero(void *s, size_t n);

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);

#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
