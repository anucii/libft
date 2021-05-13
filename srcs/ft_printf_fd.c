/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:03:18 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
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
  int     ret;
  va_list ap;

  if (fd > 0)
  {
    fd_out(fd);
  }
  ret = 1;
  if (fmt)
  {
    va_start(ap, fmt);
    ret = ft_printf(fmt);
    va_end(ap);
  }
  return (ret);
}
