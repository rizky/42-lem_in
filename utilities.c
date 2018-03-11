/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:36:16 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/08 14:46:59 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isnumber(char *coord)
{
	int i;

	i = 0;
	while (coord[i])
	{
		if (coord[i] != '-' && !ft_isdigit(coord[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_islink(char *line)
{
	if (line[0] != '#' && ft_count_spaces(line) == 0 && ft_strchr(line, '-'))
		return (1);
	return (0);
}

int		ft_isroom(char *line)
{
	if (line[0] != '#' && ft_count_spaces(line) == 2)
		return (1);
	return (0);
}

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
