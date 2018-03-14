/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:44:18 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/14 07:31:07 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_struct(t_lem_in *l)
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
}

void	ft_free_nodes(t_node *rooms, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
}

void	ft_free_int_tab(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
