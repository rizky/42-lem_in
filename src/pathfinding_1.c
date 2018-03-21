/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 03:09:29 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/21 12:59:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_array	**append_solutions(t_array **sols, int nb_sols, t_array sol)
{
	t_array		**temp;

	if ((temp = (t_array**)malloc(sizeof(t_array*) * nb_sols + 1)) == NULL)
		return (sols);
	if (nb_sols > 0)
	{
		ft_memcpy(temp, sols, sizeof(t_array*) * nb_sols);
		free(sols);
	}
	sols = temp;
	if ((sols[nb_sols] = (t_array*)malloc(sizeof(t_array))) == NULL)
		return (sols);
	ft_memcpy(sols[nb_sols], &sol, sizeof(t_array));
	if ((sols[nb_sols]->data = (int*)malloc(sizeof(int) * sol.size)) == NULL)
		return (sols);
	ft_memcpy(sols[nb_sols]->data, sol.data, sizeof(int) * sol.size);
	return (sols);
}

#define LAST(A) sols[A]->size - 1

static int		turns_counter(t_array **sols, int nb_ants, int n)
{
	int		col;
	int		row;
	int		c;
	int		off;
	int		end;

	if (n == 0)
		return (0);
	row = 0;
	c = -1;
	while (row != -1)
	{
		col = -1;
		off = 1;
		end = 1;
		while (++col < nb_ants)
		{
			off = (col % n == 0) ? off - 1 : off;
			if ((off + row) >= 0 && ((off + row) <= (int)LAST(col % n)) && end)
				end = 0;
		}
		row = end ? -1 : row + 1;
		c++;
	}
	return (c);
}

static void		solutions_to_cmds(t_array **sols, t_array *cmds,
				int nb_ants, int n)
{
	int		col;
	int		row;
	int		offset;
	char	*temp;

	row = -1;
	while (++row < turns_counter(sols, nb_ants, n))
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
	}
	fta_append(cmds, "\0", 1);
}

static int		run_pathfinder(int **route, t_array ***sols,
				t_node *r, t_lem_in *l)
{
	t_array		sol;
	int			nb_sols;
	int			turns;
	int			start;

	sol = NEW_ARRAY(int);
	nb_sols = 0;
	turns = 0;
	start = get_nodes_index(r, l, l->start);
	fta_append(&sol, &start, 1);
	while (pathfinder(&route, l->nb_rooms, &sol, get_nodes_index(r, l, l->end)))
	{
		*sols = append_solutions((*sols), nb_sols++, sol);
		if (turns_counter((*sols), l->nb_ants, nb_sols) > turns && turns != 0)
		{
			fta_clear((*sols)[--nb_sols]);
			free((*sols)[nb_sols]);
		}
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
	int			nb_sols;
	t_array		cmds;
	t_array		**sols;

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
