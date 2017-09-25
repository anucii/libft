/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:25:57 by jdaufin           #+#    #+#             */
/*   Updated: 2017/09/25 21:16:00 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_append(char *s1, char *s2, size_t len)
{
	char	*ret;

	if (!(s1 && s2 && len && (ret = (char *)ft_memalloc(2 + len))))
		return (NULL);
	ft_strlcpy(ret, s1, 1 + ft_strlen(s1));
	ft_memdel((void **)&s1);
	ft_strlcat(ret, s2, 1 + len);
	return (ret);
}

static int		get_line(t_list **alst, char **line)
{
	t_buffer	*ptr;
	char		*nl;
	ssize_t		readbytes;

	if (!line)
		return (-1);
	if (!*((ptr = (t_buffer *)((*alst)->content))->buf))
		if ((readbytes = read(ptr->fildes, ptr->buf, BUFF_SIZE)) < 1)
			return (!readbytes ? 0 : -1);
	ptr->buf[BUFF_SIZE] = '\0';
	if ((nl = ft_strchr(ptr->buf, (int)'\n')))
	{
		*line = (*line ? ft_append(*line, ptr->buf, ft_strlen(*line) +\
					ft_strlen(ptr->buf) - ft_strlen(nl)) : \
				ft_strsub(ptr->buf, 0, ft_strlen(ptr->buf) - ft_strlen(nl)));
		ft_strlcpy(ptr->buf, nl + 1, ft_strlen(nl));
	}
	else
	{
		*line = (*line ? ft_append(*line, ptr->buf, ft_strlen(*line) +\
					ft_strlen(ptr->buf)) : ft_strdup(ptr->buf));
		ft_bzero((void **)&(ptr->buf), BUFF_SIZE);
		get_line(alst, line);
	}
	return (1);
}

static void		set_link(int fd, t_list **alst, t_list **ret)
{
	static t_buffer	slot;

	slot.fildes = fd;
	if (*alst)
		ft_lstappend(alst, *ret = ft_lstnew(&slot, sizeof(t_buffer)));
	else
	{
		*alst = ft_lstnew(&slot, sizeof(t_buffer));
		*ret = *alst;
	}
}

static short	is_set(int fd, t_list **start, t_list **alst)
{
	t_buffer	*ptr;

	if (!start || !alst)
		return (0);
	*alst = *start;
	while (*alst)
	{
		ptr = (t_buffer *)((*alst)->content);
		if (ptr->fildes == fd)
			return (1);
		*alst = (*alst)->next;
	}
	return (0);
}

int				gnl_clean(const int fd, char **line, _Bool clean)
{
	static t_list	*start;
	t_list			*lst;

	lst = start;
	if (clean && (fd >= 0) && (BUFF_SIZE > 0) && lst)
	{
		while (lst)
		{
			if (((t_buffer *)lst->content)->fildes == fd)
				ft_bzero((void *)((t_buffer *)lst->content)->buf,\
						BUFF_SIZE + 1);
			lst = lst->next;
		}
		return (1);
	}
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (*line)
		*line = NULL;
	if (!is_set(fd, &start, &lst))
		set_link(fd, &start, &lst);
	return (lst ? get_line(&lst, line) : -1);
}
