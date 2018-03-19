/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:21:42 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/18 08:06:42 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_get_room_or_link(char *elem, t_lem_in *l, int i)
{
	if (i == ROOM)
	{
		l->rooms[l->j] = ft_strdup(elem);
		l->j++;
		if (l->k)
			return (-1);
	}
	else if (i == LINK)
	{
		l->links[l->k] = ft_strdup(elem);
		l->k++;
	}
	return (0);
}

static int	ft_get_start_or_end(char **map, t_lem_in *l, int i)
{
	if (i == START)
	{
		while (map[l->i][0] == '#' && map[l->i + 1])
			l->i++;
		if (l->start)
			return (-1);
		if (ft_isroom(map[l->i]))
			l->start = ft_strdup(map[l->i]);
	}
	else if (i == END)
	{
		while (map[l->i][0] == '#' && map[l->i + 1])
			l->i++;
		if (l->end)
			return (-1);
		if (ft_isroom(map[l->i]))
			l->end = ft_strdup(map[l->i]);
	}
	return (0);
}

static int	ft_get_ant_nb(char **map, t_lem_in *l)
{
	int i;
	int nb_ants;

	i = 0;
	while (map[i])
	{
		if (ft_strequ(map[i], "##start") || ft_strequ(map[i], "##end"))
			return (-1);
		else if (map[i][0] == '#')
			;
		else
		{
			if (!(nb_ants = ft_valid_ants(map[i])))
				return (-1);
			break ;
		}
		i++;
	}
	if (map[i])
	{
		l->i = i + 1;
		return (nb_ants);
	}
	else
		return (-1);
}

int			ft_get_data(char **map, t_lem_in *l)
{
	int ret;

	ret = 0;
	if ((l->nb_ants = ft_get_ant_nb(map, l)) == -1)
		ret = -1;
	while (map[l->i])
	{
		if (ft_strequ(map[l->i], "##start"))
			if (ft_get_start_or_end(map, l, START) == -1)
				ret = -1;
		if (ft_strequ(map[l->i], "##end"))
			if (ft_get_start_or_end(map, l, END) == -1)
				ret = -1;
		if (map[l->i][0] != '#' && ft_count_spaces(map[l->i]) == 2)
			if (ft_get_room_or_link(map[l->i], l, ROOM) == -1)
				ret = -1;
		if (map[l->i][0] != '#' && ft_count_spaces(map[l->i]) == 0 &&
			ft_strchr(map[l->i], '-'))
			ft_get_room_or_link(map[l->i], l, LINK);
		if ((map[l->i][0] != '#' && ft_count_spaces(map[l->i]) != 2 &&
			!ft_strchr(map[l->i], '-')) || map[l->i][0] == 'L')
			ret = -1;
		l->i++;
	}
	return (ret);
}
