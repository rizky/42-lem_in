/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:14:10 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/17 08:30:57 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_coordinates(t_lem_in *l)
{
	int		i;
	int		j;
	int		ret;
	char	**split;

	i = 0;
	ret = 0;
	while (l->rooms[i])
	{
		j = 1;
		split = ft_strsplit(l->rooms[i], ' ');
		if (ft_tablen(split) != 3)
			ret = -1;
		while (split[j])
		{
			if (!ft_isnumber(split[j]))
				ret = -1;
			j++;
		}
		ft_free_tab(split, 0);
		i++;
		if (ret == -1)
			break ;
	}
	return (ret);
}

int		ft_count_spaces(char *line)
{
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			spaces++;
		i++;
	}
	return (spaces);
}

int		ft_count_links(char **map)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && (ft_count_spaces(map[i]) == 0) &&
			ft_strchr(map[i], '-'))
			links++;
		i++;
	}
	return (links);
}

int		ft_count_rooms(char **map)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && ft_count_spaces(map[i]) == 2)
			rooms++;
		else if (map[i][0] != '#' && (ft_count_spaces(map[i]) == 1 ||
									ft_count_spaces(map[i]) > 2))
			return (-1);
		i++;
	}
	return (rooms);
}

int		ft_check_empty_lines(char *file)
{
	int i;

	i = 0;
	if (!file)
		return (-1);
	while (file[i + 1])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
			return (-1);
		else if (file[i] == '\n' && ft_isspace(file[i + 1])
								&& ft_isspace(file[i + 2]))
			return (-1);
		i++;
	}
	return (0);
}
