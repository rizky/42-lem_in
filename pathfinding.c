/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:35:09 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/16 14:04:11 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	ft_printf("------ROOM INFO-----\n");
	ft_print_nodes(rooms, l->nb_rooms);
	ft_printf("--------------------\n");
	ft_printf("DISTANCE BETWEEN ROOMS\n");
	ft_print_int_tab(connections, l->nb_rooms);
	ft_printf("--------------------\n");
	ft_free_int_tab(connections, l->nb_rooms);
	ft_free_nodes(rooms, l->nb_rooms);
	return (0);
}
