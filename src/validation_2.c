/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:22:11 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/20 09:17:49 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Overly complicated in order to make sure rooms' names are able to contain '-'
*/

int		ft_check_link_to_same_room(t_lem_in *l)
{
	int i;
	int j;

	i = 0;
	while (l->links[i])
	{
		j = 0;
		while (l->rooms[j])
		{
			if (ft_strnequ(l->rooms[j], l->links[i], ft_strlen(l->rooms[j])) &&
				l->links[i][ft_strlen(l->rooms[j])] == '-')
				if (ft_strequ(l->rooms[j],
					&l->links[i][ft_strlen(l->rooms[j]) + 1]))
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_second_link2(char *second_link, t_lem_in *l)
{
	int i;
	int stop;

	i = 0;
	stop = 0;
	while (l->rooms[i])
	{
		if (ft_strequ(second_link, l->rooms[i]))
			stop++;
		i++;
	}
	if (stop == 0)
		return (-1);
	return (0);
}

int		ft_check_second_link(t_lem_in *l)
{
	int i;
	int j;

	i = 0;
	while (l->links[i])
	{
		j = 0;
		while (l->rooms[j])
		{
			if (ft_strnequ(l->rooms[j], l->links[i], ft_strlen(l->rooms[j])) &&
				l->links[i][ft_strlen(l->rooms[j])] == '-')
				if (ft_check_second_link2(
					&l->links[i][ft_strlen(l->rooms[j]) + 1], l) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_first_link(t_lem_in *l)
{
	int i;
	int j;
	int stop;

	i = 0;
	while (l->links[i])
	{
		j = 0;
		stop = 0;
		while (l->rooms[j])
		{
			if (ft_strnequ(l->rooms[j], l->links[i], ft_strlen(l->rooms[j])))
				stop++;
			j++;
		}
		if (stop == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_identical_rooms(t_lem_in *l)
{
	int i;
	int j;

	i = 0;
	while (l->rooms[i])
	{
		j = 0;
		while (l->rooms[j])
		{
			if (ft_strequ(l->rooms[i], l->rooms[j]) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
