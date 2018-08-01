/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:43:59 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/27 12:44:01 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "./libft/libft.h"
# include <stdio.h>
# define NONEND write(2, "ERROR: There is no data to finish!\n", 35)
# define DUP write(2, "ERROR: Duplicates were found!\n", 30)
# define NUM "ERROR: The amount of ants is supposed to be the number!\n"
# define BEL_ZER "ERROR: The amount of ants is supposed to be positive!\n"
# define OMAX_INT "ERROR: The amount of ants is more than INT_MAX!\n"
# define DAT "ERROR: The data wasn't filled correctly!\n"
# define COM "ERROR: The comment is to be after the option \"Start\"!\n"
# define CORX "ERROR: The coordinate \"X\" is higher than MAX_INT/MIN_INT\n"
# define CORY "ERROR: The coordinate \"Y\" is higher than MAX_INT/MIN_INT\n"
# define LINK write(2, "WARNING: The links' names aren't correct!\n", 42)
# define NOT_CON write(2, "ERROR: The start and end aren't connected!\n", 43)
# define NO_STEN write(2, "ERROR: The start/end aren't set or overset!\n", 44)
# define EMPTY write(2, "ERROR: Empty file!\n", 19)
# define UNCOR_COOR write(2, "ERROR: Uncorrect coordinates!\n", 30)

int					g_i;

typedef enum		e_stat
{
	STA = 0, WAY, END
}					t_stat;

typedef struct		s_rooms
{
	int				x;
	int				y;
	char			*name;
	t_stat			st;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_way
{
	long			ant;
	char			*name;
	struct s_way	*next;
}					t_way;

typedef struct		s_map
{
	t_rooms			*top;
	int				size;
	int				**link;
	t_way			*way;
	long			ants;
	int				start;
	int				end;
}					t_map;

typedef struct		s_queue
{
	int				i[2048];
	int				size;
}					t_queue;

typedef struct		s_vert
{
	int				v;
	int				p;
}					t_vert;

void				ft_make_rooms(t_map **map, char **line);
void				ft_make_links(t_map **map, char **s);
int					ft_ant_err_manager(char **s, t_map **map);
int					ft_rooms_err_manager(t_rooms *head, char ***split);
void				ft_free_split(char ***split);
int					ft_find_ways(t_map **map);
void				ft_resend(int i, t_map **map, char **s);

void				push_queue(t_queue *q, int val);
void				pop_queue(t_queue *q);
int					front_queue(t_queue *q);
int					empty_queue(t_queue *q);

t_way				*ft_set_way(t_vert *v, t_map *map);

int					ft_lenway(t_way *way);
void				ft_show_run(int *tab, t_way *way, int size);
void				ft_shift(int *tab, int size);
int					ft_num_dif(int *tab, int size, int num);

#endif
