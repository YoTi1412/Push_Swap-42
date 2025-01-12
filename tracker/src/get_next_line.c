/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <yrafai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:04:11 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/18 15:46:36 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

static char	*ft_nextline(char *s)
{
	int		i;
	char	*ret;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	len = ft_strlen(s) - i;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (free(s), ret);
}

static int	check(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_read(char *s, char *buffer, int fd)
{
	int	readed;

	readed = 1;
	if (check(s))
		return (s);
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buffer[readed] = '\0';
		s = ft_join(s, buffer);
		if (!s)
			return (NULL);
		if (check(s))
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(rest), rest = NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (free(rest), rest = NULL);
	rest = ft_read(rest, buffer, fd);
	free(buffer);
	buffer = rest;
	buffer = ft_sub(buffer);
	rest = ft_nextline(rest);
	return (buffer);
}
