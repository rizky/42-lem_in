/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:01:00 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/16 14:07:34 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_tablen(char **tab)
{
	size_t len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_print_int_tab(int **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
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

void	ft_print_nodes(t_node *rooms, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("--------------------\n");
		ft_printf("index: %d\n", rooms[i].index);
		ft_printf("name:  %s\n", rooms[i].name);
		ft_printf("col:   %d\n", rooms[i].col);
		ft_printf("row:   %d\n", rooms[i].row);
		i++;
	}
}

void	ft_print_map_info(t_lem_in *l)
{
	int i;

	i = -1;
	ft_printf("------MAP INFO------\n");
	ft_printf("nb_ants: %d\n", l->nb_ants);
	ft_printf("start:   %s\n", l->start);
	ft_printf("end:     %s\n", l->end);
	while (l->rooms[++i])
		ft_printf("rooms:   %s\n", l->rooms[i]);
	i = -1;
	while (l->links[++i])
		ft_printf("links:   %s\n", l->links[i]);
	ft_printf("--------------------\n");
}
