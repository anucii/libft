/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:31:23 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/03 18:28:07 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **alst)
{
	t_list	*buf[2];

	if (!(alst && *alst && (*alst)->next))
		return ;
	buf[0] = *alst;
	while (buf[0]->next)
	{
		buf[1] = buf[0];
		buf[0] = buf[0]->next;
	}
	ft_lstdelone(&buf[0], &ft_linkdel);
	buf[1]->next = NULL;
}
