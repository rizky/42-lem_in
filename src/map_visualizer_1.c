/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:14:31 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/18 16:37:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	color_map(int ***routetab, int size, int node1, int node2)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if ((i == node1 && j == node2) ||
				(i == node2 && j == node1))
			{
				(*routetab)[i][j] += 1;
				if ((*routetab)[i][j] > 3)
					(*routetab)[i][j] = 2;
			}
		}
	}
}

static void	reset_route(int **routetab, int size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (routetab[i][j] == 1 || routetab[j][i] == 1)
			{
				routetab[i][j] = 1;
				routetab[j][i] = 1;
			}
			else
				routetab[i][j] = 0;
	}
}

void		run_print_map(int **routetab, t_lem_in *l,
			t_node *nodes, t_array a_cmds)
{
	int			i;
	int			j;
	char		**cmds;
	char		**icmds;

	i = 0;
	reset_route(routetab, l->nb_rooms);
	cmds = ft_strsplit(((char*)a_cmds.data), '\n');
	while (cmds[++i])
	{
		icmds = ft_strsplit(cmds[i], ' ');
		j = 0;
		while (j < ft_wordcounter(cmds[i], ' '))
		{
			color_map(&routetab, l->nb_rooms,
			get_prev_node(cmds, i, j, 1), ft_atoi(icmds[j]));
			j++;
		}
		ft_strtab_free(icmds);
		ft_printf("\033[H\033[J");
		print_map(nodes, routetab, l);
		ft_printfln("Turns: %d", i);
		system("sleep 0.4");
	}
	ft_strtab_free(cmds);
}
