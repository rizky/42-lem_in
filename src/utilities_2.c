/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:01:00 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/16 08:43:07 by fpetras          ###   ########.fr       */
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

void	ft_add_coordinates(char *room)
{
	int i;

	i = 0;
	while (room[i])
		i++;
	room[i] = ' ';
}

int		ft_1st_coord_index(char *room)
{
	int i;

	i = 0;
	while (room[i] != ' ')
		i++;
	return (i + 1);
}

int		ft_2nd_coord_index(char *room)
{
	int i;

	i = ft_1st_coord_index(room);
	while (room[i] != ' ')
		i++;
	return (i + 1);
}
