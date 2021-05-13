/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:35:28 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static void	make_queue(ssize_t i, t_list **start, t_list **lnk)
{
	if (i == 0)
		*start = *lnk;
	else
		ft_lstappend(start, *lnk);
}

t_list		*get_queue(char *fmt)
{
	char	*tmp;
	t_list	*lnk;
	t_list	*start;
	ssize_t	i;
	ssize_t	len;

	if (!fmt || !(*fmt))
		return ((t_list *)NULL);
	i = 0;
	while (fmt[i])
	{
		len = (fmt[i] == '%' ? get_taglen(&fmt[i]) : get_len(&fmt[i]));
		if (len != -1 && (tmp = ft_strsub(fmt, i, len)))
		{
			lnk = ft_lstnew((void *)tmp, 1 + len);
			make_queue(i, &start, &lnk);
			i += len;
			ft_strdel(&tmp);
		}
		else
			return ((t_list *)NULL);
	}
	return (start);
}
