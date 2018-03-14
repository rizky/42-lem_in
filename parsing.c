/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:58:33 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/14 07:37:13 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parsing(char **map, t_lem_in *l)
{
	if (ft_get_data(map, l) == -1)
		return (-1);
	if (ft_check_coordinates(l) == -1)
		return (-1);
	if (!l->start || !l->end || !ft_tablen(l->rooms) || !ft_tablen(l->links))
		return (-1);
	ft_remove_coordinates(l);
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
