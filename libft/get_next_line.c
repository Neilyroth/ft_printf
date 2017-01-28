/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:16:59 by nterrier          #+#    #+#             */
/*   Updated: 2016/03/15 17:42:13 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_buf	*bonus(t_buf **first_buf, int fd)
{
	t_buf *cur_buf;

	if (*first_buf == NULL)
	{
		(*first_buf) = (t_buf*)malloc(sizeof(t_buf));
		(*first_buf)->buffer = NULL;
		(*first_buf)->fd = fd;
		(*first_buf)->next = (t_buf*)malloc(sizeof(t_buf));
		(*first_buf)->next->fd = -15;
		cur_buf = *first_buf;
		return (cur_buf);
	}
	cur_buf = *first_buf;
	while (cur_buf->fd >= 0 && cur_buf->fd != fd)
		cur_buf = cur_buf->next;
	if (cur_buf->fd == -15)
	{
		cur_buf->fd = fd;
		cur_buf->buffer = NULL;
		cur_buf->next = (t_buf*)malloc(sizeof(t_buf));
		cur_buf->next->fd = -15;
	}
	return (cur_buf);
}

int		new_read(int const fd, char **ligne, t_buf *buf, int do_read)
{
	int i;
	int lenght;

	i = 0;
	if (do_read)
	{
		ft_bzero(buf->buffer, BUFF_SIZE);
		lenght = read(fd, buf->buffer, BUFF_SIZE);
		if (lenght <= 0)
			return (lenght);
		buf->head = 0;
	}
	while (buf->buffer[buf->head + i] != '\n' && buf->buffer[buf->head + i])
		i++;
	*ligne = ft_strjoin(*ligne, ft_strsub(buf->buffer, buf->head, i));
	buf->head += i;
	if (buf->head == BUFF_SIZE)
		return ((buf->buffer[buf->head - 1] != '\n' && i) ?
			(new_read(fd, ligne, buf, 1) || 1) : (new_read(fd, ligne, buf, 1)));
	else if (buf->buffer[++buf->head] == '\0' && buf->head != BUFF_SIZE)
	{
		ft_bzero(buf->buffer, BUFF_SIZE);
		buf->head = BUFF_SIZE;
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_buf	*first_buf;
	t_buf			*buf;
	char			*ligne;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	ligne = ft_strnew(0);
	buf = bonus(&first_buf, fd);
	if (!buf->buffer)
	{
		buf->buffer = ft_strnew(BUFF_SIZE);
		buf->head = -1;
		ret = new_read(fd, &ligne, buf, 1);
	}
	else
		ret = new_read(fd, &ligne, buf, 0);
	*line = ligne;
	return (ret);
}
