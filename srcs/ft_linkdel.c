/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:50:11 by jdaufin           #+#    #+#             */
/*   Updated: 2020/12/10 17:03:41 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_linkdel(void *ptr, size_t size)
{
	if (!ptr)
		return ;
	(void)size;
	ft_memdel(&ptr);
}
