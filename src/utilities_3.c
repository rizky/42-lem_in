/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:01:00 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/18 17:44:44 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_prev_node(char **cmd, int i, int j, int start)
{
	char	**icmds;
	int		value;

	if (i == 0)
		return (start);
	else
	{
		icmds = ft_strsplit(cmd[i - 1], ' ');
		if (j >= ft_wordcounter(cmd[i - 1], ' '))
			j = 0;
		value = ft_atoi(icmds[j]);
		ft_strtab_free(icmds);
		return (value);
	}
}

int		get_nodes_index(t_node *rooms, t_lem_in *l, char *name)
{
	int i;

	i = 0;
	while (i < l->nb_rooms)
	{
		if (ft_strequ(rooms[i].name, name))
			break ;
		i++;
	}
	return (rooms[i].index);
}

char	*get_nodes_name(t_node *rooms, t_lem_in *l, int index)
{
	int i;

	i = 0;
	while (i < l->nb_rooms)
	{
		if (rooms[i].index == index)
			break ;
		i++;
	}
	return (rooms[i].name);
}

void	fta_append_space(t_array *self, char *data)
{
	fta_append(self, data, ft_strlen(data));
	fta_append(self, " ", 1);
}
