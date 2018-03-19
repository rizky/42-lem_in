/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 03:09:29 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/18 10:53:01 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_array	**append_solutions(t_array **sols, int nb_sols, t_array sol)
{
	t_array		**temp;

	temp = (t_array**)malloc(sizeof(t_array*) * nb_sols + 1);
	if (nb_sols > 0)
	{
		ft_memcpy(temp, sols, sizeof(t_array*) * nb_sols);
		free(sols);
	}
	sols = temp;
	sols[nb_sols] = (t_array*)malloc(sizeof(t_array));
	ft_memcpy(sols[nb_sols], &sol, sizeof(t_array));
	sols[nb_sols]->data = (int*)malloc(sizeof(int) * sol.size);
	ft_memcpy(sols[nb_sols]->data, sol.data, sizeof(int) * sol.size);
	return (sols);
}

#define LAST(A) sols[A]->size - 1

static void		solutions_to_cmds(t_array **sols, t_array *cmds,
				int nb_ants, int n)
{
	int		col;
	int		row;
	int		offset;
	char	*temp;

	row = 0;
	while (row >= 0)
	{
		col = -1;
		offset = 1;
		while (++col < nb_ants)
		{
			offset = (col % n == 0) ? offset - 1 : offset;
			if ((offset + row) < 0)
				temp = ft_itoa(((int*)sols[col % n]->data)[0]);
			else
				temp = ((offset + row) > (int)LAST(col % n)) ?
					ft_itoa(((int*)sols[col % n]->data)[LAST(col % n)]) :
					ft_itoa(((int*)sols[col % n]->data)[offset + row]);
			fta_append_space(cmds, temp);
			free(temp);
		}
		fta_append(cmds, "\n", 1);
		row = (offset + row == (int)LAST((col - 1) % n)) ? -1 : row + 1;
	}
}

static int		turns_counter(t_array **sols, int nb_ants, int n)
{
	int		col;
	int		row;
	int		offset;
	int		c;

	if (n == 0)
		return (0);
	row = 0;
	c = 0;
	while (row >= 0)
	{
		col = -1;
		offset = 1;
		while (++col < nb_ants)
			offset = (col % n == 0) ? offset - 1 : offset;
		c++;
		row = (offset + row == (int)LAST((col - 1) % n)) ? -1 : row + 1;
	}
	return (c);
}

static int		run_pathfinder(int **routetab, t_array ***sols,
				t_node *rooms, t_lem_in *l)
{
	t_array		sol;
	int			nb_sols;
	int			start;
	int			end;
	int			turns;

	start = get_nodes_index(rooms, l, l->start);
	end = get_nodes_index(rooms, l, l->end);
	nb_sols = 0;
	sol = NEW_ARRAY(int);
	fta_append(&sol, &start, 1);
	turns = 0;
	while (pathfinder(&routetab, l->nb_rooms, &sol, end))
	{
		*sols = append_solutions((*sols), nb_sols++, sol);
		if (turns_counter((*sols), l->nb_ants, nb_sols) > turns &&
			turns != 0 && nb_sols-- > 0)
			break ;
		turns = turns_counter((*sols), l->nb_ants, nb_sols);
		fta_clear(&sol);
		sol = NEW_ARRAY(int);
		fta_append(&sol, &start, 1);
	}
	fta_clear(&sol);
	return (nb_sols);
}

int				ft_pathfinding(char **map, t_lem_in *l)
{
	t_node		*rooms;
	int			**route;
	t_array		**sols;
	t_array		cmds;
	int			nb_sols;

	if (!(rooms = ft_init_nodes(l)))
		return (-1);
	if (!(route = ft_init_route(l)))
		return (ft_free_nodes(rooms, l->nb_rooms, -1));
	if ((nb_sols = run_pathfinder(route, &sols, rooms, l)) == 0)
	{
		ft_free_nodes(rooms, l->nb_rooms, -1);
		return (ft_free_int_tab(route, l->nb_rooms, -1));
	}
	cmds = NEW_ARRAY(char);
	solutions_to_cmds(sols, &cmds, l->nb_ants, nb_sols);
	(g_option_v == 1) ? run_print_map(route, l, rooms, cmds) : 0;
	ft_print_tab(map);
	ft_print_solutions(cmds, rooms, l);
	free_sols_cmds(sols, cmds, nb_sols);
	ft_free_nodes(rooms, l->nb_rooms, 0);
	ft_free_int_tab(route, l->nb_rooms, 0);
	return (0);
}
