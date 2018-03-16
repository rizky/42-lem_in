/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:35:09 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/16 11:56:12 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_print_nodes(t_node *rooms, t_lem_in *l)
{
	int i;

	i = 0;
	while (i < l->nb_rooms)
	{
		ft_printf("--------------------\n");
		ft_printf("index: %d\n", rooms[i].index);
		ft_printf("name:  %s\n", rooms[i].name);
		ft_printf("col:   %d\n", rooms[i].col);
		ft_printf("row:   %d\n", rooms[i].row);
		i++;
	}
}

static void		ft_print_table(int **tab, t_lem_in *l)
{
	int i;
	int j;

	i = 0;
	while (i < l->nb_rooms)
	{
		j = 0;
		while (j < l->nb_rooms)
		{
			ft_printf("%d", tab[i][j]);
			if (tab[i][j] < 10)
				ft_printf("  ");
			else
				ft_printf(" ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int				ft_pathfinding(t_lem_in *l)
{
	t_node	*rooms;
	int		**connections;

	if (!(rooms = ft_init_nodes(l)))
		return (-1);
	if (!(connections = ft_init_route(l)))
	{
		ft_free_nodes(rooms, l->nb_rooms);
		return (-1);
	}
	ft_print_table(connections, l);
	ft_print_nodes(rooms, l);
	ft_free_int_tab(connections, l->nb_rooms);
	ft_free_nodes(rooms, l->nb_rooms);
	return (0);
}
