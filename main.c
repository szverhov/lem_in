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

int			ft_give_me_count_ants(t_rooms *start)
{
	while (start->next)
		start = start->next;
	return (start->count_ants);
}

void		ft_write(char *str, int i)
{
	char *tmp;

	tmp = ft_itoa(i);
	write(1, "L", 1);
	write(1, tmp, ft_strlen(tmp));
	write(1, "-", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(tmp);
}

int			ft_move_ants(t_rooms *start)
{
	int			c_ants;
	t_rooms		*tmp;
	int			i;

	c_ants = ft_give_me_count_ants(start);
	while (start->next)
		start = start->next;
	i = 1;
	while (c_ants)
	{
		tmp = start->from;
		while (tmp)
		{
			ft_write(tmp->name, i);
			if (tmp->start_r_end == 2)
			{
				c_ants--;
				i++;
			}
			tmp = tmp->from;
		}
	}
	return (1);
}

void		ft_lem_in(void)
{
	t_rooms *start;

	if (!(g_str = (char*)malloc(sizeof(char) * 2)))
		return ;
	g_str[0] = '\0';
	g_iters = 0;
	if (!(ft_make_ant_nest(&start)))
		return ;
	if (!start)
	{
		ft_clean_nest(&start);
		return ;
	}
	if (!ft_check_start_end(start))
	{
		ft_clean_nest(&start);
		return ;
	}
	if (!ft_make_path(start))
		return ;
	if (!ft_move_ants(start))
		return ;
	g_err = 5;
	ft_clean_nest(&start);
}

int			main(void)
{
	ft_lem_in();
	return (0);
}
