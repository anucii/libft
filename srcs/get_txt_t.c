/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txt_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:02:55 by jdaufin           #+#    #+#             */
/*   Updated: 2021/05/13 10:26:27 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_type	get_txt(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "lc") || ft_strstr(s, "C"))
		ret = CC;
	else if (ft_strstr(s, "c"))
		ret = C;
	else if (ft_strstr(s, "ls") || ft_strstr(s, "S"))
		ret = SS;
	else if (ft_strstr(s, "s"))
		ret = S;
	else
		ret = TABEND;
	return (ret);
}
