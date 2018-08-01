/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:18:08 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/28 17:18:10 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_rm_len(t_rooms *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int		**ft_set_matrix(int size)
{
	int **mat;
	int i;
	int j;

	mat = (int**)malloc(sizeof(int*) * (size + 1));
	i = -1;
	while (++i < size)
	{
		mat[i] = (int*)malloc(sizeof(int) * (size + 1));
		j = -1;
		while (++j < size)
			mat[i][j] = -1;
	}
	mat[size + 1] = NULL;
	return (mat);
}

int		ft_gind(char *s, t_rooms *head)
{
	int i;

	i = 0;
	while (head)
	{
		if (ft_strequ(s, head->name))
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

void	ft_set_link(t_map **map, char **line)
{
	char			**s;
	static int		i[2];

	s = ft_strsplit(*line, '-');
	if (((i[0] = ft_gind(s[0], (*map)->top)) < 0 ||\
		(i[1] = ft_gind(s[1], (*map)->top)) < 0) && LINK)
		return ;
	(*map)->link[i[0]][i[1]] = i[1];
	(*map)->link[i[1]][i[0]] = i[0];
	ft_free_split(&s);
	ft_printf("%s\n", *line);
}

void	ft_make_links(t_map **map, char **s)
{
	(*map)->size = ft_rm_len((*map)->top);
	(*map)->link = ft_set_matrix((*map)->size);
	ft_set_link(map, s);
	free(*s);
	while (get_next_line(0, s) > 0)
	{
		if (ft_strstr(*s, "#"))
			ft_printf("%s\n", *s);
		else if (ft_strstr(*s, "-"))
			ft_set_link(map, s);
		else
			break ;
		free(*s);
	}
}
