/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:27 by youncho           #+#    #+#             */
/*   Updated: 2020/12/31 08:39:01 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		make_line(char **line, char *buffer, int i)
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	while (((*line)[i++] = buffer[j]))
		if (buffer[j++] == '\n')
		{
			(*line)[--i] = (char)0;
			ret = 1;
			break ;
		}
	i = 0;
	while (buffer[j])
		buffer[i++] = buffer[j++];
	buffer[i] = (char)0;
	return (ret);
}

int		read_control(int fd, char **line, char *buffer)
{
	int len;
	int ret;
	int i;

	len = 1;
	if (read(fd, buffer, 0) == R_ERR)
		return (R_ERR);
	while (len > 0)
	{
		if (!(set_line_size(line, (i = ft_strlen(*line)))))
			return (R_ERR);
		if ((ret = make_line(line, buffer, i)))
			return (ret);
		if ((len = read(fd, buffer, BUFFER_SIZE)) == R_ERR)
			return (R_ERR);
		buffer[len] = 0;
	}
	return (R_EOF);
}

int		gnl_init(int fd, char **line, t_storage **head, t_storage **curr)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || !line ||
		(!*head && !(*head = get_new_node(fd))))
		return (FAIL);
	if (!(*curr = get_current_node(fd, *head)))
		return (deallocation(fd, head, FAIL));
	*line = (char *)0;
	return (SUCCESS);
}

int		get_next_line(int fd, char **line)
{
	static t_storage	*head;
	t_storage			*curr;
	int					ret;

	if (gnl_init(fd, line, &head, &curr) == FAIL)
		return (R_ERR);
	if ((ret = read_control(fd, line, curr->buff)))
		return ((ret == R_ERR) ? deallocation(fd, &head, R_ERR) : R_NL);
	return (deallocation(fd, &head, R_EOF));
}
