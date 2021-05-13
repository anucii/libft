/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:03:18 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 12:51:15 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int							fd_out(int fd)
{
  static int stored_fd = 1;
  
  if ((fd != QUERY_FD) && (fd > 0))
  {
    stored_fd = fd;
  }

  return (stored_fd);
}

int							ft_printf_fd(int fd, char *fmt, ...)
{
  void		(*del)(void *, size_t);
	void		(*put)(t_list *elem);
	va_list		ap;
	t_list		*start;
	t_list		*lst;

  if (fd > 0)
  {
    fd_out(fd);
  }
	del = &clean_elem;
	put = &put_list;
	ret_val(-2);
	if (fmt)
		if ((start = get_queue(fmt)))
		{
			lst = start;
			va_start(ap, fmt);
			process_fmt(&ap, start);
			ft_lstiter(lst, put);
			ft_lstdel(&start, del);
			va_end(ap);
		}
	return (ret_val(0));
}
