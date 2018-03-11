/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:44:18 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/08 14:45:17 by fpetras          ###   ########.fr       */
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
