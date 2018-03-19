/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 03:09:29 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/18 17:37:10 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	in_solutions(t_array *sol, int node)
{
	int i;

	i = 0;
	while (i < (int)sol->size)
	{
		if (ARRAY_DATA(sol, i) == node)
			return (1);
		i++;
	}
	return (0);
}

static int	get_min_path(int **routetab, int size, int row, int end)
{
	int col;
	int min;
	int node;

	col = 0;
	min = size + 1;
	node = size;
	while (col < size)
	{
		if (routetab[row][col] == 1 &&
			routetab[col][end] < min)
		{
			min = routetab[end][col];
			node = col;
		}
		col++;
	}
	return (node);
}

/*
** Does not tolerate any intersections
*/

int			pathfinder(int ***routetab, int size, t_array *sol, int end)
{
	int node;

	node = get_min_path(*routetab, size, ARRAY_DATA(sol, sol->size - 1), end);
	if (node == end)
	{
		if (sol->size == 1)
			(*routetab)[ARRAY_DATA(sol, sol->size - 1)][end] = size + 1;
		fta_append(sol, &node, 1);
		return (1);
	}
	while (node < size && (*routetab)[end][node] < size + 1 &&
		!in_solutions(sol, node))
	{
		(*routetab)[ARRAY_DATA(sol, sol->size - 1)][end] = size + 1;
		fta_append(sol, &node, 1);
		(*routetab)[end][node] = size + 1;
		if (pathfinder(routetab, size, sol, end))
			return (1);
		fta_popback(sol, 1);
		node = get_min_path(*routetab, size,
			ARRAY_DATA(sol, sol->size - 1), end);
	}
	return (0);
}
