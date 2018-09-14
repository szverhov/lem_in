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

int			ft_str_with_no_spaces(char *tmp)
{
	int i;

	i = 0;
	if (tmp[0] == '#')
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void		ft_add_to_gstr(char *str)
{
	int		i;
	char	*tmp;
	int		j;

	if (str[0] == '\0')
		return ;
	i = ft_strlen(g_str) + ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * i + 3);
	i = -1;
	while (g_str[++i])
		tmp[i] = g_str[i];
	j = -1;
	while (str[++j])
	{
		tmp[i] = str[j];
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	free(g_str);
	g_str = tmp;
}

int			ft_inner_check_d_spaces(t_rooms **nest, char **tmp)
{
	if (!(*nest))
	{
		if (!ft_init_first(&(*nest), (*tmp), 0))
			return (0);
		free(*tmp);
	}
	else
	{
		if (!ft_add_rooms(&(*nest), (*tmp), 0))
			return (0);
		free(*tmp);
	}
	return (1);
}

int			ft_make_ant_nest(t_rooms **nest)
{
	g_vars.i = 0;
	g_vars.ants = 2147483647;
	while (get_next_line(0, &g_vars.tmp) && g_vars.tmp[0] != 0)
	{
		if (((g_err = ft_inner_l_strt_end(&g_vars.tmp,
		&g_vars.i, &g_vars.ants)) == 2))
			continue ;
		else if (g_err == 0)
			return (ft_clean_nest(&(*nest)));
		if (ft_str_with_no_spaces(g_vars.tmp))
		{
			if (!ft_read_links_of_ant_nest(&(*nest), g_vars.tmp))
				return (ft_clean_nest(&(*nest)));
			else
				return (1);
		}
		if (((g_err = ft_inner_coments(&(*nest), &g_vars.tmp,
		g_vars.i, g_vars.ants)) == 2))
			continue ;
		else if (g_err == 0)
			return (ft_clean_nest(&(*nest)));
		if (!ft_chck_double_spaces(&(*nest), &g_vars.tmp))
			return (ft_clean_nest(&(*nest)));
	}
	return (ft_return_1(&g_vars.tmp));
}
