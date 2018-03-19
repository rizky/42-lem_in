/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:34:58 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/17 09:08:34 by fpetras          ###   ########.fr       */
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
	l->start = NULL;
	l->end = NULL;
	if ((l->rooms = (char**)malloc(sizeof(char*) * l->nb_rooms + 1)) == NULL)
		return (-1);
	l->rooms[l->nb_rooms] = 0;
	if ((l->links = (char**)malloc(sizeof(char*) * l->nb_links + 1)) == NULL)
		return (ft_free_tab(l->rooms, -1));
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

	file[0] = ft_strnew(0);
	while ((ret = read(g_fd, &buf, BUFF_SIZE)) > 0)
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

	g_option_v = 0;
	g_fd = 0;
	if (ac > 1)
		if (ft_options(ac, av) == -1)
			return (-1);
	if ((map = ft_read_map()) == NULL)
	{
		ft_dprintf(2, "ERROR\n");
		return (-1);
	}
	if (ft_init_struct(&l, map) == -1)
	{
		ft_dprintf(2, "ERROR\n");
		return (ft_free_tab(map, -1));
	}
	if (ft_parsing(map, &l) == -1 || ft_pathfinding(map, &l) == -1)
		ft_dprintf(2, "ERROR\n");
	ft_free_tab(map, 0);
	ft_free_struct(&l, 0);
	return (0);
}
