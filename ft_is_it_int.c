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

static int		ft_str_len_in(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		res++;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	while (str[i])
	{
		i++;
		res++;
	}
	return (res);
}

static int		ft_strcmp_in(char *s1, const char *s2)
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

int				ft_is_it_int(char *str)
{
	int i;

	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' && ft_str_len_in(str) == 11)
		if (ft_strcmp_in(str, "-2147483648") > 0)
			return (0);
	if ((str[0] == '+' && ft_str_len_in(str) == 11) ||
		(ft_str_len_in(str) == 10 && (str[0] != '-' && str[0] != '+')))
		if (ft_strcmp_in(str, "2147483647") > 0)
			return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
