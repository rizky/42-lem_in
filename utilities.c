/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:36:16 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/13 10:45:04 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_coordinates(t_lem_in *l)
{
	int i;
	int j;

	i = 0;
	while (l->rooms[i])
	{
		j = 0;
		while (l->rooms[i][j] != ' ')
			j++;
		l->rooms[i][j] = '\0';
		i++;
	}
	i = 0;
	while (l->start[i] != ' ')
		i++;
	l->start[i] = '\0';
	i = 0;
	while (l->end[i] != ' ')
		i++;
	l->end[i] = '\0';
}

int		ft_islink(char *line)
{
	if (line[0] != '#' && ft_count_spaces(line) == 0 && ft_strchr(line, '-'))
		return (1);
	return (0);
}

int		ft_isroom(char *line)
{
	if (line[0] != '#' && ft_count_spaces(line) == 2)
		return (1);
	return (0);
}

int		ft_isnumber(char *str)
{
	int i;
	int sign;
	int digit;

	i = 0;
	sign = 0;
	digit = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			sign++;
			if (sign > 1 || digit > 0)
				return (0);
		}
		else if (ft_isdigit(str[i]))
			digit++;
		else
			return (0);
		i++;
	}
	if (digit > 0)
		return (1);
	return (0);
}

int		ft_valid_ants(char *line)
{
	if (line[0] == '-')
		return (0);
	else if (ft_atoll(line) < -2147483648 || ft_atoll(line) > 2147483647)
		return (0);
	else if (!ft_isnumber(line))
		return (0);
	else
		return (ft_atoi(line));
}
