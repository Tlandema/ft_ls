/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:37:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:42:59 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static char	*reading(char **str, char *buff, int fd)
{
	char	*truc;
	int		ret;

	ret = 1;
	while (!(ft_strchr(*str, '\n')) && ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret)
		{
			buff[ret] = '\0';
			truc = *str;
			if (!(*str = ft_strjoin(*str, buff)))
				return (NULL);
			free(truc);
		}
	}
	free(buff);
	return (*str);
}

static char	*a_line(char **str)
{
	char	*buff;
	char	*line;
	char	*truc;

	buff = ft_strchr(*str, '\n');
	truc = NULL;
	if (buff)
	{
		if (!(line = ft_strndup(*str, buff - *str)))
			return (NULL);
		truc = *str;
		if (!(*str = ft_strdup(buff + 1)))
			return (NULL);
		free(truc);
	}
	else if (!(line = ft_strdup(*str)))
		return (NULL);
	if (!(*str) || !truc)
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		*buff;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || \
			!(buff = ft_strnew(BUFF_SIZE + 1)) \
			|| read(fd, buff, 0) == -1 || \
			(str[fd] == NULL && !(str[fd] = ft_strnew(0))))
		return (-1);
	if (!(reading(&str[fd], buff, fd)))
		return (-1);
	if (*str[fd])
	{
		if (!(*line = a_line(&str[fd])))
			return (-1);
		return (1);
	}
	return (0);
}
