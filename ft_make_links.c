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

#include "ft_lem_in.c"

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

	mat = (int**)malloc(sizeof(int*) * (size + 1))
	i = -1;
	while (++i < size)
	{
		mat[i] = (int*)malloc(sizeof(int) * (size + 1))
		ft_bzero(mat[i], size + 1);
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
	char **s;

	s = ft_strsplit(line, '-');
	(*map)->link[ft_gind(s[0], (*map)->top)][ft_gind(s[1]), (*map->top)] = 1;
}

void	ft_make_links(t_map **map, char **s)
{
	(*map)->link = ft_set_matrix(((*map)->size = ft_rm_len((*map)->top)));
	ft_set_link(map, s);
	free(*s);
	while (get_next_line(0, s) > 0)
	{
		if (ft_strstr(*s, "#"))
			printf("%s\n", *s);
		else if(ft_strstr(*s, "-"))
			ft_set_link(map, s);
		else//HERE !!!!
			exit(EXIT_FAILURE);
		free(*s);
	}
}
