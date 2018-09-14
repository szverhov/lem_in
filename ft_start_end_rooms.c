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

int		ft_inner_start_end(char **tmp)
{
	ft_add_to_gstr(*tmp);
	if (ft_strcmp((*tmp), "##start") == 0
	|| ft_strcmp((*tmp), "##end") == 0)
		return (0);
	free((*tmp));
	(*tmp) = 0;
	get_next_line(0, &(*tmp));
	return (1);
}

int		ft_start_room(t_rooms **nest, char **tmp, int ants, int *i)
{
	free((*tmp));
	get_next_line(0, &(*tmp));
	while ((*tmp)[0] == '#')
		if (!(ft_inner_start_end(&(*tmp))))
			return (0);
	if ((*tmp)[0] != '#')
	{
		g_iters++;
		if (g_iters > 1 && !ft_coords(*tmp))
			return (0);
	}
	if (!ft_check_pipe(*tmp))
		return (0);
	ft_add_to_gstr(*tmp);
	if (!(*nest))
		return (ft_init_start_room(&(*nest), &(*tmp), &(*i), ants));
	if (ft_check_double_space((*tmp)))
	{
		if (!ft_add_rooms(&(*nest), (*tmp), ants))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		ft_end_room(t_rooms **nest, char **tmp, int *i)
{
	free((*tmp));
	get_next_line(0, &(*tmp));
	while ((*tmp)[0] == '#')
		if (!(ft_inner_start_end(&(*tmp))))
			return (0);
	if ((*tmp)[0] != '#')
	{
		g_iters++;
		if (g_iters > 1 && !ft_coords(*tmp))
			return (0);
	}
	if (!ft_check_pipe(*tmp))
		return (0);
	ft_add_to_gstr(*tmp);
	if (!(*nest))
		return (ft_init_end_room(&(*nest), &(*tmp), &(*i)));
	if (ft_check_double_space((*tmp)))
	{
		if (!ft_add_rooms(&(*nest), (*tmp), -1))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		ft_check_exist_of_start(t_rooms **nest)
{
	t_rooms *tmp;

	if (!nest)
		return (1);
	if (!(*nest))
		return (0);
	tmp = (*nest);
	while (tmp)
	{
		if (tmp->start_r_end == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_check_exist_of_end(t_rooms **nest)
{
	t_rooms *tmp;

	if (!nest)
		return (1);
	if (!(*nest))
		return (0);
	tmp = (*nest);
	while (tmp)
	{
		if (tmp->start_r_end == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
