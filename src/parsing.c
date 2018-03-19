/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:58:33 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/16 08:31:47 by fpetras          ###   ########.fr       */
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
	return (0);
}
