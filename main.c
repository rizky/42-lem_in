/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:34:58 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/14 08:40:12 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_init_struct(t_lem_in *l, char **map)
{
	l->i = 0;
	l->j = 0;
	l->k = 0;
	l->nb_ants = 0;
	if ((l->nb_rooms = ft_count_rooms(map)) == -1)
		return (-1);
	l->nb_links = ft_count_links(map);
	if ((l->rooms = (char**)malloc(sizeof(char*) * l->nb_rooms + 1)) == NULL)
		return (-1);
	l->rooms[l->nb_rooms] = 0;
	if ((l->links = (char**)malloc(sizeof(char*) * l->nb_links + 1)) == NULL)
	{
		ft_free_tab(l->rooms);
		return (-1);
	}
	l->links[l->nb_links] = 0;
	return (0);
}

static char	**ft_save_map(char *file)
{
	char **map;

	if (file && ft_check_empty_lines(file) == -1)
	{
		free(file);
		return (NULL);
	}
	else if (file)
	{
		map = ft_strsplit(file, '\n');
		free(file);
		return (map);
	}
	return (NULL);
}

static char	**ft_read_map(void)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*file[2];
	char	**map;

	file[0] = ft_strnew(0);
	while ((ret = read(0, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		file[1] = file[0];
		file[0] = ft_strjoin(file[1], buf);
		free(file[1]);
		if (file[0][0] != '#' && file[0][0] != '+' && !ft_isdigit(file[0][0]))
		{
			free(file[0]);
			return (NULL);
		}
	}
	return (ft_save_map(file[0]));
}

int			main(int ac, char **av)
{
	char		**map;
	t_lem_in	l;

	if (ac > 1)
	{
		ft_dprintf(2, "usage: %s < map\n", av[0]);
		return (-1);
	}
	if ((map = ft_read_map()) == NULL)
	{
		ft_dprintf(2, "ERROR\n");
		return (-1);
	}
	if (ft_init_struct(&l, map) == -1)
	{
		ft_dprintf(2, "ERROR\n");
		ft_free_tab(map);
		return (-1);
	}
	if (ft_parsing(map, &l) == -1 || ft_pathfinding(&l) == -1)
		ft_dprintf(2, "ERROR\n");
//	else
//		ft_print_tab(map);
	ft_free_tab(map);
	ft_free_struct(&l);
	return (0);
}
