/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:36:16 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/12 11:05:28 by fpetras          ###   ########.fr       */
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

int		ft_isnumber(char *coord)
{
	int i;

	i = 0;
	while (coord[i])
	{
		if (coord[i] != '-' && !ft_isdigit(coord[i]))
			return (0);
		i++;
	}
	return (1);
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
