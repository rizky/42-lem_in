/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:34:58 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/11 16:36:52 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_extract_room_names(t_lem_in *l)
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

int		ft_parsing(char **map, t_lem_in *l)
{
	if (ft_get_data(map, l) == -1)
		return (-1);
	if (ft_check_coordinates(l) == -1)
		return (-1);
	if (!l->start || !l->end || !ft_tablen(l->rooms) || !ft_tablen(l->links))
		return (-1);
	ft_extract_room_names(l);
	if (ft_check_identical_rooms(l) == -1)
		return (-1);
	if (ft_check_first_link(l) == -1)
		return (-1);
	if (ft_check_second_link(l) == -1)
		return (-1);
	if (ft_check_link_to_same_room(l) == -1)
		return (-1);
	ft_printf("nb_ants: %d\n", l->nb_ants);
	ft_printf("start:   %s\n", l->start);
	ft_printf("end:     %s\n", l->end);
	int i = -1;
	while (l->rooms[++i])
		ft_printf("rooms:   %s\n", l->rooms[i]);
	i = -1;
	while (l->links[++i])
		ft_printf("links:   %s\n", l->links[i]);
	return (0);
}

int		ft_init_struct(t_lem_in *l, char **map)
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

char	**ft_save_map(void)
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
	}
	if (file[0] && ft_check_empty_lines(file[0]) == -1)
	{
		free(file[0]);
		return (NULL);
	}
	else if (file[0])
	{
		map = ft_strsplit(file[0], '\n');
		free(file[0]);
		return (map);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	char		**map;
	t_lem_in	l;

	if (ac > 1)
	{
		ft_dprintf(2, "usage: %s < map\n", av[0]);
		return (-1);
	}
	if ((map = ft_save_map()) == NULL)
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
	if (ft_parsing(map, &l) == -1)
		ft_dprintf(2, "ERROR\n");
//	else
//		ft_print_tab(map);
	ft_free_tab(map);
	ft_free_struct(&l);
	return (0);
}
