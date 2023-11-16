/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:03:09 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/16 17:13:39 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	fd = open("test.txt", O_RDONLY);
	char str[10];
	int		i;

	i = ft_strlen(str);
	read(fd, &str[i], 4);
	i = 4;
	printf("%s\n", str);
	read(fd, &str[i], 4);
	printf("%s\n", str);
	return (0);
}