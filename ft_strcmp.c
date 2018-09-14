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

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 != 0 || (unsigned char)*s2 != 0)
	{
		if ((unsigned char)*s1 - (unsigned char)*s2 != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int		ft_free_return_zero(char **tmp)
{
	if (*tmp)
		free(*tmp);
	return (0);
}

int		ft_check_pipe(char *tmp)
{
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	if (tmp[0] == '#')
		return (1);
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			spaces++;
		i++;
	}
	i = 0;
	if (spaces == 2)
		while (tmp[i])
		{
			if (tmp[i] == '-')
				return (0);
			i++;
		}
	return (1);
}

int		stop_reading(char *tmp)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (tmp[0] == '#')
		return (1);
	while (tmp[i])
	{
		if (tmp[i] == '-')
			res++;
		i++;
	}
	if (res == 1)
		return (1);
	return (0);
}

void	ft_free_strs(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
}
