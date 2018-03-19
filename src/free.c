/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:44:18 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/17 08:43:32 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_free_tab(char **tab, int status)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (status);
}

int		ft_free_int_tab(int **tab, int size, int status)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (status);
}

int		ft_free_nodes(t_node *rooms, int size, int status)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
	return (status);
}

int		ft_free_struct(t_lem_in *l, int status)
{
	int i;

	i = 0;
	if (l->start)
		free(l->start);
	if (l->end)
		free(l->end);
	while (l->rooms[i])
	{
		free(l->rooms[i]);
		i++;
	}
	if (l->rooms)
		free(l->rooms);
	i = 0;
	while (l->links[i])
	{
		free(l->links[i]);
		i++;
	}
	if (l->links)
		free(l->links);
	return (status);
}

void	free_sols_cmds(t_array **sols, t_array cmds, int nb_sols)
{
	int i;

	i = 0;
	while (i < nb_sols)
	{
		fta_clear(sols[i]);
		free(sols[i]);
		i++;
	}
	fta_clear(&cmds);
	free(sols);
}
