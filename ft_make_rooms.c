/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:10:17 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/27 15:10:19 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_co(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && UNCOR_COOR)
			exit(EXIT_FAILURE);
	return (ft_atoi(s));
}

t_rooms	*ft_make_one_room(int x, int y, char *name, int op)
{
	t_rooms *temp;

	temp = (t_rooms*)malloc(sizeof(t_rooms));
	temp->x = x;
	temp->y = y;
	temp->name = ft_strdup(name);
	if (op == 1)
		temp->st = STA;
	else if (op == 2)
		temp->st = END;
	else
		temp->st = WAY;
	temp->next = NULL;
	return (temp);
}

void	ft_set_room(t_map **map, int op, char **line)
{
	char	**s;
	t_rooms *temp;
	int		i;

	temp = (*map)->top;
	while (temp && temp->next)
		temp = temp->next;
	if (op == 1 || op == 2)
	{
		ft_printf("%s\n", *line);
		free(*line);
		get_next_line(0, line);
	}
	ft_printf("%s\n", *line);
	s = ft_strsplit(*line, ' ');
	i = 0;
	while (s[i])
		i++;
	ft_resend(i, map, s);
	if (temp == NULL)
		(*map)->top = ft_make_one_room(ft_co(s[1]), ft_co(s[2]), s[0], op);
	else
		temp->next = ft_make_one_room(ft_co(s[1]), ft_co(s[2]), s[0], op);
	ft_free_split(&s);
}

void	ft_chooser(t_map **map, char **line, int *err)
{
	if (ft_strcmp(*line, "##start") == 0 && ++g_i && ++(*err))
		ft_set_room(map, 1, line);
	else if (ft_strcmp(*line, "##end") == 0 && ++(*err))
		ft_set_room(map, 2, line);
	else if (ft_strstr(*line, "#") && !(ft_strstr(*line, "##")))
	{
		ft_printf("%s\n", *line);
		if (g_i == 0 && write(2, COM, 54))
			exit(EXIT_FAILURE);
	}
	else if (ft_strstr(*line, "##") > 0)
		ft_printf("%s", "");
	else if ((ft_isdigit(**line) || ft_isascii(**line)) &&\
		(**line != 'L' && **line != '#'))
		ft_set_room(map, 0, line);
	else
		exit(EXIT_FAILURE);
	free(*line);
}

void	ft_make_rooms(t_map **map, char **line)
{
	static int err;

	g_i = 0;
	ft_chooser(map, line, &err);
	while (get_next_line(0, line) > 0)
	{
		if (ft_strstr(*line, "-") > 0)
		{
			if (err != 2 && NO_STEN)
				exit(EXIT_FAILURE);
			return ;
		}
		else
			ft_chooser(map, line, &err);
	}
}
