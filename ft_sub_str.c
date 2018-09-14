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

char	*ft_sub_str(char *str, char end)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != end && str[i] != '\0')
		i++;
	if (str[i] == '\0' && end != '\0')
		return (0);
	if (!(tmp = (char*)malloc(sizeof(char) * i + 3)))
		return (0);
	i = -1;
	while (str[++i] != end)
		tmp[i] = str[i];
	tmp[i] = 0;
	return (tmp);
}

char	*ft_inner_substr(char *str, char end)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != end)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (str[i] != end)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int		ft_count_of_minuses(char *tmp)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (tmp[i])
	{
		if (tmp[i] == '-')
			minus++;
		i++;
	}
	return (minus);
}

int		ft_init_names(char *tmp, char **name1, char **name2)
{
	int i;

	if (!((*name1) = ft_inner_substr(tmp, '-')))
		return (0);
	i = 0;
	while (tmp[i] != '-')
		i++;
	i++;
	if (!((*name2) = ft_inner_substr(tmp + i, '\0')))
		return (0);
	return (1);
}

int		ft_find_links(t_rooms **start, char *name)
{
	while ((*start) && ft_strcmp((*start)->name, name) != 0)
		(*start) = (*start)->next;
	if (!(*start))
		return (0);
	return (1);
}
