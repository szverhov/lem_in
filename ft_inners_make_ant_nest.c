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

int		ft_if_i_zero(char *tmp, int *i, int *ants)
{
	if ((!tmp || ft_strlen(tmp) == 0 || (!ft_is_it_int(tmp))))
		return (0);
	if (((*ants) = ft_atoi(tmp)) <= 0)
		return (0);
	(*i)++;
	return (1);
}

int		ft_in_inner_coments(char **tmp)
{
	free(*tmp);
	*tmp = 0;
	return (2);
}

int		ft_inner_coments(t_rooms **nest, char **tmp, int i, int ants)
{
	if ((*tmp)[0] == '#' && (*tmp)[1] == '#')
	{
		if (ft_strcmp("start", (*tmp) + 2) == 0)
		{
			if (ft_check_exist_of_start(&(*nest)))
				return (ft_free_return_zero(&(*tmp)));
			if (ft_start_room(&(*nest), &(*tmp), ants, &i) == 1)
				return (ft_in_inner_coments(&(*tmp)));
			else
				return (ft_free_return_zero(&(*tmp)));
		}
		else if (ft_strcmp("end", (*tmp) + 2) == 0)
		{
			if (ft_check_exist_of_end(&(*nest)))
				return (ft_free_return_zero(&(*tmp)));
			if (ft_end_room(&(*nest), &(*tmp), &i) == 1)
				return (ft_in_inner_coments(&(*tmp)));
			else
				return (ft_free_return_zero(&(*tmp)));
		}
		else
			return (ft_in_inner_coments(&(*tmp)));
	}
	return (1);
}

int		ft_inner_l_strt_end(char **tmp, int *i, int *ants)
{
	if ((*tmp)[0] == 'L' || tmp[0] == '\0')
		return (ft_free_return_zero(&(*tmp)));
	if ((*tmp)[0] != '#')
	{
		g_iters++;
		if (g_iters > 1 && !ft_coords(*tmp))
			return (ft_free_return_zero(&(*tmp)));
	}
	if (!ft_check_pipe(*tmp))
		return (ft_free_return_zero(&(*tmp)));
	ft_add_to_gstr(g_vars.tmp);
	if ((*i) == 0 && (ft_strcmp((*tmp), "##start") == 0 ||
	ft_strcmp((*tmp), "##end") == 0))
		return (ft_free_return_zero(&(*tmp)));
	if ((*tmp)[0] == '#' && (ft_strcmp((*tmp), "##start")
	!= 0 && ft_strcmp((*tmp), "##end") != 0))
		return (ft_in_inner_coments(&(*tmp)));
	if ((*i) == 0)
	{
		if (!ft_if_i_zero((*tmp), &(*i), &(*ants)))
			return (ft_free_return_zero(&(*tmp)));
		free(*tmp);
		return (2);
	}
	return (1);
}

int		ft_chck_double_spaces(t_rooms **nest, char **tmp)
{
	if (ft_check_double_space((*tmp)))
	{
		if (!ft_inner_check_d_spaces(&(*nest), &(*tmp)))
			return (ft_free_return_zero(&(*tmp)));
	}
	else
		return (ft_free_return_zero(&(*tmp)));
	return (1);
}
