/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 01:07:37 by azeraoul          #+#    #+#             */
/*   Updated: 2021/03/22 20:30:30 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	error(char **buff, char **line, int fd)
{
	*buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!*buff || !line || BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
	{
		if (*buff)
			free(*buff);
		return (-1);
	}
	return (0);
}

static char	*new_line(char *str)
{
	if (!str)
		return (NULL);
	return (ft_strchr(str, '\n'));
}

static char	*ft_realloc(char *content, char *buff)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (content)
		len1 += ft_strlen(content);
	if (buff)
		len2 += ft_strlen(buff);
	new = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memmove(new, content, len1);
	ft_memmove(new + len1, buff, len2);
	free(content);
	return (new);
}

static int	split_line(char **line, char **content)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*content)[i] && (*content)[i] != '\n')
		++i;
	if ((*content)[i] == '\0')
	{
		(*line) = ft_strdup(*content);
		free(*content);
		(*content) = NULL;
		return (0);
	}
	tmp = (*content);
	(*line) = ft_strndup(tmp, i);
	(*content) = ft_strdup(tmp + i + 1);
	free(tmp);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*content[256];
	char		*buff;
	int			rlen;

	rlen = 1;
	if (error(&buff, line, fd))
		return (-1);
	while (!new_line(content[fd]) && rlen > 0)
	{
		rlen = read(fd, buff, BUFFER_SIZE);
		buff[rlen] = 0;
		content[fd] = ft_realloc(content[fd], buff);
	}
	free(buff);
	if (rlen < 0)
		return (-1);
	return (split_line(line, &content[fd]));
}
