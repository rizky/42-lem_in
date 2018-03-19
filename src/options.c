/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:27:11 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/17 08:23:10 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_open(int ac, char **av)
{
	if ((g_fd = open(av[ac - 1], O_RDONLY)) == -1)
	{
		ft_dprintf(2, "ERROR\n");
		return (-1);
	}
	return (0);
}

int			ft_options(int ac, char **av)
{
	if (ac == 2 && ft_strequ(av[1], "-v"))
		g_option_v = 1;
	else if (ac == 3 && ft_strequ(av[1], "-f") && !ft_strequ(av[2], "-v"))
		return (ft_open(ac, av));
	else if (ac == 3 && (ft_strequ(av[1], "-vf") || ft_strequ(av[1], "-fv")))
	{
		g_option_v = 1;
		return (ft_open(ac, av));
	}
	else if (ac == 4 && (((ft_strequ(av[1], "-v") && ft_strequ(av[2], "-f"))) ||
		(ft_strequ(av[1], "-f") && ft_strequ(av[2], "-v"))))
	{
		g_option_v = 1;
		return (ft_open(ac, av));
	}
	else
	{
		ft_dprintf(2, "usage: %s [-v] < map\n", av[0]);
		ft_dprintf(2, "       %s [-v] -f map\n", av[0]);
		return (-1);
	}
	return (0);
}
