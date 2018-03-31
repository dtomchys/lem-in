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

#ifndef FT_LEM_IN
# define FT_LEM_IN

#include "./libft/libft.h"
#include <stdio.h>
#define NONEND write(2, "There is no data to finish!\n", 28)
#define DUP write(2, "Duplicates were found!\n", 23)
#define NUM "The amount of ants is supposed to be the number!\n"
#define BEL_ZER "The amount of ants is supposed to be positive!\n"
#define OMAX_INT "The amount of ants isn't supposed to be more than INT_MAX!\n"
#define DAT "The data wasn't filled correctly!\n"
#define COM "The comment is to be after the option \"Start\"!\n"
#define CORX "The coordinate \"X\" is higher/lower than MAX_INT/MIN_INT\n"
#define CORY "The coordinate \"Y\" is higher/lower than MAX_INT/MIN_INT\n"
#define LINK write(2, "The links' names aren't correct!\n", 33)

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

typedef struct		s_map
{
	t_rooms			*top;
	int				size;
	int				**link;
	long			ants;
}					t_map;

void				ft_make_rooms(t_map **map, char **line);
void				ft_make_links(t_map **map, char **s);
int					ft_ant_err_manager(char **s, t_map **map);
int 				ft_rooms_err_manager(t_rooms *head, char ***split);
void				ft_free_split(char ***split);


void testing(t_map *map);
#endif
