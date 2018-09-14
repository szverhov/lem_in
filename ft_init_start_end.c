/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:31:43 by szverhov          #+#    #+#             */
/*   Updated: 2017/11/03 12:23:59 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_init_start_room(t_rooms **nest, char **tmp, int *i, int ants)
{
	if (ft_check_double_space((*tmp)))
	{
		if (!ft_init_first(&(*nest), (*tmp), ants))
			return (0);
	}
	else
		return (0);
	(*i)++;
	return (1);
}

int		ft_init_end_room(t_rooms **nest, char **tmp, int *i)
{
	if (ft_check_double_space((*tmp)))
	{
		if (!ft_init_first(&(*nest), (*tmp), -1))
			return (0);
	}
	else
		return (0);
	(*i)++;
	return (1);
}
