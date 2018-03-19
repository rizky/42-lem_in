/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:32:55 by fpetras           #+#    #+#             */
/*   Updated: 2018/03/18 10:50:46 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define START	1
# define END	2
# define ROOM	1
# define LINK	2
# define W		100
# define H		25
# define ARRAY_DATA(D, I) ((int*)(D)->data)[I]

int					g_option_v;
int					g_fd;

typedef struct		s_lem_in
{
	int				i;
	int				j;
	int				k;
	int				nb_ants;
	int				nb_rooms;
	int				nb_links;
	char			*start;
	char			*end;
	char			**rooms;
	char			**links;
}					t_lem_in;

typedef struct		s_node
{
	int				index;
	char			*name;
	int				col;
	int				row;
}					t_node;

int					ft_options(int ac, char **av);
int					ft_parsing(char **map, t_lem_in *l);
int					ft_get_data(char **map, t_lem_in *l);

int					ft_check_empty_lines(char *file);
int					ft_count_rooms(char **map);
int					ft_count_links(char **map);
int					ft_count_spaces(char *line);
int					ft_check_coordinates(t_lem_in *l);
int					ft_check_identical_rooms(t_lem_in *l);
int					ft_check_first_link(t_lem_in *l);
int					ft_check_second_link(t_lem_in *l);
int					ft_check_second_link2(char *second_link, t_lem_in *l);
int					ft_check_link_to_same_room(t_lem_in *l);

int					ft_valid_ants(char *line);
int					ft_isroom(char *line);
int					ft_islink(char *line);
int					ft_isnumber(char *coord);

int					ft_pathfinding(char **map, t_lem_in *l);

t_node				*ft_init_nodes(t_lem_in *l);
int					**ft_init_route(t_lem_in *l);

void				ft_remove_coordinates(t_lem_in *l);
void				ft_add_coordinates(char *room);
int					ft_1st_coord_index(char *room);
int					ft_2nd_coord_index(char *room);

int					pathfinder(int ***routetab, int size,
					t_array *sol, int end);

void				run_print_map(int **routetab, t_lem_in *l,
					t_node *nodes, t_array a_cmds);
void				print_map(t_node *nodes, int **routetab, t_lem_in *l);

int					get_prev_node(char **cmd, int i, int j, int start);
int					get_nodes_index(t_node *rooms, t_lem_in *l, char *name);
char				*get_nodes_name(t_node *rooms, t_lem_in *l, int index);
void				fta_append_space(t_array *self, char *data);

size_t				ft_tablen(char **tab);
void				ft_print_tab(char **tab);
void				ft_print_solutions(t_array com, t_node *rooms, t_lem_in *l);
int					ft_free_tab(char **tab, int status);
int					ft_free_int_tab(int **tab, int size, int status);
int					ft_free_nodes(t_node *rooms, int size, int status);
int					ft_free_struct(t_lem_in *l, int status);
void				free_sols_cmds(t_array **sols, t_array cmds, int nb_sols);

#endif
