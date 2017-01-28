/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:18:05 by nterrier          #+#    #+#             */
/*   Updated: 2016/02/13 19:07:32 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 17
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_buf
{
	char			*buffer;
	int				head;
	int				fd;
	struct s_buf	*next;
}				t_buf;

int				get_next_line(int const fd, char **line);
int				new_read(int const fd, char **ligne, t_buf *buf, int do_read);

#endif
